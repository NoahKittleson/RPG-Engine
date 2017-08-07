//
//  BattleMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 12/31/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "BattleMode.h"

//This copies passed enemyVec.  Change if this is a problem
BattleMode::BattleMode(std::vector<std::shared_ptr<Character>>&& enemies) : StartOptions(true)
{
	StartOptions.emplace_back(resources.getFont(Fonts::Sansation), "Attack", MenuOption::Attack);
    StartOptions.emplace_back(resources.getFont(Fonts::Sansation), "Ability", MenuOption::Ability);
    StartOptions.emplace_back(resources.getFont(Fonts::Sansation), "Recovery", MenuOption::Recovery);
    StartOptions.emplace_back(resources.getFont(Fonts::Sansation), "Crash Game", MenuOption::Crash);
    
    for (int iii = 0; iii < StartOptions.size(); ++iii) {
        StartOptions[iii].setPosition(100, 40 * iii);
    }
	
    for (auto && it : party) {
        combatants.emplace_back(&it);
    }
    for (auto && it : enemies) {
		combatants.emplace_back(std::move(it));
    }
    StartOptions.get().setColor(sf::Color::Red);
    combatants.setLooping(true);
    targetSelectVec = combatants;
    positionStats();
}

BattleMode::~BattleMode() {
    //All characters are dynamically allocated
    for (auto && it : combatants) {
        if (it->_NPC) {
            //delete it;
        }
    }
}

void BattleMode::update(sf::RenderWindow& rw, sf::Clock& timer)
{
    rw.setView(rw.getDefaultView());
    float elapsed = timer.restart().asSeconds();
    rw.clear(sf::Color::White);
    runChoice(rw, elapsed);
}

void BattleMode::draw(sf::RenderWindow& rw)
{
    drawAll(rw);
    rw.display();
}

void BattleMode::handleEvent()
{
	return;
}

void BattleMode::updateSprites(float elapsed) {
    for (auto && it: combatants) {
        it->animate(elapsed);
    }
}

void BattleMode::runChoice(sf::RenderWindow &rw, float elapsed)
{
    if (combatants.get()->_NPC) {
        //run AI logic...
    }
    sf::Event event;
    switch (Choice) {
        case Mode::StartChoice:
            while (rw.pollEvent(event)) {
                StartOptions.get().setColor(sf::Color::Black);
                scroll(event, StartOptions);
                StartOptions.get().setColor(sf::Color::Red);
            }
            for (auto && it: StartOptions) {
                it.draw(rw);
            }
            break;
            
        case Mode::PickAbility:
            while (rw.pollEvent(event)) {
                combatants.get()->_abilityList.get().setColor(sf::Color::Black);
                scroll(event, combatants.get()->_abilityList);
                combatants.get()->_abilityList.get().setColor(sf::Color::Red);
            }
            for (auto && it: combatants.get()->_abilityList) {
                it.draw(rw);
            }
            combatants.get()->_abilityList.get().drawDesc(rw);
            break;
            
        case Mode::PickTarget: {
            //if I want to have special behavior for the target scroll (i.e. scrolling over enemies) just define another scroll();
            while (rw.pollEvent(event)) {
                targetSelectVec.get()->setColor(sf::Color::Black);
                scroll(event, targetSelectVec);
                targetSelectVec.get()->setColor(sf::Color::Red);
            }
            break;
        }
        case Mode::Animating:
            animateAndDraw(rw, elapsed);
            nextTurn();
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
    else if (chosenAbil != &combatants.get()->_basicAttack) {
        Choice = Mode::PickAbility;
        
    }
    else Choice = Mode::StartChoice;
}

void BattleMode::nextMenu(Ability& abil)
{
    abil.setColor(sf::Color::Black);
    Choice = Mode::PickTarget;
    chosenAbil = &abil;
}

void BattleMode::nextMenu(std::shared_ptr<Character> target)
{
    Choice = Mode::Animating;
    chosenTarget = target;
}

void BattleMode::nextMenu(MenuOption& item)            //this is less weak...
{
    auto type = item.Option;
    if (type == MenuOption::Attack) {
        chosenAbil = &combatants.get()->_basicAttack;
        Choice = Mode::PickTarget;
    }
    if (type == MenuOption::Ability) {
        if (combatants.get()->_abilityList.empty()) {
            return;
        }
        combatants.get()->_abilityList.begin()->setColor(sf::Color::Red);
        Choice = Mode::PickAbility;
    }
    if (type == MenuOption::Recovery) {
        chosenAbil = &combatants.get()->_basicAttack;
        chosenTarget = combatants.get();
        Choice = Mode::Animating;
    }
    if (type == MenuOption::Crash) {
        assert(false);
    }
}

void BattleMode::animateAndDraw(sf::RenderWindow &rw, float elapsed)
{
    chosenTarget->takeDamage(*chosenAbil, *combatants.get());
    //this is gonna be the really hard one
    //Animate battle
}

void BattleMode::nextTurn(){
    do ++combatants; while (combatants.get()->getHealth() == 0);
    Choice = Mode::StartChoice;
    
}

void BattleMode::positionStats() {
    int statBarWidth = 1024 / (combatants.size() + 1);             //magic number!! Also I add +1 for padding on both sides
    int iii = 0;
    for (auto && it: combatants) {
        it->setSpritePosition(statBarWidth/2 + (statBarWidth * iii), 300);
        it->setStatPosition(statBarWidth/2 + (statBarWidth * iii), 300);
        iii++;
    }
}

void BattleMode::drawAll(sf::RenderWindow &rw)
{
    for (auto && it: combatants) {
        it->drawAllStats(rw);
        it->drawSprite(rw);
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










