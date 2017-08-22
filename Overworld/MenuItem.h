//
//  MenuItem.h
//  SFML test
//
//  Created by Noah Kittleson on 1/11/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "Character.h"

class MenuItem
{
public:
    enum Action {Attack, Ability, Recover, Nothing, Crash};
    
    MenuItem(std::string, const sf::Font&, Action, sf::Vector2f);
    void draw(sf::RenderWindow &rw);
    void setPosition(float x, float y);
    void setColor(sf::Color color);
    
    Action _action;
    sf::Text _name;
    
private:
    MenuItem();
	
};

class NewMenuItem
{
public:
	NewMenuItem(const sf::Font& font, std::string string)
	{
		text.setString(string);
		text.setFont(font);
	};
	
	virtual void draw(sf::RenderWindow &rw) = 0;
	virtual void update(float elapsed) = 0;
	virtual void handleInput(sf::RenderWindow& rw) = 0;
	virtual void select() = 0;						//select is for highlighting current option, activate for executing it
	virtual void activate() = 0;
	virtual void deselect() = 0;
	virtual void deactivate() = 0;
	virtual bool selectable() = 0;
	bool isSelected() const {return selected;};
	bool isActive() const {return active;};
	
protected:
	sf::Text text;
	bool selected = false;
	bool active = false;
	
	//define color Types across all MenuItems
	const sf::Color selectColor = sf::Color::Red;
	const sf::Color defaultColor = sf::Color::Black;
	const sf::Color unselectableColor = sf::Color(128,128,128);

	
};
//
//class MenuItemContainer : public NewMenuItem {
//public:
//	MenuItemContainer(const sf::Font& font, std::string string)
//	: NewMenuItem(font, string)
//	{
//		text.setFont(font);
//		text.setString(string);
//	};
//	
//	void draw(sf::RenderWindow &rw) override {
//		rw.draw(text);
//		//draw selected marker?
//	}
//	
//	void update(float elapsed) override {
//		//nothing yet?
//	}
//	
//	void handleInput(sf::RenderWindow& rw) override {
//		if (options.get().isActive()) {
//			options.get().handleInput(rw);
//		}
//			
//		sf::Event event;
//		while (rw.pollEvent(event)) {
//			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
//				options.get().deselect();
//				++options;
//				options.get().select();
//			}
//			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
//				options.get().deselect();
//				--options;
//				options.get().select();
//			}
//			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
//				options.get().activate();
//			}
//		}
//	}
//	
//	void deselect() override {
//		selected = false;
//		if (selectable()) {
//			text.setColor(defaultColor);
//		} else {
//			text.setColor(unselectableColor);
//		}
//	}
//	
//	bool selectable() override {
//		return true;
//	}
//	
//	void select() override {
//		selected = true;
//		text.setColor(selectColor);
//	}
//	
//	void activate() override {
//		active = true;
//	}
//	
//	void deactivate() override {
//		active = false;
//	}
//	
//private:
//	IterVector<NewMenuItem> options;
//};

//#include "Ability.h"

using MenuPtr = std::unique_ptr<NewMenuItem>;

class AbilityMenuItem : public NewMenuItem {
public:
	AbilityMenuItem(const sf::Font& font, std::string string, const Ability& ability, Character& character)
	: NewMenuItem(font, string), ability(ability), character(&character)
	{
		text.setString(ability.getName());
	}
	
	AbilityMenuItem(const sf::Font& font, Ability& abil, IterVector<Character>& combatants)
	: NewMenuItem(font, abil.getName()), ability(abil), character(&combatants.get())
	{

	}
	
	virtual void draw(sf::RenderWindow &rw) override {
		rw.draw(text);
	}
	
	virtual void update(float elapsed) override {
		//nothing yet
	}
	
	void handleInput(sf::RenderWindow& rw) override {
		//I don't think handleInput should ever be called for this type of menu
		if (options.get().isActive()) {
			options.get().handleInput(rw);
		}
		
		sf::Event event;
		while (rw.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
				options.get().deselect();
				++options;
				options.get().select();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
				options.get().deselect();
				--options;
				options.get().select();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
				options.get().activate();
			}
		}
	}
	
	void deselect() override {
		selected = false;
		if (selectable()) {
			text.setColor(defaultColor);
		} else {
			text.setColor(unselectableColor);
		}
	}
	
	bool selectable() override {
		return character->CheckAbilityCost(ability);
	}
	
	void select() override {
		selected = true;
		text.setColor(selectColor);
	}
	
	void activate() override {
		//create next series of MenuOptions into a vector
		active = true;
		for (auto & it : combatants) {
			options.emplace_back(std::unique_ptr<MenuItem>(new CharacterMenuItem(text.getFont(), it, combatants)));
		}
	}
	
	void deactivate() override {
		active = false;
		options.clear();
	}
	
	
private:
	const Ability& ability;
	Character* character;
	
	IterVector<MenuPtr> options;
	IterVector<Character> combatants;
};





//what if I made Characters and Abilities inherit directly from NewMenuItem?

