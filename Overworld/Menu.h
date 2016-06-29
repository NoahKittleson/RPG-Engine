//
//  Menu.h
//  SFML test
//
//  Created by Noah Kittleson on 1/11/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "Ability.h"
#include "Character.h"


class OptionInterface
{
public:
    virtual void draw(sf::RenderWindow &rw) = delete;
    virtual void get() = delete;
};


class Menu
{
public:        
    template <typename ItemIterator, typename ItemVec>
    void scroll(sf::Event& event, ItemIterator& it, ItemVec& vec);
    
protected:
    void DrawAll(sf::RenderWindow &rw, std::vector<OptionInterface*> &vec);
};




//////////////////DEFINITIONS FOR TEMPLATE FUNCTIONS/////////////////////////////
template <typename ItemIterator, typename ItemList>
void Menu::scroll(sf::Event &event, ItemIterator &it, ItemList &list)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
        it++;
        if (it == list.end()) {
            it = list.begin();
        }
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
        if (it == list.begin()) {
            it = list.end();
        }
        it--;
    }
}