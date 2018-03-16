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
    Character(int MaxHealth, int MaxMana, const sf::Texture& texture, const sf::Font&, std::string name, bool enemy, const sf::Texture& getHit);
    Character(const Character& other) = delete;
    Character& operator= (const Character &other) = delete;
    ~Character();
	
    void addAbility(Ability&);
	void setBasicAttack(Ability& abil);
	void setRecoveryAbility(Ability& abil);
	const Ability getBasicAttack() const;
	const Ability getRecoveryAbility() const;
	const IterVector<Ability> getAbilityList() const;
	
    bool checkAbilityCost(const Ability&) const;
    void payAbilityCost(Ability&);
	float calculateDmg(Ability, std::shared_ptr<Character> attacker);
	void move(sf::Vector2f movement);
	void animate(float elapased);
	void setStatPosition(int x, int y);
	void setSpritePosition(int x, int y);
	sf::Vector2f getSpritePosition() const;
	void drawAllStats(sf::RenderWindow&);
	void drawSprite(sf::RenderWindow&);
	std::string getName() const;
	void setFont(const sf::Font &font);
	void adjustHealth(int);
	float getHealth() const;
	void adjustMana(int);
	float getMana() const;
	bool isNPC() const;
	
	//NEW AND BAD//
	bool isIdle() {return sprite.getTexture() == idleTexture;};
	void setAnimation(const sf::Texture& texture);
	void startGetHitAnimation() {if (idleTexture) {sprite.setTexture(*idleTexture);}};
	//NEW AND BAD//

private:
	const bool NPC;
    float maxHealth;
    float currentHealth;
    float maxMana;
    float currentMana;
	Ability basicAttack;
	Ability recoveryAbility;
	IterVector<Ability> abilityList;
	
	sf::Text name;
    std::map<Ability::Property, float> statusEffects;			//or any modifier applied each turn
	AnimatedSprite sprite;
    const sf::Texture* idleTexture = nullptr;
    const sf::Texture* getHitTexture = nullptr;
	sf::Text MPText;
	sf::Text HPText;
	sf::RectangleShape MPBar;
	sf::RectangleShape HPBar;
	sf::RectangleShape barOutline;
	std::list<sf::Text> statusEffectDisplay;
    
    void addPoison(int);
    void addAdditiveProperty(float, Ability::Property);
    void addStun(int);
    void addMark();
    void addSelfShield(float);
    void addFlatDmgBuff(int);
    void curePoison(float);
	std::string getText(std::string Description, int currentValue, int maxValue);
    float percentMana();
    float percentHealth();
    void updateStatDisplay();
    void updateStatusEffects();
};



















