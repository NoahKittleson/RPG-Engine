//
//  OptionNode.h
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "DNode.h"


class OptionNode: public DNode
{
public:
    OptionNode(const sf::Font& font, Dialogue::ID id);
    ~OptionNode();
    
	void addText(sf::String&&, std::vector<DPath>);
    
    void update(float elapsed) override;
    void draw(sf::RenderWindow &rw) override;
    void handleInput(sf::Event&) override;
	Dialogue::ID getNext(const std::vector<Condition>& cv) override;
	
private:
    IterVector<std::pair<sf::String, std::vector<DPath>>> text;
    std::string getText() override;
};
