//
//  BattleMenu.cpp
//  SFML test
//
//  Created by Noah Kittleson on 1/12/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "BattleMenu.h"


/*#define SCREEN_WIDTH 1024                       //also, this is cheating.
#define SCREEN_HEIGHT 768
#define INITIAL_ENEMY_X 200						//these are not well defined/named...
#define INITIAL_ENEMY_Y 350
#define CHARINFO_SPACING_Y 50
#define DIRECT_COMBAT_Y 200
#define TIME_PER_FRAME 0.2


BattleMenu::BattleMenu(std::list<Character>& enemylist)
{
    for (auto && it: party) {
        allCombatants.push_back(&it);
    }
    for (auto && it: enemylist) {
        allCombatants.push_back(&it);
    }
    selectedCharacter = allCombatants.begin();
}

bool BattleMenu::Run(sf::RenderWindow &rw)
{
    //initializing everything here cause I'm a dummy				--Note: I was having issue from copy constructors
    rw.setView(rw.getDefaultView());
    std::list<MenuItem> OptionList;

    MenuItem AttackOption ("Attack", resources.getFont("sansation.ttf"), MenuItem::Attack, sf::Vector2f(0,0));
    OptionList.push_back(AttackOption);
    MenuItem AbilityOption ("Ability", resources.getFont("sansation.ttf"), MenuItem::Ability, sf::Vector2f(0,50));
    OptionList.push_back(AbilityOption);
    MenuItem RecoveryOption ("Recover", resources.getFont("sansation.ttf"), MenuItem::Recover, sf::Vector2f(0,100));
    OptionList.push_back(RecoveryOption);
    MenuItem RunAwayOption ("Crash Game", resources.getFont("sansation.ttf"), MenuItem::Crash, sf::Vector2f(0,150));
    OptionList.push_back(RunAwayOption);
    
    {
        int placementX = SCREEN_WIDTH/(allCombatants.size()+1);		//used for initial placement and spacing.
        int placementY = INITIAL_ENEMY_Y;
        int index = 1;
        for (auto&& it : allCombatants)
        {
            it->setSpritePosition(placementX*index, placementY-CHARINFO_SPACING_Y);
            
            it->setPositionStatDisplay(placementX*index, placementY);
            it->setFont(resources.getFont("sansation.ttf"));
            it->UpdateStatDisplay();
            for (auto & ability: it->_abilityList)
            {
                ability.setFont(resources.getFont("sansation.ttf"));
            }
            index++;
        }
    }
    while (rw.isOpen())
    {
        StartOfTurn(rw);
        if ((*selectedCharacter)->_NPC)
        { ExecuteAI(rw); }
        else
        {	grayOutAbilities();
            ChooseOption(rw, OptionList);
        }
        if (CheckforBattleEnd())			//currently no distinction between enemy and ally victories
        {
            actionComplete = true;
            return true;						//put victory/defeat effects here!, currently only victory possible?
        }
        incrementPlayer();
        while ((*selectedCharacter)->_currentHealth == 0)
        {
            selectedCharacter++;
        }
    }
    return false;   //placeholder
}

void BattleMenu::ChooseOption(sf::RenderWindow &rw, std::list<MenuItem> OptionList)
{
    std::list<MenuItem>::iterator selected = OptionList.begin();
    selected->setColor(sf::Color::Red);
    selected->_name.setString((*_selectedCharacter)->_AttackName);
    sf::Event event;
    while (!_actionComplete)
    {
        rw.clear(sf::Color::White);
        _elapsed = _clock.restart().asSeconds();
        
        while(rw.pollEvent(event))
        {
            //scroll(event, std::forward<std::list<MenuItem>::iterator>(selected), std::forward<std::list<MenuItem>>(OptionList));
            scroll(event, selected, OptionList);
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::X))
            {
                ChangeMenu(*selected, rw);
                if (_actionComplete) {rw.clear(); return;}
            }
        }
        if ((*selected)._action == MenuItem::Attack)
        {
            (*_selectedCharacter)->_basicAttack.drawDesc(rw);
        }
        if ((*selected)._action == MenuItem::Recover)
        {
            (*_selectedCharacter)->_recoveryAbility.drawDesc(rw);
        }
        
        DrawAll(rw, OptionList);
        DrawAllStats(rw);
        rw.display();
    }
}

void BattleMenu::ChangeMenu(MenuItem selected, sf::RenderWindow &rw)
{
    switch (selected._action)
    {
        case MenuItem::Ability:
            ChooseAbility((*_selectedCharacter)->_abilityList, rw);
            break;
            
        case MenuItem::Attack:
            ChooseTarget((*_selectedCharacter)->_basicAttack, rw);
            break;
            
        case MenuItem::Recover:
            _actionComplete = true;
            (*_selectedCharacter)->UseRecovery(nullptr);
            break;
            
        case MenuItem::Crash:;
            _actionComplete = true;
            rw.close();
            break;
            
        default:
            break;
    }
}

void BattleMenu::ChooseAbility(std::list<Ability> Options, sf::RenderWindow &rw)
{
    std::list<Ability>::iterator selected = Options.begin();
    for (short temp = 0; selected != Options.end(); selected++, temp++)
    {
        (*selected).setPosition(0, temp*50);
    }
    selected = Options.begin();
    
    sf::Event event;
    while (!_actionComplete)
    {
        rw.clear(sf::Color::White);
        _elapsed = _clock.restart().asSeconds();
        while (rw.pollEvent(event))
        {
            scroll(event, selected, Options);
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::X))
            {
                ChooseTarget((*selected), rw);
                if (_actionComplete) {rw.clear(); return;}
            }
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Slash || event.key.code == sf::Keyboard::Z))
            {
                return;
            }
        }
        for (auto&& otherit: Options)
        {
            otherit.draw(rw);
        }
        (*selected).drawDesc(rw);
        DrawAllStats(rw);
        rw.display();
    }
}


void BattleMenu::ChooseTarget(Ability abil, sf::RenderWindow &rw)
{
    assert(!_characterlist.empty());
    std::list<Character*>::iterator selected =_characterlist.begin();
    if (!abil._allyPrimaryTarget)
    {
        while (!(*selected)->_NPC)
        { selected++; }
    }
    sf::Event event;
    while (!_actionComplete)
    {
        rw.clear(sf::Color::White);
        _elapsed = _clock.restart().asSeconds();
        while (rw.pollEvent(event))
        {
            (*selected)->_name.setColor(sf::Color::Black);
            scroll(event, selected, _characterlist);
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::X))
            {
                if (!(*_selectedCharacter)->CheckAbilityCost(abil)) return;
                (*_selectedCharacter)->PayAbilityCost(abil);
                _actionComplete = true;
                AnimateBattle(rw, (*selected), (*_selectedCharacter), (*selected)->takeDamage(abil, *(*_selectedCharacter)), abil);
                if ((*selected)->_currentHealth <= 0 && (*selected)->_NPC)
                {
                    if (_selectedCharacter == selected) {_selectedCharacter--;}
                    _characterlist.erase(selected);		//selected briefly points to deallocated space
                }
                return;
            }
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Slash || event.key.code == sf::Keyboard::Z))
            {
                return;
            }
            (*selected)->_name.setColor(sf::Color::Red);
        }
        DrawAllStats(rw);
        abil.drawDesc(rw);
        rw.display();
    }
}

void BattleMenu::DrawAllStats(sf::RenderWindow &rw)
{
    for (auto&& it: _characterlist)
    {
        it->drawAllStats(rw);
        it->_sprite.animate(_elapsed, rw);
    }
}

bool BattleMenu::CheckforBattleEnd()
{
    bool NoEnemies = true;
    bool NoAllies = true;
    for (auto&& it: _characterlist)
    {
        if (it->_NPC)
        {
            NoEnemies = false;
        }
        else if (it->_currentHealth > 0)
        {
            NoAllies = false;
        }
    }
    return (NoEnemies || NoAllies);
}

void BattleMenu::ExecuteAI(sf::RenderWindow &rw)
{
    if (_actionComplete)
    { return; }
    
    
    // Find out the applicable range of possible targets and pick one
    Character* Victim = PickTarget(false, _characterlist);
    
    //if Mana is lower than ~10%
    //use recovery ability
    //are enemy recovery abilities going to take targets?
    if ((*_selectedCharacter)->percentMana() < 0.1f) {
        (*_selectedCharacter)->UseRecovery(Victim);
        return;
    }
    
    //	Select a random Ability
    char Scope = (*_selectedCharacter)->_abilityList.size()+1;
    char RandomAction = (std::rand()%Scope);
    Ability* ChosenAbility;
    if (RandomAction == 0)
    { ChosenAbility = &(*_selectedCharacter)->_basicAttack; }
    else for (auto && it : (*_selectedCharacter)->_abilityList)
    {
        if (RandomAction == 1)
        {
            ChosenAbility = &it;
            break;
        }
        RandomAction--;
    }
    //if ability is HEAL then pick an ally rather than an enemy.
    if (ChosenAbility->hasProperty(Ability::Heal)) {
        Victim = PickTarget(true, _characterlist);
    }
    
    // Check for mana costs and apply damage
    if ((*_selectedCharacter)->CheckAbilityCost(*ChosenAbility))
    { (*_selectedCharacter)->PayAbilityCost(*ChosenAbility); }
    else ChosenAbility = &((*_selectedCharacter)->_basicAttack);
    AnimateBattle(rw, Victim, (*_selectedCharacter), Victim->takeDamage(*ChosenAbility, *(*_selectedCharacter)), *ChosenAbility);
}

Character* BattleMenu::PickTarget(bool NPC, const std::list<Character*>& list)
{
    // Find out the applicable range of possible targets
    char Scope = 0;
    for (auto && it : list)
    {
        if ((it->_NPC == NPC) && it->_currentHealth > 0)
        { Scope++; }
    }
    
    // Pick an applicable Target
    assert(Scope > 0);
    char RandomTarget = (std::rand()%Scope);
    Character* Victim = _characterlist.front();
    for (auto && it : _characterlist)
    {
        if (it->_currentHealth > 0 && (NPC == it->_NPC))
        {
            if (RandomTarget == 0)
            {
                Victim = it;
                break;
            }
            RandomTarget--;
        }
    }
    return Victim;
}

void BattleMenu::AnimateBattle(sf::RenderWindow &rw, Character *Defender, Character *Attacker, float Damage, Ability& abil)
{
    _effectsHandler.clearAll();
    sf::Event event;
    int phase = 0;
    sf::View view = rw.getDefaultView();
    
    sf::Text damageText;
    damageText.setFont(_font);
    std::ostringstream ss;
    ss << static_cast<int>(Damage);
    damageText.setString(ss.str());
    int textColor = 255;
    if (!Damage) {textColor = 0;}
    damageText.setColor(sf::Color(255, 0, 0, textColor));
    damageText.setPosition(rw.getDefaultView().getCenter().x, DIRECT_COMBAT_Y-50);
    
    
    sf::Vector2f returnPosAttacker = Attacker->_sprite.getPosition();
    sf::Vector2f returnPosDefender = Defender->_sprite.getPosition();
    sf::Vector2f PrimaryPosition (rw.getDefaultView().getCenter().x-75, DIRECT_COMBAT_Y);
    sf::Vector2f SecondaryPosition (rw.getDefaultView().getCenter().x+75, DIRECT_COMBAT_Y);
    
    //Hecka placeholder
    sf::Texture attackAnimation;
    attackAnimation.loadFromFile("BadAttackAnimation.png");
    sf::Texture getHitAnimation;
    getHitAnimation.loadFromFile("GetHitAnimation.png");
    
    while (phase < 4 && rw.isOpen())
    {
        rw.clear(sf::Color::White);
        _elapsed = _clock.restart().asSeconds();
        while (rw.pollEvent(event))
        {
            //nothing here, this is just to make sure I don't crash...
        }
        if (!_effectsHandler.isBusy())
        {
            phase++;
            switch (phase) {
                case 1:
                    _effectsHandler.addEffect(EffectsHandler::ZoomIn);
                    if (Attacker->_NPC)
                    {
                        _effectsHandler.addSprite(&Defender->_sprite, PrimaryPosition);
                        _effectsHandler.addSprite(&Attacker->_sprite, SecondaryPosition);
                    }
                    else
                    {
                        _effectsHandler.addSprite(&Defender->_sprite, SecondaryPosition);
                        _effectsHandler.addSprite(&Attacker->_sprite, PrimaryPosition);
                    }
                    break;
                case 2:
                    //I need to have this return something when the attack animations are both done...
                    ActualBattle(rw, Defender, Attacker, abil);	//need to have ability that hits to pass in...
                    *//*Attacker->_sprite.setTexture(attackAnimation);
                     Attacker->setIdleNext();
                     Defender->_sprite.setTexture(getHitAnimation);
                     Defender->setIdleNext();
                     _effectsHandler.addEffect(EffectsHandler::Pause);*//*
                    
                    break;
                case 3:
                    Attacker->setIdle();
                    Defender->setIdle();
                    _effectsHandler.addEffect(EffectsHandler::ZoomOut);
                    _effectsHandler.addSprite(&Defender->_sprite, returnPosDefender);
                    _effectsHandler.addSprite(&Attacker->_sprite, returnPosAttacker);
                    break;
                    
                default:
                    break;
            }
        }
        if (textColor > 0) {
            textColor -= _elapsed * 100;
            damageText.move(0, -40 * _elapsed);
            damageText.setColor(sf::Color(255, 0, 0, textColor));
            rw.draw(damageText);
        }
        
        _effectsHandler.UpdateSprites(_elapsed);
        _effectsHandler.Update(_elapsed, view, rw);
        rw.setView(view);
        
        DrawAllStats(rw);
        rw.display();
    }
    return;
}

void BattleMenu::ActualBattle(sf::RenderWindow& rw, Character* Defender, Character* Attacker, Ability& abil)
{
    //start the attacker's animation
    Attacker->_sprite.setTexture(*abil.hitAnimation);
    Attacker->setIdleNext();
    Defender->setGetHit();
    Defender->setIdleNext();
    
    float deleteme {0};
    
    sf::Event fuck;
    while (deleteme < 30.0) {
        while (rw.pollEvent(fuck))
        {
            //nothing here, this is just to make sure I don't crash...
        }
        rw.clear(sf::Color::White);
        deleteme += _clock.restart().asSeconds();
        
        //if() certain frame, start getHit animation
        Attacker->_sprite.animate(_elapsed, rw);
        if (Attacker->_sprite.isOnFrame() > abil.hitsOnFrame) {		// > or >= ?
            Defender->_sprite.animate(_elapsed, rw);
        }
        else
            Defender->_sprite.draw(rw);
        
        //if() animations are done, return.
        if (Attacker->isIdle() && Defender->isIdle()) {			//isIdle() will return a bool if IdleTexture is used
            return;
        }
        
        //draw all the shite
        DrawAllStats(rw);
        rw.display();
    }
}


void BattleMenu::StartOfTurn(sf::RenderWindow &rw)
{
    _actionComplete = false;
    for (auto it = (*_selectedCharacter)->StatusEffects.begin(); it != (*_selectedCharacter)->StatusEffects.end();)
    {
        switch (it->first)
        {
            case Ability::Poison:
            case Ability::Bleed:
                (*_selectedCharacter)->_currentHealth -= it->second;
                if ((*_selectedCharacter)->_currentHealth <= 0)
                {
                    (*_selectedCharacter)->_currentHealth = 0;
                    if (CheckforBattleEnd())								//if last enemy dies from DOT
                    {
                        _actionComplete = true;
                        rw.close();
                        return;
                    }
                    (*_selectedCharacter)->UpdateStatDisplay();
                    if ((*_selectedCharacter)->_NPC)
                    {
                        _characterlist.erase(_selectedCharacter++);			//can't use increment player here because I need returned value
                    }
                    else
                    {
                        _selectedCharacter++;
                    }
                    if (_selectedCharacter == _characterlist.end())
                    {_selectedCharacter = _characterlist.begin();}
                    
                    StartOfTurn(rw);
                    return;
                }
                (*_selectedCharacter)->UpdateStatDisplay();
                it++;
                break;
                
            case Ability::Stun:
                (*_selectedCharacter)->StatusEffects.erase(it++);
                _actionComplete = true;
                break;
                
                
            case Ability::SelfShieldPercent:
                (*_selectedCharacter)->StatusEffects.erase(it++);
                break;
                
            default:
                it++;
                break;
        }
        if (it == (*_selectedCharacter)->StatusEffects.end() )
        { return; }
    }
}

void BattleMenu::incrementPlayer()
{
    _selectedCharacter++;
    if (_selectedCharacter == _characterlist.end())
    {_selectedCharacter = _characterlist.begin();}
}

void BattleMenu::grayOutAbilities()
{
    for (auto && it: (*_selectedCharacter)->_abilityList) {
        if ((*_selectedCharacter)->CheckAbilityCost(it)) {
            it.toggleGray(false);
        }
        else it.toggleGray(true);
    }
}




*/






