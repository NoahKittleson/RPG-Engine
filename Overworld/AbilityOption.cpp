//
//  AbilityMenuItem.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "AbilityOption.hpp"


AbilityOption::AbilityOption(Ability abil, const sf::Font& font) : MenuOption(abil.getName(), nullptr, font) {
	
}

AbilityOption::AbilityOption(Ability, const sf::Font& font, std::function<void()> callback)  : MenuOption(abil.getName(), nullptr, font, callback) {
	
}
