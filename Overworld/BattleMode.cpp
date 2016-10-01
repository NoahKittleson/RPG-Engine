//
//  BattleMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 12/31/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "BattleMode.h"

//This alters base enemyVec.  Change if this is a problem
BattleMode::BattleMode(std::vector<Character>& enemies) : enemyVec(enemies)
{
    //keep enemyVec and player party separate
    
    //create the enemies and party cause fuck me...
    party.emplace_back(500, 450, 75, resources.getTexture("BasicIdle.png"),
                             resources.getFont("sansation.ttf"), "Pringus", "CLASH", false,
                             resources.getTexture("GetHitAnimation.png"));
    party.back()._recoveryAbility.setProperties(Ability::Heal, 100);
    Ability ability1 ("BigPunch", "Makes a big punch", 100, false, false,
                      resources.getTexture("BadAttackAnimation.png"));
    ability1.setReq(Ability::ManaCost, 100);
    Ability ability2 ("SmallPunch", "Makes a smaller punch" , 50, false, false,
                      resources.getTexture("BadAttackAnimation.png"));
    ability2.setReq(Ability::ManaCost, 50);
    party.back().addAbility(ability1);
    party.back().addAbility(ability2);
    
    enemyVec.emplace_back(300, 100,  30, resources.getTexture("RollingWheat.png"),
                          resources.getFont("sansation.ttf"), "GrainMan", ".", true,
                          resources.getTexture("RollingWheat.png"));
    
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Attack", MenuOption::Attack);
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Ability", MenuOption::Ability);
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Recovery", MenuOption::Recovery);
    StartOptions.emplace_back(resources.getFont("sansation.ttf"), "Crash Game", MenuOption::Crash);
    
    currentChar = enemyVec.begin();
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
            scrollAndDisplay(rw, currentChar->_abilityList);
            break;
            
        case Mode::PickTarget: {
            sf::Event event;
            auto iter = enemyVec.begin();
            while (rw.pollEvent(event)) {
                scroll(event, iter, enemyVec, party);
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
    int iii = 0;
    for (auto && it: enemyVec) {
        it.setSpritePosition(200 + (200 * iii), 300);
        it.setStatPosition(200 + (200 * iii), 300);
        it.drawAllStats(rw);
        it.drawSprite(rw);
        iii++;
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










