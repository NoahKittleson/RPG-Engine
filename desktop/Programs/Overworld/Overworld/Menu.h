//
//  Menu.h
//  SFML test
//
//  Created by Noah Kittleson on 1/11/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "MenuItem.h"
#include "Ability.h"
#include "Character.h"

class Menu
{
public:    
    //void GetResponse(sf::Event&, std::list<MenuItem>&, std::list<MenuItem>::iterator &it);
    //void GetResponse(sf::Event&, std::list<Ability>&, std::list<Ability>::iterator &it);
    //void GetResponse(sf::Event&, std::list<Character*>&, std::list<Character*>::iterator &it);
    
    template <typename ItemIterator, typename ItemList>
    void scroll(sf::Event& event, ItemIterator& it, ItemList& list);
    
protected:
    void DrawAll(sf::RenderWindow &rw, std::list<MenuItem> &list);
};


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