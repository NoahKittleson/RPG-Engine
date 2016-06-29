//
//  MenuItem.cpp
//  SFML test
//
//  Created by Noah Kittleson on 1/11/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "MenuItem.h"

MenuItem::MenuItem()                            //this shouldn't even be called...
{
    _name.setColor(sf::Color::Black);
    _name.setString("EMPTY. ERROR");
    _name.setCharacterSize(50);
    _name.setPosition(0, 0);
}

MenuItem::MenuItem(std::string string, const sf::Font& font, Action A, sf::Vector2f pos)
: _action(A)
{
    _name.setColor(sf::Color::Black);
    _name.setString(string);
    _name.setFont(font);
    _name.setCharacterSize(50);
    _name.setPosition(pos);
}

void MenuItem::draw(sf::RenderWindow &rw)
{
    rw.draw(_name);
}

void MenuItem::setColor(sf::Color color)
{
    _name.setColor(color);
}

void MenuItem::setPosition(float x, float y)
{
    _name.setPosition(x, y);
}