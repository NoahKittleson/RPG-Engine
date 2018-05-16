//
//  AbilityMenuItem.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MenuOption.hpp"
#include "Ability.hpp"
#include "Character.h"

class AbilityOption : public MenuOption
{
public:
	AbilityOption(Ability, const sf::Font& font, std::shared_ptr<Character> actor, std::function<void()> callback = nullptr);
	
	void draw(sf::RenderWindow& rw) override;

	
private:
	Ability ability;
};
