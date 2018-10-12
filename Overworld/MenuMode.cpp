//
//  MenuMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuMode.hpp"

MenuMode::MenuMode(BattleInfo& info, const sf::Font& font) : info(info)
{
	startMenu = std::make_shared<Menu>();
	std::shared_ptr<Menu> abilityMenu = std::make_shared<Menu>();
	std::shared_ptr<Menu> targetMenu = std::make_shared<Menu>();

	//set up Attack Option on Start Menu
	const Ability& autoAttack = info.currentAction.attacker->getBasicAttack();
	auto attackFunc = [&info, &autoAttack] () {
		info.currentAction.ability = &autoAttack;
	};
	auto attackOption = std::make_shared<MenuOption>("Attack", font, attackFunc);
	attackOption->attachNext(targetMenu);
	startMenu->addChild(attackOption);
	
	//set up Ability Option on Start Menu
	auto abilityOption = std::make_shared<MenuOption>("Ability", font);
	abilityOption->attachNext(abilityMenu);
	if (info.currentAction.attacker->getAbilityList().size() == 0) {
		abilityOption->setPossible(false);
	}
	startMenu->addChild(abilityOption);

	
	//set up Pass Option on Start Menu
	auto passOption = std::make_shared<MenuOption>("Pass", font);
	startMenu->addChild(passOption);
	
	//set up each option in Target Menu
	for (auto & target : info.combatants) {
		auto function = [&info, &target] () {
			info.currentAction.defenders.push_back(target);
		};
		auto targetOption = std::make_shared<MenuOption>(target->getName(), font, function);
		targetMenu->addChild(targetOption);
	}
	
	//set up each option in Ability Menu
	for (const auto & ability : info.currentAction.attacker->getAbilityList()) {
		auto function = [&info, &ability] () {
			info.currentAction.ability = &ability;
		};
		std::shared_ptr<MenuOption> addMe = std::make_shared<AbilityOption>(ability, font, info.combatants.get(), function);
		addMe->attachNext(targetMenu);
		abilityMenu->addChild(addMe);
	}
	startMenu->activate();
}

void MenuMode::update(float elapsed, State* context) {
	startMenu->update(elapsed, context, CommandVec);
	for (Command& command : CommandVec) {
		switch (command) {
			case Command::CursorUp:
			case Command::CursorDown:
				context->audioPlayer.playSound(SoundID::shine);
				break;
				
			case Command::Back:
				context->audioPlayer.playSound(SoundID::airdodge);
				break;
				
			case Command::Select:
				context->audioPlayer.playSound(SoundID::fox);
				break;
		}
	}
	if (info.currentAction.complete()) {
		done = true;
	}
	for (const auto & it : info.combatants) {
		it->animate(elapsed);
	}
}

void MenuMode::draw(sf::RenderWindow &rw) {
	startMenu->draw(rw);
}

void MenuMode::handleInput(sf::RenderWindow &rw) {
	if (info.combatants.get()->isNPC()) {
		info.combatants.get()->fillInAction(info);
		done = true;
		return;
	}
	CommandVec.clear();
	sf::Event event;
	while (rw.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::X:
					CommandVec.push_back(Command::Select);
					break;
					
				case sf::Keyboard::Z:
					CommandVec.push_back(Command::Back);
					break;
					
				case sf::Keyboard::Up:
				case sf::Keyboard::Right:
					CommandVec.push_back(Command::CursorUp);
					break;

				case sf::Keyboard::Down:
				case sf::Keyboard::Left:
					CommandVec.push_back(Command::CursorDown);
					break;

				default:
					//std::cout << "Hey, don't press that key.  It doesn't do anything.\n";
					break;
			}
		}
	}
}
