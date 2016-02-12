//
//  MenuItem.h
//  SFML test
//
//  Created by Noah Kittleson on 1/11/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class MenuItem
{
public:
    enum Action {Attack, Ability, Recover, Nothing, Crash};
    
    MenuItem(std::string, const sf::Font&, Action, sf::Vector2f);
    void draw(sf::RenderWindow &rw);
    void setPosition(float x, float y);
    void setColor(sf::Color color);
    
    Action _action;
    sf::Text _name;
    
private:
    MenuItem();
    
};

class NewMenuOption : public sf::Text
{
    MenuItem::Action action;
};

//template <class Type>
//class MenuOption
//{
//    Type var;
//};

//enum MenuStates : pickState, basic attack, 



//reasons for keeping menuitem...
//-it's simple
//-it works totaly fine
//
//
//

//reasons for deleting MenuItem
//-it's barely anything more than sf::text (put it in with menu)
//-it's bloating the filelist
//