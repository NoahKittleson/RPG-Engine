//
//  DManager.h
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "TalkNode.h"
#include "OptionNode.h"
#include "State.h"
#include "DialogueFactory.hpp"

class DialogueMode : public State
{
public:
    DialogueMode(NodePtr start);
	
	void update(sf::Clock &clock) override;
    void draw(sf::RenderWindow&) override;
    void handleInput(sf::RenderWindow& rw) override;
    
private:
	sf::Sprite dialogueBar;
    NodePtr currentDNode;
		
};
