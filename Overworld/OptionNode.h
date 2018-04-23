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
    OptionNode(const sf::Font& font);
    ~OptionNode();
    
    void addText(sf::String&&, NodePtr);
    
    void update(float elapsed) override;
    void draw(sf::RenderWindow &rw) override;
    void handleInput(sf::Event&) override;
	NodePtr getNext() override;
	void attachNext(NodePtr next) override;

    
private:
    IterVector<std::pair<sf::String, NodePtr>> text;
    std::string getText() override;
};
