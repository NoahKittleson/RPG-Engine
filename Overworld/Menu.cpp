//
//  MenuContainer.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "Menu.hpp"
#include "MenuItem.hpp"

void Menu::draw(sf::RenderWindow &rw) {
	if (children.get().getNext() && children.get().getNext()->isActive()) {
		children.get().getNext()->draw(rw);
	} else {
		for (int iii = 0; iii < children.size(); iii++) {
			children[iii].draw(rw);
		}
	}
}

void Menu::update(float elapsed) {
	if (children.get().getNext() && children.get().getNext()->isActive()) {
		children.get().getNext()->update(elapsed);
	} else {
		//maybe some flicker on selected option?
		//continue animation
	}
}

void Menu::activate() {
	active = true;
}

void Menu::handleInput(sf::RenderWindow& rw) {
	if (children.get().getNext() && children.get().getNext()->isActive()) {
		children.get().getNext()->handleInput(rw);
	} else {
		sf::Event event;
		while (rw.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
					case sf::Keyboard::X:
						if(children.get().getNext()) {
							children.get().getNext()->activate();
						}
						children.get().activate();
						break;
						
					case sf::Keyboard::Z:
						active = false;
						break;
						
					case sf::Keyboard::Up:
						children.get().deselect();
						--children;
						children.get().select();
						break;
						
					case sf::Keyboard::Down:
						children.get().deselect();
						++children;
						children.get().select();
						break;
						
					default:
						break;
				}
			}
		}
	}
}

void Menu::addChild(MenuItem item) {
	std::cout << "item: " << item.getName() << "\n";
	children.push_back(item);
	if (children.size() == 1) {
		children[0].select();
	}
	children.back().setPosition(100, 100+children.size()*50);
}

bool Menu::isDone() const {
	if (children.get().getNext() && children.get().getNext()->isActive()) {
		return children.get().getNext()->isDone();
	} else {
		return children.get().getNext();
	}
}

