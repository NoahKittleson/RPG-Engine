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
    
    std::cout << "ability list size: ";
    std::cout << party.back()._abilityList.size();
    std::cout << "\n";
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
            std::cout << "ability list size: ";
            std::cout << party.back()._abilityList.size();
            std::cout << "\n";
            scrollAndDisplay(rw, currentChar->_abilityList);
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
        std::cout << "ability list size: ";
        std::cout << party.back()._abilityList.size();
        std::cout << "\n";
        
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
    std::cout << "Attacker ability list size: " << currentChar->_abilityList.size() << "\n";
    std::cout << "Defender ability list size: " << chosenTarget->_abilityList.size() << "\n";
    
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










