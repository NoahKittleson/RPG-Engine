//
//  TalkNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "TalkNode.h"


void TalkNode::setNext(DNode *ptr)
{
    next = ptr;
}

//TalkNode::TalkNode(const TalkNode& other) : DNode(*other.display.getFont()) {
//    
//}

TalkNode::TalkNode(const sf::Font &font)
: DNode(font)
{
    text.setLooping(false);
}

void TalkNode::addText(sf::String&& add)
{
    text.push_back(add);
}

void TalkNode::update(float elapsed)
{
    auto displayString = display.getString();
    totalElapsed += elapsed;
    
    if (displayString.getSize() == text.get().getSize()) {
        return;
    }
    float time_per_letter = 0.02;
    while (totalElapsed >= time_per_letter && displayString.getSize() != text.get().getSize()) {
        displayString += text.get()[displayString.getSize()];
        totalElapsed -= time_per_letter;
    }
    display.setString(displayString);
}


void TalkNode::draw(sf::RenderWindow &rw)
{
    rw.draw(display);
}

void TalkNode::clear() {
    display.setString("");
    totalElapsed = 0;
}

void TalkNode::handleInput(sf::Event &)         //perhaps for later?
{
    return;
}

DNode* TalkNode::getNext()
{
    if (text.get().getSize() != display.getString().getSize()) {
        display.setString(text.get());
        return this;
    }
    
    if (text.atEnd()) {
        text.reset();
        return next;
    }
    ++text;
    clear();
    return this;
}