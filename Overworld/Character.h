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

class Character : sf::NonCopyable
{
public:
    Character(int MaxHealth, int MaxMana, int BasicAttackDmg,  const sf::Texture& texture, const sf::Font&, std::string name, std::string Attackname, bool enemy, const sf::Texture& getHit);
    Character(const Character& other) = delete;
    Character& operator= (const Character &other) = delete;
    ~Character();
	
    void addAbility(Ability&);
    bool CheckAbilityCost(const Ability&) const;
    void PayAbilityCost(Ability&);
	float calculateDmg(Ability, std::shared_ptr<Character> attacker);
	
	//NEW AND BAD//
	bool isIdle() {return sprite.getTexture() == IdleTexture;};
	void setAnimation(const sf::Texture& texture);
	void startGetHitAnimation() {if (IdleTexture) {sprite.setTexture(*IdleTexture);}};
	//NEW AND BAD//
	
    void setStatPosition(int x, int y);
    void setSpritePosition(int x, int y);
	sf::Vector2f getSpritePosition() const;
	void move(sf::Vector2f movement);
    void drawAllStats(sf::RenderWindow&);
    void drawSprite(sf::RenderWindow&);

    void adjustHealth(int);
    float getHealth() const;
    void adjustMana(int);
    float getMana() const;
	std::string getName() const;
    
    void setColor(sf::Color);                             //Sets item's color in an option menu
    void setFont(const sf::Font &font);
    
    void animate(float elapased);
    
private:
	Ability basicAttack;
	Ability recoveryAbility;
	IterVector<Ability> abilityList;
	const bool NPC;
	sf::Text name;
	
    //character stats
    AnimatedSprite sprite;
    std::string attackName;
    float maxHealth;
    float currentHealth;
    float maxMana;
    float currentMana;
    
    std::map<Ability::Property, float> StatusEffects;			//or any modifier applied each turn
    
    const sf::Texture* idleTexture = nullptr;
    const sf::Texture* getHitTexture = nullptr;
    
    void addPoison(int);
    void addAdditiveProperty(float, Ability::Property);
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
    sf::Text MPText;
    sf::Text HPText;
    sf::RectangleShape MPBar;
    sf::RectangleShape HPBar;
    sf::RectangleShape barOutline;
    std::list<sf::Text> statusEffectDisplay;
    
};



















