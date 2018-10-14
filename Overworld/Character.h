//
//  Character.h
//  BattleMode
//
//  Created by Noah Kittleson on 1/2/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "Ability.hpp"
#include "IterVector.hpp"
#include "AnimatedComponent.hpp"
#include "BattleInfo.hpp"
#include "BattleAI.hpp"
#include "AnimationSheet.hpp"
#include "AudioHandler.hpp"

class BattleInfo;
class BattleAI;

class Character : sf::NonCopyable
{
public:
	Character(int MaxHealth, int MaxMana, const sf::Font&, std::string name, bool NPC, const AnimationSheet anims);
    Character(const Character& other) = delete;
    Character& operator= (const Character &other) = delete;
    ~Character();
	
    void addAbility(Ability&);
	void setBasicAttack(Ability& abil);
	void setRecoveryAbility(Ability& abil);
	const Ability& getBasicAttack() const;
	const Ability& getRecoveryAbility() const;
	const IterVector<Ability>& getAbilityList() const;
	
    bool checkAbilityCost(const Ability&) const;
    void payAbilityCost(const Ability&);
	float calculateDmg(const Ability&, std::shared_ptr<Character> attacker);
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
	bool isIncapped() const;
	
	void fillInAction(BattleInfo&) const;
	void attachAudio(AudioHandler& audio);
	
	//NEW AND BAD//
	bool isIdle();
	void setIdle();
	void startAttackAnimation(const Ability& abil);
	void startGetHitAnimation();
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
	AnimatedComponent sprite;
	AnimationSheet animations;
	sf::Text MPText;
	sf::Text HPText;
	sf::RectangleShape MPBar;
	sf::RectangleShape HPBar;
	sf::RectangleShape barOutline;
	std::list<sf::Text> statusEffectDisplay;
	std::unique_ptr<BattleAI> AI = nullptr;
	AudioHandler* audio = nullptr;
    
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


















