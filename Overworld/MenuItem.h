//
//  MenuItem.h
//  SFML test
//
//  Created by Noah Kittleson on 1/11/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

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

class MenuItemContainer : public NewMenuItem {
public:
	MenuItemContainer(const sf::Font& font, std::string string)
	: NewMenuItem(font, string)
	{
		
	};
	
	void draw(sf::RenderWindow &rw) override {
		rw.draw(text);
		//draw selected marker?
	}
	
	void update(float elapsed) override {
		//nothing yet?
	}
	
	void handleInput(sf::RenderWindow& rw) override {
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
		return true;
	}
	
	void select() override {
		selected = true;
		text.setColor(selectColor);
	}
	
	void activate() override {
		active = true;
	}
	
	void deactivate() override {
		active = false;
	}
	
private:
	IterVector<NewMenuItem> options;
};

#include "Ability.h"

class AbilityMenuItem : public NewMenuItem {
public:
	AbilityMenuItem(const sf::Font& font, std::string string, const Ability& ability)
	: NewMenuItem(font, string), ability(ability)
	{
		text.setString(ability.getName());
	}
	
	virtual void draw(sf::RenderWindow &rw) override {
		rw.draw(text);
	}
	
	virtual void update(float elapsed) override {
		//nothing yet
	}
	
	void handleInput(sf::RenderWindow& rw) override {
		//I don't think handleInput should ever be called for this type of menu
		return;
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
		//this is the tricky one
		return character->meetsRequirement(ability);
	}
	
	void select() override {
		selected = true;
		text.setColor(selectColor);
	}
	
	void activate() override {
		active = true;
	}
	
	void deactivate() override {
		active = false;
	}
	
	
private:
	const Ability& ability;
	
	
};


