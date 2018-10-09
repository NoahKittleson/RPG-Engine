//
//  MenuContainer.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "Menu.hpp"
#include "MenuOption.hpp"

void Menu::draw(sf::RenderWindow &rw) {
	if (children.get()->getNext() && children.get()->getNext()->isActive()) {
		children.get()->getNext()->draw(rw);
	} else {
		if (!children.size()) {
			std::cout << "nothing to draw\n";
			return;
		}
		for (int iii = 0; iii < children.size(); iii++) {
			children[iii]->draw(rw);
		}
	}
}

void Menu::update(float elapsed, std::vector<Command> commandVec) {
	if (children.get()->getNext() && children.get()->getNext()->isActive()) {
		children.get()->getNext()->update(elapsed, commandVec);
	} else {
		for (Command& command : commandVec) {
			switch (command) {
				case Command::Select:
					if (children.get()->isSelectable()) {
						if(children.get()->getNext()) {
							children.get()->getNext()->activate();
						} else done = true;
						children.get()->activate();
					}
					break;
					
				case Command::Back:
					active = false;
					break;
					
				case Command::CursorUp:
					children.get()->deselect();
					--children;
					children.get()->select();
					break;
					
				case Command::CursorDown:
					children.get()->deselect();
					++children;
					children.get()->select();
					break;

			}
		}
		//maybe some flicker on selected option?
		//continue animation
	}
}

void Menu::activate() {
	active = true;
}

void Menu::addChild(std::shared_ptr<MenuOption>& item) {
	children.push_back(item);
	if (children.size() == 1) {
		children[0]->select();
	}
	children.back()->setPosition(100, 100 + children.size() * 50);				//magic numbers
}

bool Menu::isDone() const {
	return done;
}

bool Menu::done = false;

