//
//  BattleMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 12/31/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "BattleMode.h"

//This copies passed enemyVec.  Change if this is a problem
BattleMode::BattleMode(std::vector<Character>& enemies) : enemyVec(enemies)
{
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Attack", MenuOption::Attack);
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Ability", MenuOption::Ability);
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Recovery", MenuOption::Recovery);
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Crash Game", MenuOption::Crash);
    
    currentChar = enemyVec.begin();
    StartOptions.begin()->setColor(sf::Color::Red);
    positionStats();
}

void BattleMode::update(sf::RenderWindow &rw, sf::Clock& timer)
{
    rw.setView(rw.getDefaultView());
    float elapsed = timer.restart().asSeconds();
    rw.clear(sf::Color::White);
    runChoice(rw, elapsed);
    drawAll(rw, elapsed);
    rw.display();
}

//non-template
void BattleMode::scrollAndDisplayMore (sf::RenderWindow &rw, std::list<Ability>& list)
{
    static std::list<Ability>::iterator itr { list.begin() };
    sf::Event event;
    while (rw.pollEvent(event)) {
        scroll(event, itr, list);
    }
    
    //std::cout << "S&D ability list size: " << list.size() << "\n";
    itr->drawDesc(rw);
    drawOptions(rw, list, sf::Vector2f(100,100));
}

void BattleMode::runChoice(sf::RenderWindow &rw, float elapsed)
{
    if (currentChar->_NPC) {
        //run AI logic...
    }
    
    switch (Choice) {
        case Mode::StartChoice:
            scrollAndDisplay(rw, StartOptions);
            break;
            
        case Mode::PickAbility:
            scrollAndDisplayMore(rw, currentChar->_abilityList);
            break;
            
        case Mode::PickTarget: {
            sf::Event event;
            static auto iter { chosenAbil->_allyPrimaryTarget ? party.begin() : enemyVec.begin() };
            while (rw.pollEvent(event)) {
                if (iter->_NPC) {
                    scroll(event, iter, enemyVec, party);
                } else {
                    scroll(event, iter, party, enemyVec);
                }
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
    chosenAbil->_allyPrimaryTarget ? party.begin()->setColor(sf::Color::Red) : enemyVec.begin()->setColor(sf::Color::Red);
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
        currentChar->_abilityList.begin()->setColor(sf::Color::Red);
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
    if (currentChar == enemyVec.end()) {
        currentChar = party.begin();
    } else if (currentChar == party.end()) {
        currentChar = enemyVec.begin();
    }
    Choice = Mode::StartChoice;
    //this is gonna be the really hard one
}

void BattleMode::positionStats() {
    char combatants = enemyVec.size() + party.size();
    int statBarWidth = 1024 / (combatants + 1);                   //magic number!! Also I add +1 for padding on both sides
    int iii = 0;
    for (auto && it: enemyVec) {
        it.setSpritePosition(statBarWidth/2 + (statBarWidth * iii), 300);
        it.setStatPosition(statBarWidth/2 + (statBarWidth * iii), 300);
        iii++;
    }
    for (auto && it: party) {
        it.setSpritePosition(statBarWidth/2 + (statBarWidth * iii), 300);
        it.setStatPosition(statBarWidth/2 + (statBarWidth * iii), 300);
        iii++;
    }
}

void BattleMode::drawAll(sf::RenderWindow &rw, float elapsed)
{
    for (auto && it: enemyVec) {
        it.animate(rw, elapsed);
        it.drawAllStats(rw);
        it.drawSprite(rw);
    }
    for (auto && it: party) {
        it.animate(rw, elapsed);
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










