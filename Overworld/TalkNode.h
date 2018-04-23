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
    ~TalkNode();
    
    void addText(sf::String&&);
    //void setNext(NodePtr ptr);
	
    void clear() override;
    void update(float elapsed) override;
    void draw(sf::RenderWindow &rw) override;
    void handleInput(sf::Event&) override;
    NodePtr getNext() override;
	void attachNext(NodePtr next, std::string prompt);

private:
    NodePtr next {nullptr};
    float totalElapsed {0};
    IterVector<sf::String> text;
    
    std::string getText() override;
};
