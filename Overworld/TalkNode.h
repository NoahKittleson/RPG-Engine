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
	TalkNode(const sf::Font&, Dialogue::ID);
    ~TalkNode();
    
	void addText(sf::String&&);
	void addPath(DPath path);
	
    void clear() override;
    void update(float elapsed) override;
    void draw(sf::RenderWindow &rw) override;
	void handleInput(sf::Event&) override;
	Dialogue::ID getNext(const std::vector<Condition>& cv) override;

private:
	//Dialogue::ID next { Dialogue::None };
    float totalElapsed {0};
    IterVector<sf::String> text;
	std::vector<DPath> potentialPaths;
    
    std::string getText() override;
};
