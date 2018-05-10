//
//  AbilityMenuItem.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "AbilityOption.hpp"


AbilityOption::AbilityOption(Ability abil, const sf::Font& font, std::function<void()> callback)
	: MenuOption(abil.getName(), nullptr, font, callback), ability(abil) {
	//determine if conditions for selection are met, and set selectability bool.
		abilityDesc.setString(abilt);
}

void AbilityOption::draw(sf::RenderWindow& rw) {
	ability.draw(rw);
	//rw.draw(text);
	ability.drawDesc(rw);
}
