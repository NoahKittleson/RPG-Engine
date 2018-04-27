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
#include "Conditions.cpp"
#include "DialogueIDs.cpp"

class DNode;

//using NodePtr = std::shared_ptr<DNode>;

class DNode
{
public:
    DNode(const sf::Font&);
    void setPosition(float x, float y);
    void setPosition(sf::Vector2f xy);
    sf::Vector2f getPosition() const;
    
    virtual void clear();
    virtual void update(float) = 0;
    virtual void draw(sf::RenderWindow &rw) = 0;
    virtual void handleInput(sf::Event&) = 0;
	virtual Dialogue::ID getNext() = 0;
	
	virtual void addPreReq(Condition add);
	virtual void addConsequence(Condition add);
	virtual void resolveConditions(std::vector<Condition>& cv) const;
	virtual bool checkConditions(const std::vector<Condition>& cv) const;

protected:
    sf::Text display;
	std::vector<Condition> preReqs;
	std::vector<Condition> consequences;
	
    virtual std::string getText() = 0;
};
