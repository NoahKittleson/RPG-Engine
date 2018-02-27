//
//  BattleState.h
//  Overworld
//
//  Created by Noah Kittleson on 12/31/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "State.h"
#include "Mode.hpp"
#include "MenuMode.hpp"
#include "AttackMode.hpp"
#include "BattleInfo.hpp"

class BattleState : public State
{
public:
	BattleState(std::vector<std::shared_ptr<Character>>&& enemies);
	void update(sf::Clock& timer) override;
	void draw(sf::RenderWindow&) override;
	void handleInput(sf::RenderWindow& rw) override;
	
private:
	std::unique_ptr<Mode> mode;
	enum ModeType {menu, attack};
	ModeType currentMode;
	BattleInfo info;
	void loadMenu();
	void drawAll(sf::RenderWindow &rw);
};

//class BattleState : public State
//{
//public:
//	BattleState(std::vector<std::shared_ptr<Character>>&& enemies);
//	~BattleState();
//	void update(sf::Clock& timer) override;
//	void draw(sf::RenderWindow&) override;
//	void handleInput(sf::RenderWindow& rw) override;
//
//private:
//	std::unique_ptr<Mode> mode;
//
//
//	//void runChoice(sf::RenderWindow &rw, float elapsed /*input*/);
//	//void nextTurn();
//	void drawAll(sf::RenderWindow& rw);
//
//	//void animateAndDraw(sf::RenderWindow &rw, float elapsed);
//	//float calculateDmg();
//
//	//void updateSprites(float elapsed);
//	//enum class Mode { StartChoice, PickAbility, PickTarget, Animating };
//	IterVector<std::shared_ptr<Character>> combatants;
//	std::vector<std::shared_ptr<Character>>::iterator currentCombatant = combatants.begin();
//
//	//std::vector<std::shared_ptr<Character>>::iterator selectedTarget = combatants.begin();
//	//Ability* chosenAbil {nullptr};
//	//std::shared_ptr<Character> chosenTarget {nullptr};
//	//Mode Choice = Mode::StartChoice;
//
//	//void nextMenu(Ability&);
//	//void nextMenu(MenuOption&);
//	//void nextMenu(std::shared_ptr<Character>);
//	void previousMenu();
//	//void positionStats();
//
//	IterVector<MenuOption> StartOptions;           //messy...
//
//	template <typename Item>
//	void scroll(sf::Event &event, IterVector<Item> &list);
//
//};
//
//
////////////////Definitions for Template Functions//////////////
//template <typename Item>
//void BattleState::scroll(sf::Event &event, IterVector<Item> &list) {
//	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
//		++list;
//	}
//	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
//		--list;
//	}
//	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::X || event.key.code == sf::Keyboard::Return)) {
//		nextMenu(list.get());
//	}
//	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::Slash)) {
//		previousMenu();
//	}
//}
//
//
//
