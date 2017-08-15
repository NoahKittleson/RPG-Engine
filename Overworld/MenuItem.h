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
	NewMenuItem(const sf::Font& font, std::string&& string)
	{
		text.setString(string);
		text.setFont(font);
	};
	
	virtual void draw(sf::RenderWindow &rw) = 0;
	virtual void update(float elapsed) = 0;
	virtual void handleInput(sf::RenderWindow& rw);
	virtual void select() = 0;						//select is for highlighting current option, activate for executing it
	virtual void activate() = 0;
protected:
	sf::Text text;
	bool selected = false;
	bool active = false;
};

class MenuItemContainer : public NewMenuItem {
public:
	MenuItemContainer(const sf::Font& font, std::string&& string)
	: NewMenuItem(font, std::move(string))
	{
		
	};
	
	void draw(sf::RenderWindow &rw) {
		rw.draw(text);
		//draw selected marker?
	}
	
	void update(float elapsed){
		//nothing yet?
	}
	
	void handleInput(sf::RenderWindow& rw) {
		if (!active) {
			return;
		}
		sf::Event event;
		while (rw.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
				++options;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
				--options;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
				options.get().activate();
			}
		}
	}
	
private:
	IterVector<NewMenuItem> options;
};
