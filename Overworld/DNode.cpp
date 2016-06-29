//
//  DNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "DNode.h"

DNode::DNode(sf::Font& font)
{
    display.setFont(font);
    display.setColor(sf::Color::Black);
    display.setString("");
}

void DNode::setPosition(float x, float y)
{
    display.setPosition(x, y);
}