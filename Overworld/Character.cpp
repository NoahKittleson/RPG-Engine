//
//  Character.cpp
//  BattleMode
//
//  Created by Noah Kittleson on 1/2/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "Character.h"

#define FONT_SIZE_STAT_DISPLAY 20
#define BAR_WIDTH 100
#define BAR_HEIGHT 40
#define STAT_SPACING_Y 50



Character::Character(const Character& other)					//is this necessary? Doesn't _spr already point to original?
:_IdleTexture(other._IdleTexture), _maxMana(other._maxMana), _maxHealth(other._maxHealth), _NPC(other._NPC),
_currentHealth(other._currentHealth), _currentMana(other._currentMana), _sprite(other._sprite), _name(other._name),
_HPText(other._HPText), _MPText(other._MPText), _AttackName(other._AttackName), _recoveryAbility(other._recoveryAbility),
_basicAttack(other._basicAttack), _abilityList(other._abilityList), _getHitTexture(other._getHitTexture),
_HPBar(other._HPBar), _MPBar(other._MPBar), _BarOutline(other._BarOutline)
{
    std::cout << "alert: character copied. Name: " << other._name.getString().toAnsiString() << "\n";
    //setFont(*other._name.getFont());
    _sprite.setTexture(*_IdleTexture);
}

Character::Character(int MaxHealth, int MaxMana, int BAdmg, const sf::Texture &texture, const sf::Font& font,
                     std::string name, std::string attackName, bool NPC, const sf::Texture& getHit)
: _maxMana(MaxMana), _maxHealth(MaxHealth), _IdleTexture(&texture), _NPC(NPC),
_sprite(AnimatedSprite(sf::Vector2i(texture.getSize().y,texture.getSize().y), 0.2, texture)), _getHitTexture(&getHit),
_currentHealth(MaxHealth), _currentMana(MaxMana)
{
    //This needs to be cleaned up//
    setFont(font);
    //setStatBarPositioning//
    _HPBar.setFillColor(sf::Color::Red);
    _HPBar.setSize(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));
    _MPBar.setFillColor(sf::Color::Blue);
    _MPBar.setSize(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));
    
    _BarOutline.setSize(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));
    _BarOutline.setOutlineColor(sf::Color::Black);
    _BarOutline.setFillColor(sf::Color(0,0,0,0));
    _BarOutline.setOutlineThickness(3);
    
    _sprite.setTexture(*_IdleTexture);
    if (_NPC) { _sprite.setScale(-1.0f, 1.0f); }
    
    _name.setString(name);
    _name.setColor(sf::Color::Black);
    _name.setCharacterSize(FONT_SIZE_STAT_DISPLAY+20);				//name should be slightly bigger font, hence +20.
    _name.setPosition(0, 0);
    
    _HPText.setString("EMPTY");
    _MPText.setString("EMPTY");
    
    _HPText.setPosition(100, 0);
    _MPText.setPosition(200, 0);
    
    _HPText.setColor(sf::Color::Red);
    _MPText.setColor(sf::Color::Blue);
    
    _HPText.setCharacterSize(FONT_SIZE_STAT_DISPLAY);
    _MPText.setCharacterSize(FONT_SIZE_STAT_DISPLAY);
    
    _AttackName = attackName;
    _recoveryAbility = Ability("Recover", "Restores all Mana", 0, 0, 0, *_IdleTexture);				//placeholder texture
    _basicAttack = Ability("ATTACK", "Does Basic Damage", BAdmg, 0, 0, *_IdleTexture);				//placeholder texture
    if (_NPC) {
        _basicAttack._allyPrimaryTarget = true;
    }
    else _basicAttack._allyPrimaryTarget = false;
    
    _recoveryAbility.setProperties(Ability::PercentManaRecovery, 1.0);
    if (_NPC) {
        _recoveryAbility._baseDamage = 200;
    }
    UpdateStatDisplay();
}

void Character::addAbility(Ability& ability)
{
    ability.setFont(*_name.getFont());
    _abilityList.push_back(ability);
}

float Character::takeDamage(Ability ability, Character& attacker)
{
    float TOTALDAMAGE = ability._baseDamage;
    float DamageReduction = 1.0;
    float DamageMultiplier = 1.0;
    
    //FIRST GO THROUGH ALL ATTACKER DAMAGE MODIFIERS
    for (auto&& it : attacker.StatusEffects) {
        switch (it.first) {
            case Ability::FlatDmgBuff:
                if (ability._baseDamage != 0) {
                    TOTALDAMAGE += it.second;
                }
                break;
                
            case Ability::PercentManaRecovery:
                attacker.adjustMana(_maxMana * it.second);
                break;
                
            default:
                break;
        }
    }
    //SECOND GO THROUGH ALL ABILITY DAMAGE MULTIPLIERS
    switch (ability.AbilityDmgMulti.first)				//only allows for one dmg mulitplier
    {
        case Ability::WhilePoisoned:
            if (StatusEffects.find(Ability::Poison) != StatusEffects.end()) {
                DamageMultiplier += ability.AbilityDmgMulti.second;
            }
            break;
            
        case Ability::VSUndead:					//currently doesn't work because there is no "undead"
            if (/* DISABLED CODE */ (false)) {
                DamageMultiplier += ability.AbilityDmgMulti.second;
            }
            break;
            
        case Ability::VSHealthy:
            if (_currentHealth >= _maxHealth/2) {
                DamageMultiplier += ability.AbilityDmgMulti.second;
            }
            break;
            
        case Ability::VSUnhealthy:
            if (_currentHealth < _maxHealth/2) {
                DamageMultiplier += ability.AbilityDmgMulti.second;
            }
            break;
            
        case Ability::VSFullHealth:
            if (_currentHealth == _maxHealth) {
                DamageMultiplier += ability.AbilityDmgMulti.second;
            }
            break;
            
        default:
            break;
    }
    
    //THIRD APPLY ALL DEFENDER DAMAGE MODIFIERS
    auto find = StatusEffects.find(Ability::DeathMark);
    if (find != StatusEffects.end()) {
        DamageMultiplier += (find->second);
    }
    
    find = StatusEffects.find(Ability::SelfShieldPercent);
    if (find != StatusEffects.end()) {
        if (find->second >= 0 && find->second <= 1.0)
        { DamageReduction *= (1.0f - find->second); }
    }
    
    //FOURTH CALCULATE DAMAGE AND ALL EFFECTS THAT REQUIRE KNOWING THE DAMAGE DONE
    TOTALDAMAGE = TOTALDAMAGE * DamageMultiplier * DamageReduction;
    
    for (auto&& it : ability.AbilityAfterEffects) {
        switch (it.first)
        {
            case Ability::LifeDrain:
                attacker.adjustHealth(TOTALDAMAGE * it.second);
                break;
                
            case Ability::ManaDrain:
                adjustMana(TOTALDAMAGE * it.second);
                break;
        }
    }
    
    //FIFTH APPLY ANY STATUS EFFECTS
    for (auto&& it : ability.AbilityProperties) {
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
                attacker.addSelfShield(it.second);
                break;
                
            case Ability::FlatDmgBuff:
                addAdditiveProperty(it.second, Ability::FlatDmgBuff);
                break;
                
            case Ability::PoisonHeal:
                if (StatusEffects.find(Ability::Poison) != StatusEffects.end()) {
                    attacker.adjustHealth(it.second);
                }
                break;
                
            case Ability::GiveMana:
                adjustMana(it.second);
                break;
                
            case Ability::AntidotePercent:
                curePoison(it.second);
                break;
                
            case Ability::SelfHeal:
                attacker.adjustHealth(it.second);
                break;
                
            case Ability::SelfStun:
                attacker.addStun(it.second);
                break;
                
            case Ability::Clear:
                StatusEffects.clear();
                break;
                
            default:
                break;
        }
    }
    //SIXTH, APPLY AND RETURN THE DAMAGE DONE
    adjustHealth(-TOTALDAMAGE);
    UpdateStatDisplay();
    attacker.UpdateStatDisplay();
    return TOTALDAMAGE;
}

void Character::addPoison(int PsnAmount)	//will re-apply poison if poison amount is greater than before
{
    for (auto && it : StatusEffects) {
        if (it.first == Ability::Poison) {
            if (it.second < PsnAmount) {
                it.second = PsnAmount;
            }
            return;
        }
    }
    StatusEffects.insert(std::pair<Ability::Properties, int> (Ability::Poison, PsnAmount));
}

void Character::addStun(int turns)	//will apply only if there is no active stun.
{
    for (auto && it : StatusEffects) {
        if (it.first == Ability::Stun) {
            return;
        }
    }
    StatusEffects.insert(std::pair<Ability::Properties, int> (Ability::Stun, turns));
}

void Character::adjustHealth(int amount)
{
    _currentHealth += amount;
    if (_currentHealth > _maxHealth) {
        _currentHealth = _maxHealth;
    }
    if (_currentHealth < 0) {
        _currentHealth = 0;
    }
}

void Character::adjustMana(int amount)
{
    _currentMana += amount;
    if (_currentMana > _maxMana) {
        _currentMana = _maxMana;
    }
    if (_currentMana < 0) {
        _currentMana = 0;
    }
}

void Character::UpdateStatDisplay()
{
    _HPText.setString(GetText("HP: ", _currentHealth, _maxHealth));
    _MPText.setString(GetText("MP: ", _currentMana, _maxMana));
    
    _HPBar.setSize(sf::Vector2f(percentHealth()*BAR_WIDTH, BAR_HEIGHT));
    _MPBar.setSize(sf::Vector2f(percentHealth()*BAR_WIDTH, BAR_HEIGHT));
    updateStatusEffects();
}

std::string Character::GetText(std::string Description, int currentValue, int maxValue)
{
    std::ostringstream ss;
    ss << Description << currentValue << "/" << maxValue;
    return ss.str();
}

void Character::setStatPosition(int x, int y)
{
    _name.setPosition(x, y);
    _HPText.setPosition(x, y + STAT_SPACING_Y);
    _HPBar.setPosition(x, y + 2 * STAT_SPACING_Y);
    _MPText.setPosition(x, y + 3 * STAT_SPACING_Y);
    _MPBar.setPosition(x, y + 4 * STAT_SPACING_Y);
    char space = 5;
    for (auto & it: StatusEffectDisplay) {
        it.setPosition(x, y + space * FONT_SIZE_STAT_DISPLAY);
        space++;
    }
}

void Character::drawAllStats(sf::RenderWindow &rw)
{
    rw.draw(_name);
    rw.draw(_HPText);
    rw.draw(_HPBar);
    rw.draw(_MPText);
    rw.draw(_MPBar);
    
    for (const auto & it: StatusEffectDisplay) {
        rw.draw(it);
    }
    
    _BarOutline.setPosition(_HPBar.getPosition());
    rw.draw(_BarOutline);
    _BarOutline.setPosition(_MPBar.getPosition());
    rw.draw(_BarOutline);
}

void Character::drawSprite(sf::RenderWindow &rw)
{
    _sprite.draw(rw);
}

void Character::updateStatusEffects()
{
    StatusEffectDisplay.clear();
    std::ostringstream ss;
    sf::Text display;
    display.setCharacterSize(FONT_SIZE_STAT_DISPLAY);
    int yPos = _MPBar.getPosition().y + STAT_SPACING_Y;
    display.setFont(*_name.getFont());                          //create a font member?
    
    for (auto && it: StatusEffects) {
        switch (it.first)
        {
            case Ability::Properties::Bleed:
                display.setColor(sf::Color::Red);               //Red
                ss << "Bleed: " << it.second << "\n";
                break;
                
            case Ability::Properties::DeathMark:
                display.setColor(sf::Color::Black);				//Black
                ss << "Marks: " << it.second << "\n";
                break;
                
            case Ability::Properties::FlatDmgBuff:
                display.setColor(sf::Color::Blue);				//Blue
                ss << "Buff: +" << it.second << "\n";
                break;
                
            case Ability::Properties::Poison:
                display.setColor(sf::Color(0,153,0));			//Green
                ss << "Poison: " << it.second << "\n";
                break;
                
            case Ability::Properties::SelfShieldPercent:
                display.setColor(sf::Color(100,100,100));		//Gray
                ss << "Sheild: " << it.second * 100 << "%\n";
                break;
                
            case Ability::Properties::Stun:
                display.setColor(sf::Color(200,200,0));			//Yellow
                ss << "Stunned\n";
                break;
                
            default:
                break;
                
        }
        if (ss) {
            display.setString(ss.str());
            display.setPosition(_MPBar.getPosition().x, yPos);
            yPos += FONT_SIZE_STAT_DISPLAY;
            StatusEffectDisplay.push_back(display);
            ss.str("");
        }
    }
}


void Character::setFont(const sf::Font &font)
{
    _name.setFont(font);
    _MPText.setFont(font);
    _HPText.setFont(font);
    _basicAttack.setFont(font);
    _recoveryAbility.setFont(font);
}

void Character::setSpritePosition(int x, int y)
{
    _sprite.setPosition(x, y);
}

void Character::PayAbilityCost(Ability& abil)
{
    if (abil.AbilityRequirements.empty()) return;
    for (auto&& it : abil.AbilityRequirements)
    {
        switch (it.first)
        {
            case Ability::ManaCost:
                _currentMana -= it.second;
                break;
                
            case Ability::HealthCost:
                _currentHealth -= it.second;
                break;
                
            default:
                break;
        }
    }
    UpdateStatDisplay();
}

void Character::addMark()
{
    for (auto && it : StatusEffects)
    {
        if (it.first == Ability::DeathMark)
        {
            it.second++;
            return;
        }
    }
    StatusEffects.insert(std::pair<Ability::Properties, float> (Ability::DeathMark, 1));
}

void Character::addAdditiveProperty(float amount, Ability::Properties property)
{
    auto find = StatusEffects.find(property);
    if (find != StatusEffects.end())
    {
        find->second += amount;
    }
    else StatusEffects.insert(std::pair<Ability::Properties, float>(property, amount));
}

void Character::addSelfShield(float percentDamageReduction)
{
    StatusEffects.insert(std::pair<Ability::Properties, float> (Ability::SelfShieldPercent, percentDamageReduction));
}

void Character::curePoison(float percent)
{
    auto find = StatusEffects.find(Ability::Poison);
    if (find != StatusEffects.end())
    {
        (*find).second -= (*find).second*percent;
        if ((*find).second <= 0)
        {
            StatusEffects.erase(find);
        }
        
    }
}

float Character::percentMana()
{
    return _currentMana/_maxMana;
}

float Character::percentHealth()
{
    return _currentHealth/_maxHealth;
}

bool Character::CheckAbilityCost(Ability& abil)
{
    for (const auto & it: abil.AbilityRequirements) {
        switch (it.first) {
            case Ability::HealthCost:
                if (it.second > _currentHealth) {
                    return false;
                }
                break;
                
            case Ability::ManaCost:
                if (it.second > _currentMana) {
                    return false;
                }
                break;
                
            default:
                break;
        }
    }
    return true;
}

void Character::setColor(sf::Color color)
{
    _name.setColor(color);
}

void Character::animate(sf::RenderWindow &rw, float elapsed) {
    _sprite.animate(elapsed, rw);
}



/////////////SET FOR DELETION///////////////

/*void Character::drawName(sf::RenderWindow &rw)
{
    rw.draw(_name);
}

void Character::UseRecovery(Character* Target)
{
    for (auto && it: _recoveryAbility.AbilityProperties)
    {
        switch (it.first)
        {
            case Ability::AntidotePercent:
                curePoison(it.second);
                break;
                
            case Ability::Heal:
                heal(it.second);
                break;
                
            case Ability::PercentManaRecovery:
                _currentMana += (_maxMana * it.second);
                if (_currentMana > _maxMana)
                { _currentMana = _maxMana; }
                break;
                
            default:
                break;
        }
    }
    if (Target && _recoveryAbility._baseDamage) {
        Target->_currentHealth -= _recoveryAbility._baseDamage;
        if (Target->_currentHealth <= 0) {
            Target->_currentHealth = 0;
        }
        UpdateStatDisplay();
        Target->UpdateStatDisplay();
    }
    
}

void Character::setIdle()
{
    _sprite.setTexture(*_IdleTexture);
}

void Character::setIdleNext()
{
    _sprite.setNextAnimation(*_IdleTexture);
}

void Character::setGetHit()
{
    _sprite.setTexture(*_getHitTexture);
}

bool Character::isIdle()
{
    if (_sprite.compare(_IdleTexture)) {
        return true;
    }
    return false;
}
void Character::heal(int amount)
{
    _currentHealth += amount;
    if (_currentHealth > _maxHealth)
    {
        _currentHealth = _maxHealth;
    }
}*/









