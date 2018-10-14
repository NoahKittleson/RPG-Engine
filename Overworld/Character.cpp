//
//  Character.cpp
//  BattleMode
//
//  Created by Noah Kittleson on 1/2/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "Character.h"

#define FONTSIZESTATDISPLAY 20
#define BARWIDTH 150
#define BARHEIGHT 20
#define STATSPACINGY 30


Character::~Character() {
    std::cout << "Character destroyed.  Name: " << this->name.getString().toAnsiString() << "\n";
}

Character::Character(int MaxHealth, int MaxMana, const sf::Font& font, std::string name, bool NPC, const AnimationSheet anims)
: maxMana(MaxMana), maxHealth(MaxHealth), NPC(NPC), animations(anims),
sprite(AnimatedComponent(*anims.getIdle(), sf::Vector2f(0,0), 0.2, sf::Vector2i(anims.getIdle()->getSize().y,anims.getIdle()->getSize().y))), recoveryAbility("Recover", "Restores all Mana", 0, 0, 0, *anims.getIdle()), basicAttack("Attack", "Does Basic Damage", 50, 0, 0, *anims.getIdle()), currentHealth(MaxHealth), currentMana(MaxMana)
{
    //This needs to be cleaned up//
    setFont(font);
    //setStatBarPositioning//
    HPBar.setFillColor(sf::Color::Red);
    HPBar.setSize(sf::Vector2f(BARWIDTH, BARHEIGHT));
    MPBar.setFillColor(sf::Color::Blue);
    MPBar.setSize(sf::Vector2f(BARWIDTH, BARHEIGHT));
    
    barOutline.setSize(sf::Vector2f(BARWIDTH, BARHEIGHT));
    barOutline.setOutlineColor(sf::Color::Black);
    barOutline.setFillColor(sf::Color(0,0,0,0));
    barOutline.setOutlineThickness(3);
    
    sprite.setTexture(*anims.getIdle());
    //if (NPC) { sprite.setScale(-1.0f, 1.0f); }
	sprite.setScale(2.0f, 2.0f);
    
    this->name.setString(name);
    this->name.setColor(sf::Color::Black);
    this->name.setCharacterSize(FONTSIZESTATDISPLAY+20);				//name should be slightly bigger font, hence +20.
    this->name.setPosition(0, 0);
    
    HPText.setString("EMPTY");
    MPText.setString("EMPTY");
    
    HPText.setPosition(100, 0);
    MPText.setPosition(200, 0);
    
    HPText.setColor(sf::Color::Red);
    MPText.setColor(sf::Color::Blue);
    
    HPText.setCharacterSize(FONTSIZESTATDISPLAY);
    MPText.setCharacterSize(FONTSIZESTATDISPLAY);
    
    recoveryAbility.addProperty(Ability::PercentManaRecovery, 1.0, true);
    if (NPC) {
        recoveryAbility.baseDamage = 200;
		AI = std::unique_ptr<BattleAI>(new RandomAI());
    }
    updateStatDisplay();
	
}

void Character::addAbility(Ability& ability) {
    ability.setFont(*name.getFont());
    ability.setPosition(100, 30 * abilityList.size());
    abilityList.push_back(ability);
}

float Character::calculateDmg(const Ability& ability, std::shared_ptr<Character> attacker) {
    float TOTALDAMAGE = ability.baseDamage;
    float DamageReduction = 1.0;
    float DamageMultiplier = 1.0;
    
    //FIRST GO THROUGH ALL ATTACKER DAMAGE MODIFIERS
    for (const auto & it : attacker->statusEffects) {
        switch (it.first) {
            case Ability::FlatDmgBuff:
                if (ability.baseDamage != 0) {
                    TOTALDAMAGE += it.second;
                }
                break;
                
            case Ability::PercentManaRecovery:
                attacker->adjustMana(maxMana * it.second);
                break;
                
            default:
                break;
        }
    }
    //SECOND GO THROUGH ALL ABILITY DAMAGE MULTIPLIERS
    switch (ability.dmgMulti.first)				//only allows for one dmg mulitplier
    {
        case Ability::WhilePoisoned:
            if (statusEffects.find(Ability::Poison) != statusEffects.end()) {
                DamageMultiplier += ability.dmgMulti.second;
            }
            break;
            
        case Ability::VSUndead:					//currently doesn't work because there is no "undead"
            if (/* DISABLED CODE */ (false)) {
                DamageMultiplier += ability.dmgMulti.second;
            }
            break;
            
        case Ability::VSHealthy:
            if (currentHealth >= maxHealth/2) {
                DamageMultiplier += ability.dmgMulti.second;
            }
            break;
            
        case Ability::VSUnhealthy:
            if (currentHealth < maxHealth/2) {
                DamageMultiplier += ability.dmgMulti.second;
            }
            break;
            
        case Ability::VSFullHealth:
            if (currentHealth == maxHealth) {
                DamageMultiplier += ability.dmgMulti.second;
            }
            break;
            
        default:
            break;
    }
    
    //THIRD APPLY ALL DEFENDER DAMAGE MODIFIERS
    auto find = statusEffects.find(Ability::DeathMark);
    if (find != statusEffects.end()) {
        DamageMultiplier += (find->second);
    }
    
    find = statusEffects.find(Ability::SelfShieldPercent);
    if (find != statusEffects.end()) {
        if (find->second >= 0 && find->second <= 1.0)
        { DamageReduction *= (1.0f - find->second); }
    }
    
    //FOURTH CALCULATE DAMAGE AND ALL EFFECTS THAT REQUIRE KNOWING THE DAMAGE DONE
    TOTALDAMAGE = TOTALDAMAGE * DamageMultiplier * DamageReduction;
	
    for (const auto & it : ability.afterEffects) {
        switch (it.first)
        {
            case Ability::LifeDrain:
                attacker->adjustHealth(TOTALDAMAGE * it.second);
                break;
                
            case Ability::ManaDrain:
                adjustMana(TOTALDAMAGE * it.second);
                break;
        }
    }
    
    //FIFTH APPLY ANY STATUS EFFECTS
    for (const auto & it : ability.properties) {
        switch (it.first)
        {
            case Ability::Poison:
                addPoison(it.second);
                break;
                
            case Ability::Bleed:
                addAdditiveProperty(it.second, Ability::Bleed);
                break;
                
            case Ability::Stun:
                addStun(it.second);
                break;
                
            case Ability::Heal:
                adjustHealth(it.second);
                break;
                
            case Ability::DeathMark:
                addMark();
                break;
                
            case Ability::SelfShieldPercent:
                attacker->addSelfShield(it.second);
                break;
                
            case Ability::FlatDmgBuff:
                addAdditiveProperty(it.second, Ability::FlatDmgBuff);
                break;
                
            case Ability::PoisonHeal:
                if (statusEffects.find(Ability::Poison) != statusEffects.end()) {
                    attacker->adjustHealth(it.second);
                }
                break;
                
            case Ability::GiveMana:
                adjustMana(it.second);
                break;
                
            case Ability::AntidotePercent:
                curePoison(it.second);
                break;
                
            case Ability::SelfHeal:
                attacker->adjustHealth(it.second);
                break;
                
            case Ability::SelfStun:
                attacker->addStun(it.second);
                break;
                
            case Ability::Clear:
                statusEffects.clear();
                break;
                
            default:
                break;
        }
    }
    //SIXTH, APPLY AND RETURN THE DAMAGE DONE, ALSO ANIMATIONS
    adjustHealth(-TOTALDAMAGE);
    updateStatDisplay();
    attacker->updateStatDisplay();
	attacker->startAttackAnimation(ability);
    return TOTALDAMAGE;
}

void Character::addPoison(int PsnAmount) {	//will re-apply poison if poison amount is greater than before
    for (auto & it : statusEffects) {
        if (it.first == Ability::Poison) {
            if (it.second < PsnAmount) {
                it.second = PsnAmount;
            }
            return;
        }
    }
    statusEffects.insert(std::pair<Ability::Property, int> (Ability::Poison, PsnAmount));
}

void Character::addStun(int turns) {	//will apply only if there is no active stun.
    for (const auto & it : statusEffects) {
        if (it.first == Ability::Stun) {
            return;
        }
    }
    statusEffects.insert(std::pair<Ability::Property, int> (Ability::Stun, turns));
}

void Character::adjustHealth(int amount) {
    currentHealth += amount;
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
    if (currentHealth < 0) {
        currentHealth = 0;
    }
}

float Character::getHealth() const {
    return currentHealth;
}

void Character::adjustMana(int amount)
{
    currentMana += amount;
    if (currentMana > maxMana) {
        currentMana = maxMana;
    }
    if (currentMana < 0) {
        currentMana = 0;
    }
}

float Character::getMana() const {
    return currentMana;
}

void Character::move(sf::Vector2f movement) {
	sprite.move(movement);
}

sf::Vector2f Character::getSpritePosition() const {
	return sprite.getPosition();
};


void Character::updateStatDisplay() {
    HPText.setString(getText("HP: ", currentHealth, maxHealth));
    MPText.setString(getText("MP: ", currentMana, maxMana));
    
    HPBar.setSize(sf::Vector2f(percentHealth()*BARWIDTH, BARHEIGHT));
    MPBar.setSize(sf::Vector2f(percentMana()*BARWIDTH, BARHEIGHT));
    updateStatusEffects();
}

std::string Character::getText(std::string Description, int currentValue, int maxValue) {
    std::ostringstream ss;
    ss << Description << currentValue << "/" << maxValue;
    return ss.str();
}

void Character::setStatPosition(int x, int y) {
    name.setPosition(x, y);
    HPText.setPosition(x, y + 2 * STATSPACINGY);
    HPBar.setPosition(x, y + 3 * STATSPACINGY);
    MPText.setPosition(x, y + 4 * STATSPACINGY);
    MPBar.setPosition(x, y + 5 * STATSPACINGY);
    char space = 6;
    for (auto & it: statusEffectDisplay) {
        it.setPosition(x, y + space * FONTSIZESTATDISPLAY);
        space++;
    }
}

void Character::drawAllStats(sf::RenderWindow &rw) {
    rw.draw(name);
    rw.draw(HPText);
    rw.draw(HPBar);
    rw.draw(MPText);
    rw.draw(MPBar);
    
    for (const auto & it: statusEffectDisplay) {
        rw.draw(it);
    }
    
    barOutline.setPosition(HPBar.getPosition());
    rw.draw(barOutline);
    barOutline.setPosition(MPBar.getPosition());
    rw.draw(barOutline);
}

void Character::drawSprite(sf::RenderWindow &rw) {
	//this line is breaking things during the second loop and battleAnimation... Probably has no attack animation.
	rw.draw(sprite);
}

void Character::updateStatusEffects() {
    statusEffectDisplay.clear();
    std::ostringstream ss;
    sf::Text display;
    display.setCharacterSize(FONTSIZESTATDISPLAY);
    int yPos = MPBar.getPosition().y + STATSPACINGY;
    display.setFont(*name.getFont());                          //create a font member?
    
    for (const auto & it: statusEffects) {
        switch (it.first)
        {
            case Ability::Property::Bleed:
                display.setColor(sf::Color::Red);               //Red
                ss << "Bleed: " << it.second << "\n";
                break;
                
            case Ability::Property::DeathMark:
                display.setColor(sf::Color::Black);				//Black
                ss << "Marks: " << it.second << "\n";
                break;
                
            case Ability::Property::FlatDmgBuff:
                display.setColor(sf::Color::Blue);				//Blue
                ss << "Buff: +" << it.second << "\n";
                break;
                
            case Ability::Property::Poison:
                display.setColor(sf::Color(0,153,0));			//Green
                ss << "Poison: " << it.second << "\n";
                break;
                
            case Ability::Property::SelfShieldPercent:
                display.setColor(sf::Color(100,100,100));		//Gray
                ss << "Sheild: " << it.second * 100 << "%\n";
                break;
                
            case Ability::Property::Stun:
                display.setColor(sf::Color(200,200,0));			//Yellow
                ss << "Stunned\n";
                break;
                
            default:
                break;
                
        }
        if (ss) {
            display.setString(ss.str());
            display.setPosition(MPBar.getPosition().x, yPos);
            yPos += FONTSIZESTATDISPLAY;
            statusEffectDisplay.push_back(display);
            ss.str("");
        }
    }
}


void Character::setFont(const sf::Font &font) {
    name.setFont(font);
    MPText.setFont(font);
    HPText.setFont(font);
    basicAttack.setFont(font);
    recoveryAbility.setFont(font);
}

void Character::setSpritePosition(int x, int y) {
    sprite.setPosition(x, y);
}

void Character::payAbilityCost(const Ability& abil) {
    if (abil.requirements.empty()) return;
    for (const auto & it : abil.requirements)
    {
        switch (it.first)
        {
            case Ability::ManaCost:
                currentMana -= it.second;
                break;
                
            case Ability::HealthCost:
                currentHealth -= it.second;
                break;
                
            default:
                break;
        }
    }
    updateStatDisplay();
}

void Character::addMark() {
    for (auto & it : statusEffects)
    {
        if (it.first == Ability::DeathMark)
        {
            it.second++;
            return;
        }
    }
    statusEffects.insert(std::pair<Ability::Property, float> (Ability::DeathMark, 1));
}

void Character::addAdditiveProperty(float amount, Ability::Property property) {
    auto find = statusEffects.find(property);
    if (find != statusEffects.end())
    {
        find->second += amount;
    }
    else statusEffects.insert(std::pair<Ability::Property, float>(property, amount));
}

void Character::addSelfShield(float percentDamageReduction) {
    statusEffects.insert(std::pair<Ability::Property, float> (Ability::SelfShieldPercent, percentDamageReduction));
}

void Character::curePoison(float percent) {
    auto find = statusEffects.find(Ability::Poison);
    if (find != statusEffects.end())
    {
        (*find).second -= (*find).second*percent;
        if ((*find).second <= 0)
        {
            statusEffects.erase(find);
        }
        
    }
}

float Character::percentMana() {
    return currentMana/maxMana;
}

float Character::percentHealth() {
    return currentHealth/maxHealth;
}

bool Character::checkAbilityCost(const Ability& abil) const {
    for (const auto & it: abil.requirements) {
        switch (it.first) {
            case Ability::HealthCost:
                if (it.second > currentHealth) {
                    return false;
                }
                break;
                
            case Ability::ManaCost:
                if (it.second > currentMana) {
                    return false;
                }
                break;
                
            default:
                break;
        }
    }
    return true;
}

void Character::animate(float elapsed) {
	if (sprite.atEnd()) {
		if (currentHealth <= 0) {
			assert(animations.getDead() != nullptr);
			sprite.setTexture(*animations.getDead());
		} else {
			assert(animations.getIdle() != nullptr);
			sprite.setTexture(*animations.getIdle());
		}
	}
    sprite.update(elapsed);
}

std::string Character::getName() const {
	return name.getString();
}

bool Character::isIdle() {
	return sprite.getTexture() == animations.getIdle() || sprite.getTexture() == animations.getDead();
}

void Character::startGetHitAnimation() {
	if (currentHealth <= 0 ) {
		assert(animations.getGetKilled());
		sprite.setTexture(*animations.getGetKilled());
		audio->playSound(SoundID::foxDeath);
	} else {
		assert(animations.getGetHit());
		sprite.setTexture(*animations.getGetHit());
		audio->playSound(SoundID::foxHurt);
	}
}

bool Character::isNPC() const {
	return NPC;
}

bool Character::isIncapped() const {
	return currentHealth <= 0;
}


const IterVector<Ability>& Character::getAbilityList() const {
	return abilityList;
}

const Ability& Character::getBasicAttack() const {
	return basicAttack;
}

const Ability& Character::getRecoveryAbility() const {
	return recoveryAbility;
}

void Character::setBasicAttack(Ability& abil) {
	basicAttack = abil;
}

void Character::setRecoveryAbility(Ability& abil) {
	recoveryAbility = abil;
}

void Character::fillInAction(BattleInfo& info) const {
	AI->FillAction(info);
	if (!info.currentAction.ability) {
		info.currentAction.ability = &basicAttack;
		std::cout << "No Action Chosen.\n";
	}
	if (!info.currentAction.defenders.size()) {
		info.currentAction.defenders.push_back(info.PCs[0]);
		std::cout << "No Defenders Chosen.\n";
	}
	if (!info.currentAction.attacker) {
		info.currentAction.attacker = info.combatants.get();
		std::cout << "No Attacker Chosen. How did this happen?\n";
	}
	info.currentAction.complete();
}

void Character::setIdle() {
	if (currentHealth <= 0) {
		assert(animations.getDead());
		sprite.setTexture(*animations.getDead());
	} else {
		assert(animations.getIdle());
		sprite.setTexture(*animations.getIdle());
	}
}
void Character::startAttackAnimation(const Ability& abil) {
	sprite.setTexture(*abil.getAnimation());
}

void Character::attachAudio(AudioHandler& audioPlayer) {
	audio = &audioPlayer;
}





