//
//  BattleState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 12/31/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "BattleState.h"

//This moves passed enemyVec.  Change if this is a problem
BattleState::BattleState(std::vector<std::shared_ptr<Character>>&& enemies)
{
    for (auto && it : party) {
        info.combatants.push_back(it);
    }
    for (auto && it : enemies) {
		info.combatants.emplace_back(std::move(it));
    }
	info.currentAction.attacker = info.combatants[0];
	info.NPCs = std::move(enemies);
	info.PCs = party;
	mode = make_unique<MenuMode>(info, resources.getFont(Fonts::Sansation));
	
    info.combatants.setLooping(true);
    //positionStats();
}

void BattleState::update(sf::Clock& timer)
{
    float elapsed = timer.restart().asSeconds();
	if (mode) {
		mode->update(elapsed);
	}
	//updateSprites(elapsed);
	if (mode->isDone()) {
		switch (currentMode) {
			case menu:
				mode = make_unique<AttackMode>(info);
				//mode.reset(make_unique<AttackMode>(info));
				break;
				
			case attack:
				++info.combatants;
				info.clear();
				info.currentAction.attacker = info.combatants.get();
				mode = make_unique<MenuMode>(info, resources.getFont(Fonts::Sansation));
				break;
				
			default:
				std::cout << "Mode unaccounted for.\n";
				break;
		}
	}
}

void BattleState::draw(sf::RenderWindow& rw) {
	rw.setView(rw.getDefaultView());
	rw.clear(sf::Color::White);
	drawAll(rw);
	if (mode) {
		mode->draw(rw);
	} else {
		//anything?
	}
    rw.display();
}

void BattleState::handleInput(sf::RenderWindow& rw) {
	if (mode) {
		mode->handleInput(rw);
	} else {
		sf::Event event;
		while (rw.pollEvent(event)) {
			//nothing
		}
	}
}

void BattleState::drawAll(sf::RenderWindow &rw)
{
	for (auto && it: info.combatants) {
		it->drawAllStats(rw);
		it->drawSprite(rw);
	}
}

//void BattleState::updateSprites(float elapsed) {
//    for (auto && it: combatants) {
//        it->animate(elapsed);
//    }
//}
//
//void BattleState::runChoice(sf::RenderWindow rw, float felapsed)
//{
//    if (combatants.get()->_NPC) {
//        //run AI logic...
//    }
//    sf::Event event;
//    switch (Choice) {
//        case Mode::StartChoice:
//            while (rw.pollEvent(event)) {
//                StartOptions.get().setColor(sf::Color::Black);
//                scroll(event, StartOptions);
//                StartOptions.get().setColor(sf::Color::Red);
//            }
//            for (auto && it: StartOptions) {
//                it.draw(rw);
//            }
//            break;
//
//        case Mode::PickAbility:
//            while (rw.pollEvent(event)) {
//                combatants.get()->_abilityList.get().setColor(sf::Color::Black);
//                scroll(event, combatants.get()->_abilityList);
//                combatants.get()->_abilityList.get().setColor(sf::Color::Red);
//            }
//            for (auto && it: combatants.get()->_abilityList) {
//                it.draw(rw);
//            }
//            combatants.get()->_abilityList.get().drawDesc(rw);
//            break;
//
//        case Mode::PickTarget: {
//            //if I want to have special behavior for the target scroll (i.e. scrolling over enemies) just define another scroll();
//            while (rw.pollEvent(event)) {
//                targetSelectVec.get()->setColor(sf::Color::Black);
//                scroll(event, targetSelectVec);
//                targetSelectVec.get()->setColor(sf::Color::Red);
//            }
//            break;
//        }
//        case Mode::Animating:
//            animateAndDraw(rw, elapsed);
//            nextTurn();
//            break;
//
//        default:
//            break;
//    }
//}
//
//void BattleState::previousMenu()
//{
//    if (Choice == Mode::StartChoice || Choice == Mode::Animating) {
//        return;
//    }
//    if (Choice == Mode::PickAbility) {
//        Choice = Mode::StartChoice;
//    }
//    else if (chosenAbil != &combatants.get()->_basicAttack) {
//        Choice = Mode::PickAbility;
//
//    }
//    else Choice = Mode::StartChoice;
//}
//
//void BattleState::nextMenu(Ability& abil)
//{
//    abil.setColor(sf::Color::Black);
//    Choice = Mode::PickTarget;
//    chosenAbil = &abil;
//}
//
//void BattleState::nextMenu(std::shared_ptr<Character> target)
//{
//    Choice = Mode::Animating;
//    chosenTarget = target;
//}
//
//void BattleState::nextMenu(MenuOption& item)            //this is less weak...
//{
//    auto type = item.Option;
//    if (type == MenuOption::Attack) {
//        chosenAbil = &combatants.get()->_basicAttack;
//        Choice = Mode::PickTarget;
//    }
//    if (type == MenuOption::Ability) {
//        if (combatants.get()->_abilityList.empty()) {
//            return;
//        }
//        combatants.get()->_abilityList.begin()->setColor(sf::Color::Red);
//        Choice = Mode::PickAbility;
//    }
//    if (type == MenuOption::Recovery) {
//        chosenAbil = &combatants.get()->_basicAttack;
//        chosenTarget = combatants.get();
//        Choice = Mode::Animating;
//    }
//    if (type == MenuOption::Crash) {
//        assert(false);
//    }
//}
//
//void BattleState::animateAndDraw(sf::RenderWindow &rw, float elapsed)
//{
//    chosenTarget->takeDamage(*chosenAbil, *combatants.get());
//    //this is gonna be the really hard one
//    //Animate battle
//}
//
//void BattleState::nextTurn(){
//    do ++combatants; while (combatants.get()->getHealth() == 0);
//    Choice = Mode::StartChoice;
//
//}
//
//void BattleState::positionStats() {
//    int statBarWidth = 1024 / (combatants.size() + 1);             //magic number!! Also I add +1 for padding on both sides
//    int iii = 0;
//    for (auto && it: combatants) {
//        it->setSpritePosition(statBarWidth/2 + (statBarWidth * iii), 300);
//        it->setStatPosition(statBarWidth/2 + (statBarWidth * iii), 300);
//        iii++;
//    }
//}
//
//void BattleState::drawAll(sf::RenderWindow &rw)
//{
//    for (auto && it: combatants) {
//        it->drawAllStats(rw);
//        it->drawSprite(rw);
//    }
//}
//
//
//
////MOVE THESE TO THEIR OWN FILE//
//MenuOption::MenuOption(const sf::Font& font, std::string name, OptionType type)
//: Option(type)
//{
//    display.setFont(font);
//    display.setString(name);
//    display.setColor(sf::Color::Black);
//}
//
//void MenuOption::setPosition(float x, float y)
//{
//    display.setPosition(x, y);
//}
//
//void MenuOption::setColor(sf::Color color)
//{
//    display.setColor(color);
//}
//
//void MenuOption::draw(sf::RenderWindow &rw)
//{
//    rw.draw(display);
//}










