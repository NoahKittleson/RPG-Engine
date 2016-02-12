//
//  DialogueThread.h
//  Overworld
//
//  Created by Noah Kittleson on 11/15/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class DialogueThread
{
public:
    DialogueThread(sf::String choice = "ERROR");
    
    void addDialogue(sf::String);
    void addChoice(DialogueThread* DTptr);
    
    std::list<sf::String>& getDialogue();
    std::list<DialogueThread*> getChoices();
    sf::String getStartingOption();
    
private:
    sf::String StartingOption;
    std::list<sf::String> Dialogue;
    std::list<DialogueThread*> Choices;
};
    