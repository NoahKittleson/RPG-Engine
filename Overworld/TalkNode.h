//
//  TalkNode.h
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "DNode.h"

class TalkNode: public DNode
{
public:
    TalkNode(sf::Font&);
    
    void addText(sf::String&&);
    void setNext(DNode *ptr);
    
    void update(float elapsed) override;
    void draw(sf::RenderWindow &rw) override;
    void handleInput(sf::Event&) override;
    DNode* getNext() override;
    
private:
    DNode* next {nullptr};
    float totalElapsed{0};
    IterVector<sf::String> text;

};