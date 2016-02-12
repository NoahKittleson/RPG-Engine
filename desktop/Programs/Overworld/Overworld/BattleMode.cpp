//
//  BattleMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 12/31/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "BattleMode.h"


BattleMode::BattleMode(std::list<Character> enemies)
{
    //merge enemies and allies into combatants list;
    combatants = std::move(enemies);

    //add allies to list as well
    //this only adds COPIES.  I need REFERENCES OR POINTERS
    for (auto && it: party) {
        //it.setFont(resources.getFont("sansation.ttf"));
        combatants.push_back(it);
    }
    for (auto && it: combatants) {
        it.setFont(resources.getFont("sansation.ttf"));
    }
    
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Attack", MenuOption::Attack);
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Ability", MenuOption::Ability);
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Recovery", MenuOption::Recovery);
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Crash Game", MenuOption::Crash);
}

void BattleMode::update(sf::RenderWindow &rw, sf::Clock &timer)
{
    rw.setView(rw.getDefaultView());
    float elapsed = timer.restart().asSeconds();
    rw.clear(sf::Color::White);
    runChoice(rw, elapsed);
    drawAll(rw, elapsed);
    rw.display();
}

void BattleMode::runChoice(sf::RenderWindow &rw, float elapsed)
{
    switch (Choice) {
        case Mode::StartChoice:
            scrollAndDisplay(rw, StartOptions);
            break;
            
        case Mode::PickAbility:
            scrollAndDisplay(rw, currentChar->_abilityList);
            break;
            
        case Mode::PickTarget: {
            sf::Event event;
            std::list<Character>::iterator iter = combatants.begin();
            while (rw.pollEvent(event)) {
                scroll(event, iter, combatants);
            }
            break;
        }
        case Mode::Animating:
            Animate(rw, elapsed);
            break;
            
        default:
            break;
    }
}

void BattleMode::previousMenu()
{
    if (!chosenAbil || Choice == Mode::Animating) {
        return;
    }
    if (chosenAbil != &currentChar->_basicAttack) {
        Choice = Mode::PickAbility;
    }
    else Choice = Mode::StartChoice;
}

void BattleMode::nextMenu(Ability& abil)
{
    Choice = Mode::PickTarget;
    chosenAbil = &abil;
}

void BattleMode::nextMenu(Character &target)
{
    Choice = Mode::Animating;
    chosenTarget = &target;
}

void BattleMode::nextMenu(MenuOption& item)            //this is less weak...
{
    auto type = item.Option;
    if (type == MenuOption::Attack) {
        chosenAbil = &currentChar->_basicAttack;
        Choice = Mode::PickTarget;
    }
    if (type == MenuOption::Ability) {
        if (currentChar->_abilityList.empty()) {
            return;
        }
        Choice = Mode::PickAbility;
    }
    if (type == MenuOption::Recovery) {
        chosenAbil = &currentChar->_basicAttack;
        chosenTarget = &(*currentChar);
        Choice = Mode::Animating;
    }
    if (type == MenuOption::Crash) {
        assert(false);
    }
}

void BattleMode::Animate(sf::RenderWindow &rw, float elapsed)
{
    chosenTarget->takeDamage(*chosenAbil, *currentChar);
    currentChar++;
    Choice = Mode::StartChoice;
    //this is gonna be the really hard one
}

void BattleMode::drawAll(sf::RenderWindow &rw, float elapsed)
{
    for (auto && it: combatants) {
        it.setSpritePosition(200, 200);
        it.setStatPosition(200, 200);
        it.drawAllStats(rw);
        it.drawSprite(rw);
    }
}



//MOVE THESE TO THEIR OWN FILE//
MenuOption::MenuOption(const sf::Font& font, std::string name, OptionType type)
: Option(type)
{
    display.setFont(font);
    display.setString(name);
    display.setColor(sf::Color::Black);
}

void MenuOption::setPosition(float x, float y)
{
    display.setPosition(x, y);
}

void MenuOption::setColor(sf::Color color)
{
    display.setColor(color);
}

void MenuOption::draw(sf::RenderWindow &rw)
{
    rw.draw(display);
}










