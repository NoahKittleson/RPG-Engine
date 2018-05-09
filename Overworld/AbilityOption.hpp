//
//  AbilityMenuItem.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MenuOption.hpp"
#include "Ability.h"

class AbilityOption : public MenuOption
{
public:
	AbilityOption(Ability, const sf::Font& font);
	AbilityOption(Ability, const sf::Font& font, std::function<void()> callback);
	
	virtual void draw(sf::RenderWindow& rw) override;
	virtual void select() override;				//select is for highlighting current option, activate for executing it
	virtual void activate() override;
	virtual bool isActive() const override;
	virtual void deselect()override;
	virtual bool isSelectable()override;
	virtual Menu* getNext() const override { return nextMenu; };
	virtual void setSelect(bool selectable) override;
	
	void attachNext(std::shared_ptr<Menu> next);
}
