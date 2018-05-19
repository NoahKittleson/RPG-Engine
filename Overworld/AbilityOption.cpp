//
//  AbilityMenuItem.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "AbilityOption.hpp"


AbilityOption::AbilityOption(Ability abil, const sf::Font& font, std::shared_ptr<Character> actor, std::function<void()> callback)
	: MenuOption(abil.getName(), font, callback), ability(abil)
{
	//determine if conditions for selection are met, and set possibility bool.
	setPossible(actor->checkAbilityCost(ability));
	optionName.setString(ability.getName());
	optionName.setFont(font);
	optionName.setPosition(100, 100);
	optionName.setColor(sf::Color::Black);
}

void AbilityOption::draw(sf::RenderWindow& rw) {
//	ability.draw(rw);
	rw.draw(optionName);
	if (isSelected()) {
		ability.drawDesc(rw);
	}
}


