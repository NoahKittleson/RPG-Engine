//
//  Menu.cpp
//  SFML test
//
//  Created by Noah Kittleson on 1/11/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "Menu.h"


void Menu::DrawAll(sf::RenderWindow &rw, std::list<MenuItem> &list)
{
    for (std::list<MenuItem>::iterator otherit = list.begin(); otherit != list.end(); otherit++)
    {
        otherit->draw(rw);
    }
}

//template <typename ItemIterator, typename ItemList>
/*void Menu::scroll(sf::Event& event, ItemIterator& it, ItemList& list)
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

template <typename T>
void Menu::scrollTwo(sf::Event &event, typename std::list<T>::iterator it, typename std::list<T> list)
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
}*/

/*void Menu::GetResponse(sf::Event& event, std::list<MenuItem> &OptionsList, std::list<MenuItem>::iterator &it)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
    {
        (*it).setColor(sf::Color::Black);
        it++;
        if (it == OptionsList.end())
        {
            it = OptionsList.begin();
        }
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
    {
        (*it).setColor(sf::Color::Black);
        if (it == OptionsList.begin())
        {
            it = OptionsList.end();
        }
        it--;
    }
    (*it).setColor(sf::Color::Red);
}


//I might want to put the event loop inside this block purely because of closewindow events...

void Menu::GetResponse(sf::Event& event, std::list<Ability> &OptionsList, std::list<Ability>::iterator &it)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
    {
        //if abilitydesc is black, make text black, otherwise make it gray.
        if (it->isGrayedOut()) {
            (*it).setColor(sf::Color(128,128,128));
        }
        else (*it).setColor(sf::Color::Black);
        it++;
        if (it == OptionsList.end())
        {
            it = OptionsList.begin();
        }
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
    {
        if (it->isGrayedOut()) {
            (*it).setColor(sf::Color(128,128,128));
        }
        else (*it).setColor(sf::Color::Black);
        if (it == OptionsList.begin())
        {
            it = OptionsList.end();
            
        }
        it--;
    }
    (*it).setColor(sf::Color::Red);
}

void Menu::GetResponse(sf::Event& event, std::list<Character*>& OptionsList, std::list<Character*>::iterator& it)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
    {
        it++;
        if (it == OptionsList.end())
        {
            it = OptionsList.begin();
        }
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
    {
        if (it == OptionsList.begin())
        {
            it = OptionsList.end();
        }
        it--;
    }
}*/









