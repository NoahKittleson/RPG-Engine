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
    ~OptionNode() {std::cout << "OptionNode deleted. Text:" << getText() << "\n";}
    
    void addText(sf::String&&, DNode*);
    
    void update(float elapsed) override;
    void draw(sf::RenderWindow &rw) override;
    void handleInput(sf::Event&) override;
    DNode* getNext() override;
    
    std::string getText() override {
        return text[0].first.toAnsiString();
    }
    
private:
    IterVector<std::pair<sf::String, DNode*>> text;
};