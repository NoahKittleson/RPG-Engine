//
//  DialogueMode.h
//  Overworld
//
//  Created by Noah Kittleson on 11/15/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "State.h"
#include "MapSection.h" //previously dialoguethread.


class DialogueMode: public State
{
public:
    DialogueMode (DialogueThread* beginningSpool);
    void update(sf::RenderWindow& rw, sf::Clock&) override;
    
private:
    sf::String getGradualText(sf::String full, sf::String partial);
    void drawOptions(sf::RenderWindow &rw);
    
    std::list<sf::String>::iterator it;
    std::list<DialogueThread*>::iterator choice;
    float totalElapsed{0};
    sf::Font font;
    sf::Text displayText;
    sf::RectangleShape displayFrame;
    DialogueThread* spool;
};



//What if:
//I made DialogueMode into a class similar to StateStack where you could pile on DialogueStates and it processes the first one each
//turn, changing the conditions of the DialogueStack as it resolves each item.  For example, the dialogueStack could only ever be
//two items deep, BUT the first item would print out all the dialogue, the second item would wait for you to select a dialogueOption,
//changing the dialogueThread that is selected so the dialoguePrinter can continue doing its job.
