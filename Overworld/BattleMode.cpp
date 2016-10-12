//
//  BattleMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 12/31/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "BattleMode.h"

//This copies passed enemyVec.  Change if this is a problem
BattleMode::BattleMode(std::vector<Character>& enemies) : enemyVec(enemies), StartOptions(true)
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

//this actually doesn't make sense to turn ability list into an IterVector
void BattleMode::abilityScroll (sf::RenderWindow &rw, IterVector<Ability>& list){
    sf::Event event;
    while (rw.pollEvent(event)) {
        scroll(event, list);
    }
    list.get().drawDesc(rw);
    for (auto && it: list) {
        it.draw(rw);
    }
}

//void testFunc(sf::RenderWindow &rw, MenuOption option) {
//    option.draw(rw);
//}

void BattleMode::startMenuScroll(sf::RenderWindow &rw, IterVector<MenuOption> &list) {
    sf::Event event;
    while (rw.pollEvent(event)) {
        scroll(event, list);
    }
    for (auto && it: list) {
        it.draw(rw);
    }
    //Learn how binding might work on a latter date.  Not necessary for now.
    //using namespace std::placeholders;
    //auto drawFunc = std::bind (testFunc, &rw, _1);
    //list.forAll(&drawFunc);
}

template <typename ItemType>
void BattleMode::commonMenuScroll(sf::RenderWindow &rw, IterVector<ItemType>) {
    sf::Event event;
    while (rw.pollEvent(event)) {
        scroll(event, list);
    }
}

void BattleMode::runChoice(sf::RenderWindow &rw, float elapsed)
{
    if (currentChar->_NPC) {
        //run AI logic...
    }
    sf::Event event;
    switch (Choice) {
        case Mode::StartChoice:
            commonMenuScroll(rw, StartOptions);
            for (auto && it: StartOptions) {
                it.draw(rw);
            }
            break;
            
        case Mode::PickAbility:
            commonMenuScroll(rw, currentChar->_abilityList);
            for (auto && it: currentChar->_abilityList) {
                it.draw(rw);
            }
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
    if (Choice == Mode::StartChoice || Choice == Mode::Animating) {
        return;
    }
    if (Choice == Mode::PickAbility) {
        Choice = Mode::StartChoice;
    }
    else if (chosenAbil != &currentChar->_basicAttack) {
        Choice = Mode::PickAbility;
    }
    else Choice = Mode::StartChoice;
}

void BattleMode::nextMenu(Ability& abil)
{
    abil.setColor(sf::Color::Black);
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










