//
//  BattleMenu.h
//  SFML test
//
//  Created by Noah Kittleson on 1/12/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "Menu.h"
#include "MenuItem.h"
#include "Character.h"
#include "PrefixHeader.pch"
#include "EffectsHandler.h"
#include "State.h"

/*class BattleMenu: public Menu, public State
{
public:
    BattleMenu(std::list<Character>& enemies);
    bool Run(sf::RenderWindow &rw);
    
private:
    bool actionComplete;
    std::list<Character*> allCombatants;
    std::list<Character*>::iterator selectedCharacter;
    EffectsHandler effectsHandler;
    
    void update(sf::RenderWindow &rw, sf::Clock& timer) override;


    void StartOfTurn(sf::RenderWindow &rw);
    bool CheckforBattleEnd();
    void ExecuteAI(sf::RenderWindow &rw);
    Character* PickTarget(bool enemy, const std::list<Character*>&);
    
    void ChangeMenu(MenuItem, sf::RenderWindow &rw);
    void ChooseOption(sf::RenderWindow &rw, std::list<MenuItem>);
    void ChooseAbility(std::list<Ability>, sf::RenderWindow &rw);
    void ChooseTarget(Ability ability, sf::RenderWindow &rw);
    
    void DrawAllStats(sf::RenderWindow &rw);		//also draws character sprites
    void AnimateBattle(sf::RenderWindow& rw, Character* Defender, Character* Attacker, float Damage, Ability& abil);
    void ActualBattle(sf::RenderWindow& rw, Character* Defender, Character* Attacker, Ability& abil);
    
    void incrementPlayer();
    void grayOutAbilities();
    
};
*/
