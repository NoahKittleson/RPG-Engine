//
//  DialogueThread.cpp
//  Overworld
//
//  Created by Noah Kittleson on 11/15/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "DialogueThread.h"


DialogueThread::DialogueThread(sf::String str)
: StartingOption(str)
{
    
}

std::list<DialogueThread*> DialogueThread::getChoices()
{
    return Choices;
}

void DialogueThread::addDialogue(sf::String str)
{
    Dialogue.push_back(str);
}

void DialogueThread::addChoice(DialogueThread *DTptr)
{
    Choices.push_back(DTptr);
}

std::list<sf::String>& DialogueThread::getDialogue()
{
    return Dialogue;
}

sf::String DialogueThread::getStartingOption()
{
    return StartingOption;
}

