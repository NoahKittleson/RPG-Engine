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
    BattleMode(std::vector<Character*>& enemies);
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
    IterVector<Character*> combatants;
    IterVector<Character*> targetSelectVec;
    //std::vector<Character>::iterator currentChar { enemyVec.begin() };
    Ability* chosenAbil {nullptr};
    Character* chosenTarget {nullptr};
    Mode Choice = Mode::StartChoice;
    
    void nextMenu(Ability&);
    void nextMenu(MenuOption&);
    void nextMenu(Character*);
    void previousMenu();
    void positionStats();
    
    IterVector<MenuOption> StartOptions;           //messy...

    template <typename Item>
    void scroll(sf::Event &event, IterVector<Item> &list);
    
};


//////////////Definitions for Template Functions//////////////
template <typename Item>
void BattleMode::scroll(sf::Event &event, IterVector<Item> &list) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
        ++list;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
        --list;
    }        
    if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::X || event.key.code == sf::Keyboard::Return)) {
        nextMenu(list.get());
    }
    if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::Slash)) {
        previousMenu();
    }
}


