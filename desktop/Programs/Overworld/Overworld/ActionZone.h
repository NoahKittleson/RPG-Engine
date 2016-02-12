//
//  ActionZone.h
//  Overworld
//
//  Created by Noah Kittleson on 9/16/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "Character.h"
#include "DialogueThread.h"

enum class ActionType {None, Dialogue, Fight, OverWorld};

class ActionZone
{
public:
	sf::FloatRect getPosition();
	virtual ActionType getType();
	//virtual void resolve(sf::RenderWindow& rw, std::list<Character*>& party) = 0;
	
protected:
	ActionZone(sf::FloatRect pos): position (pos) {};

	sf::FloatRect position;
};



class FightZone: public ActionZone
{
public:
	FightZone(std::list<Character>& enemies, sf::FloatRect pos);
	
	virtual ActionType getType() override;
	//virtual void resolve(sf::RenderWindow& rw, std::list<Character*>& party);
	
    std::list<Character>* enemylist;
};



class DialogueZone: public ActionZone
{
public:
	DialogueZone(std::list<sf::Text>& texts, sf::FloatRect& pos);
	
	bool intersects(sf::FloatRect);
	virtual ActionType getType() override;
	
	DialogueThread* dialogue;
	//virtual void resolve(sf::RenderWindow& rw, std::list<Character*>& party);
private:
	std::list<sf::Text>* list;
};











