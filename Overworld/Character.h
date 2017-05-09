//
//  Character.h
//  BattleMode
//
//  Created by Noah Kittleson on 1/2/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "Ability.h"
#include "IterVector.hpp"
#include "AnimatedSprite.h"

class Character
{
public:
    Character(int MaxHealth, int MaxMana, int BasicAttackDmg,  const sf::Texture& texture, const sf::Font&, std::string name, std::string Attackname, bool enemy, const sf::Texture& getHit);
    Character(const Character& other);
    Character& operator= (const Character &other) = delete;
    ~Character();
    
    void addAbility(Ability&);
    bool CheckAbilityCost(Ability&);
    void PayAbilityCost(Ability&);
    float takeDamage(Ability, Character& attacker);

    void setStatPosition(int x, int y);
    void setSpritePosition(int x, int y);
    void drawAllStats(sf::RenderWindow&);
    void drawSprite(sf::RenderWindow&);

    void adjustHealth(int);
    float getHealth() const;
    void adjustMana(int);
    float getMana() const;
    
    void setColor(sf::Color);                             //Sets item's color in an option menu
    void setFont(const sf::Font &font);
    
    void animate(float elapased);
    //void UseRecovery();
    //void UseRecovery(Character* target);					//there has got to be a better way to do damaging recoveries...
    //void setIdle();
    //void setIdleNext();
    //void setGetHit();
    //bool isIdle();
    //void drawName(sf::RenderWindow&);
    
public:
    Ability _basicAttack;
    Ability _recoveryAbility;
    IterVector<Ability> _abilityList;
    const bool _NPC;
    sf::Text _name;
    
private:
    //character stats
    //sf::Text _name;
    AnimatedSprite _sprite;
    std::string _AttackName;
    float _maxHealth;
    float _currentHealth;
    float _maxMana;
    float _currentMana;
    
    std::map<Ability::Properties, float> StatusEffects;			//or any modifier applied each turn
    
private:
    const sf::Texture* _IdleTexture;
    const sf::Texture* _getHitTexture;
    
    void addPoison(int);
    void addAdditiveProperty(float, Ability::Properties);
    void addStun(int);
    void addMark();
    void addSelfShield(float);
    void addFlatDmgBuff(int);
    void curePoison(float);
    
    float percentMana();
    float percentHealth();
    void UpdateStatDisplay();
    void updateStatusEffects();
    
    std::string GetText(std::string Description, int currentValue, int maxValue);
    sf::Text _MPText;
    sf::Text _HPText;
    sf::RectangleShape _MPBar;
    sf::RectangleShape _HPBar;
    sf::RectangleShape _BarOutline;
    std::list<sf::Text> StatusEffectDisplay;
    
};



















