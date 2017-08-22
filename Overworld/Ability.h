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
    Ability();
    Ability(std::string name, std::string desc, float BaseDmg, bool multiTarget, bool AllyTarget, const sf::Texture&);
    friend class Character;
    
    float _baseDamage = 0;
    char hitsOnFrame = 2;
    
    enum Properties {Poison, Bleed, Stun, Heal, DeathMark, SelfShieldPercent, FlatDmgBuff, PercentManaRecovery,
                    PoisonHeal, AntidotePercent, GiveMana, SelfHeal, SelfStun, Clear};
    //Props to display onscreen: Poison, Bleed, Stun, Deathmark, Shield, Buff, (Curse?), (Blind?)
    
    enum Requirements {ManaCost, HealthCost, };
    enum DamageMultipliers {VSUndead, WhilePoisoned, VSHealthy, VSUnhealthy, VSFullHealth};	//if fulfills name, apply number multiplier
    enum DamageType {Physical, Earth, Air, Fire, Water, Dark, Light};	//oh baby it's Mardek...
    enum AfterEffects {LifeDrain, ManaDrain};							//things calculated after all damage has been dealt
    
    void setProperties(Properties, float);
    void setReq(Requirements, float);
    void setMultiplier(DamageMultipliers, float);
    void setDamageType(DamageType);
    void setAfterEffects(AfterEffects, float);
    
    void setColor(sf::Color);
    void setPosition(float x, float y);
    void setFont(const sf::Font &font);
    void draw(sf::RenderWindow &rw);
    void drawDesc(sf::RenderWindow &rw);
    
    bool _allyPrimaryTarget;			//true = ally, false = enemy as primary target
    bool hasProperty(const Properties& type) const;
    void toggleGray(bool gray);
    bool isGrayedOut();
    
    const sf::Texture* hitAnimation;
    
private:
    //passive abilities should be different and hard programmed into characters?????
    void drawReqs(sf::RenderWindow &rw);
    
    bool _multiTarget;
    
    
    sf::Text _AbilityName;
    sf::Text _AbilityDescription;
    
    std::map<Properties, float> AbilityProperties;
    //std::map<Properties, float> AbilitySelfProperties;				//consider properly implementing this??
    std::map<Requirements, float> AbilityRequirements;
    std::map<AfterEffects, float> AbilityAfterEffects;
    
    std::pair<DamageMultipliers, float> AbilityDmgMulti;
    
    DamageType _dmgType;
};


//class NewAbility : public NewMenuItem {
//public:
//	virtual void draw(sf::RenderWindow &rw) override;			//draw text & desc
//	virtual void update(float elapsed) override;				//nothing?
//	virtual void handleInput(sf::RenderWindow& rw) override;	//scroll up and down IF active and there are options
//	virtual void select() override;								//select = true, highlight
//	virtual void activate() override;							//active = true, create options
//	virtual void deselect() override;							//select = false, unhighlight
//	virtual void deactivate() override;							//active = false
//	virtual bool selectable() override;							//NEED to know who the Character is
//	void setPosition(float x, float y);							//need one for Name, one for Description
//	
//	void setCallback(std::function<void()> callback);			//setter;
//	
//private:
//	//sf::Text
//	sf::Text description;
//	std::function<void()> callback;
//};





