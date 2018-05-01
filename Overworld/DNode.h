//
//  DNode.h
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "IterVector.hpp"
#include "Conditions.hpp"
#include "DialogueIDs.hpp"

class DNode;

using NodePtr = std::shared_ptr<DNode>;

class DNode
{
public:
	DNode(const sf::Font&, Dialogue::ID ID);
    void setPosition(float x, float y);
    void setPosition(sf::Vector2f xy);
    sf::Vector2f getPosition() const;
    
    virtual void clear();
    virtual void update(float) = 0;
    virtual void draw(sf::RenderWindow &rw) = 0;
    virtual void handleInput(sf::Event&) = 0;
	virtual Dialogue::ID getNext(const std::vector<Condition>& cv) = 0;
	Dialogue::ID getID() const;
	
	virtual void addConsequence(Condition add);
	//virtual void addPreReq(Condition add);
	virtual void resolveConditions(std::vector<Condition>& cv) const;
	//virtual bool checkConditions(const std::vector<Condition>& cv) const;

protected:
    sf::Text display;
	//std::vector<Condition> preReqs;
	std::vector<Condition> consequences;
	Dialogue::ID ID;
	
    virtual std::string getText() = 0;
};


struct DPath
{
public:
	DPath(std::vector<Condition> preReqs, Dialogue::ID next);
	bool isSatisfied(const std::vector<Condition> activeConds) const;
	Dialogue::ID getNext() const;
	
private:
	std::vector<Condition> preReqs;
	Dialogue::ID next;
};
