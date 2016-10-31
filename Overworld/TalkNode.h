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
    TalkNode(const sf::Font&);
//    TalkNode(const TalkNode& other);
    ~TalkNode() {std::cout << "TalkNode deleted. Text:" << getText() << "\n";}
    
    void addText(sf::String&&);
    void setNext(DNode *ptr);
    
    void clear() override;
    
    void update(float elapsed) override;
    void draw(sf::RenderWindow &rw) override;
    void handleInput(sf::Event&) override;
    DNode* getNext() override;
    
    std::string getText() override {
        return "TEST420";//text[0];
    }
    
private:
    DNode* next {nullptr};
    float totalElapsed{0};
    IterVector<sf::String> text;

};