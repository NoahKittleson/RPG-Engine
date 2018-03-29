//
//  Ability.h
//  BattleMode
//
//  Created by Noah Kittleson on 1/17/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
//#include "MenuItem.h"

class Ability
{
public:
    Ability(std::string name, std::string desc, float BaseDmg, bool multiTarget, bool AllyTarget, const sf::Texture&);
    friend class Character;

    enum Property {Poison, Bleed, Stun, Heal, DeathMark, SelfShieldPercent, FlatDmgBuff, PercentManaRecovery,
                    PoisonHeal, AntidotePercent, GiveMana, SelfHeal, SelfStun, Clear};
    //Props to display onscreen: Poison, Bleed, Stun, Deathmark, Shield, Buff, (Curse?), (Blind?)
    
    enum Requirement {ManaCost, HealthCost, };
    enum DamageMultiplier {VSUndead, WhilePoisoned, VSHealthy, VSUnhealthy, VSFullHealth};
    enum DamageType {Physical, Earth, Air, Fire, Water, Dark, Light};
    enum AfterEffect {LifeDrain, ManaDrain};							//things calculated after all damage has been dealt
    
    void addProperty(Property, float, bool onSelf);
    void addReq(Requirement, float);
    void addAfterEffect(AfterEffect, float);
	void setMultiplier(DamageMultiplier, float);
	void setDamageType(DamageType);
	void setColor(sf::Color);
	void setPosition(float x, float y);
	void setFont(const sf::Font &font);
    void draw(sf::RenderWindow &rw);
    void drawDesc(sf::RenderWindow &rw);
	std::string getName() const;
    bool hasProperty(const Property& type) const;
	bool isAttackSpell() const;

	
private:
    void drawReqs(sf::RenderWindow &rw);
    
    bool multiTarget;
	float baseDamage = 420;
	char hitsOnFrame = 2;
	const sf::Texture* hitAnimation = nullptr;
	bool allyTargetPref;			//true = ally, false = enemy as primary target
	
    sf::Text abilityName;
    sf::Text abilityDescription;
    
    std::map<Property, float> properties;
    std::map<Property, float> selfProperties;
    std::map<Requirement, float> requirements;
    std::map<AfterEffect, float> afterEffects;
    
    std::pair<DamageMultiplier, float> dmgMulti;
    
    DamageType dmgType;
};





