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
    virtual DNode* getNext() = 0;
    
protected:
    sf::Text display;
	std::vector<Condition> conds;
	
    virtual std::string getText() = 0;

};
