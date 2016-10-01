//
//  BattleMode.h
//  Overworld
//
//  Created by Noah Kittleson on 12/31/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "State.h"

class MenuOption
{
public:
    enum OptionType{Attack, Recovery, Ability, Crash};
    OptionType Option;
    
    MenuOption(const sf::Font&, std::string, OptionType);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& rw);
    void setColor(sf::Color);
    
    
private:
    sf::Text display;
};


class BattleMode : public State
{
public:
    BattleMode(std::vector<Character>& enemies);
    void update(sf::RenderWindow&rw, sf::Clock& timer) override;
    //fill these next two out later....
    void draw(sf::RenderWindow&) override {};
    std::string handleEvent() override { return ""; };
    
private:
    void runChoice(sf::RenderWindow &rw, float elapsed /*input*/);
    void drawAll(sf::RenderWindow& rw, float elapsed);
    
    void Animate(sf::RenderWindow &rw, float elapsed);
    float calculateDmg();
    
    enum class Mode {StartChoice, PickAbility, PickTarget, Animating};
    std::vector<Character>& enemyVec;
    std::vector<Character>::iterator currentChar { enemyVec.begin() };
    Ability* chosenAbil {nullptr};
    Character* chosenTarget {nullptr};
    Mode Choice = Mode::StartChoice;
    
    void nextMenu(Ability&);
    void nextMenu(MenuOption&);
    void nextMenu(Character&);
    void previousMenu();
    
    std::list<MenuOption> StartOptions;           //messy...

    template <typename ListType>
    void scrollAndDisplay (sf::RenderWindow &rw, std::list<ListType>& list);
    
    template <typename ItemIterator, typename ItemList>
    void scroll(sf::Event &event, ItemIterator &it, ItemList &list);
    
    template <typename ItemIterator, typename ItemList>
    void scroll(sf::Event &event, ItemIterator &it, ItemList &list, ItemList &otherList);
    
    template <typename T>
    void drawOptions(sf::RenderWindow &rw, std::list<T> list, sf::Vector2f startPos);
    
};



//////////////Definitions for Template Fuctions////////////
template <typename ListType>
void BattleMode::scrollAndDisplay (sf::RenderWindow &rw, std::list<ListType>& list)
{
    static typename std::list<ListType>::iterator itr { list.begin() };
    sf::Event event;
    while (rw.pollEvent(event)) {
        scroll(event, itr, list);
    }
    drawOptions(rw, list, sf::Vector2f(100,100));
}

template <typename ItemIterator, typename ItemList>
void BattleMode::scroll(sf::Event &event, ItemIterator &it, ItemList &list)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
        it->setColor(sf::Color::Black);
        it++;
        if (it == list.end()) {
            it = list.begin();
        }
        it->setColor(sf::Color::Red);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
        it->setColor(sf::Color::Black);
        if (it == list.begin()) {
            it = list.end();
        }
        it--;
        it->setColor(sf::Color::Red);
    }
    if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::X || event.key.code == sf::Keyboard::Return)) {
        nextMenu(*it);
    }
    if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::Slash)) {
        previousMenu();
    }

}


template <typename ItemIterator, typename ItemList>
void BattleMode::scroll(sf::Event &event, ItemIterator &it, ItemList &list, ItemList &otherList) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
        it->setColor(sf::Color::Black);
        it++;
        if (it == list.end()) {
            it = list.begin();
        }
        it->setColor(sf::Color::Red);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
        it->setColor(sf::Color::Black);
        if (it == list.begin()) {
            it = list.end();
        }
        it--;
        it->setColor(sf::Color::Red);
    }
    if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Up)) {
        it->setColor(sf::Color::Black);
        int index = it - list.begin();
        if (index < otherList.size()) {
            it = otherList.begin() + index;
        } else {
           it = --otherList.end();
        }
        it->setColor(sf::Color::Red);
    }
    if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::X || event.key.code == sf::Keyboard::Return)) {
        nextMenu(*it);
    }
    if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::Slash)) {
        previousMenu();
    }
}

template <typename T>
void BattleMode::drawOptions(sf::RenderWindow &rw, std::list<T> list, sf::Vector2f startPos)
{
    for (auto && it: list) {
        it.setPosition(startPos.x, startPos.y);
        it.draw(rw);
        startPos.y += 30;               //!!ALERT: MAGIC NUMBER :ALERT!!
    }
}







