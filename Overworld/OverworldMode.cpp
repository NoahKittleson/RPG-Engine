//
//  OverworldMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/22/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "OverworldMode.h"

#define COLLISION_BOX_EXTRA 10


OverworldMode::OverworldMode()
{
	view.setSize(sf::Vector2f(1024,768));			//this is very much cheating but I don't want to figure this out right now.
	view.zoom(0.5);
	view.setCenter(player->getPosition());
	updateView();
	
	player->setScale(4.0f);
	musicPlayer.openFromFile(currentMap->getMusicAddress());
	//musicPlayer.play();
}

void OverworldMode::handleInput(sf::RenderWindow& rw) {
	CommandQueue.clear();
	if (mode) {
		mode->handleInput(rw);
		return;
	} else {
		sf::Event event;
		while (rw.pollEvent(event)) {
			switch (event.key.code) {
				case sf::Keyboard::X:
					CommandQueue.push_back(X);
					break;
					
				case sf::Keyboard::Z:
					CommandQueue.push_back(Z);
					break;
					
				case sf::Keyboard::Escape:
					rw.close();
					break;

				default:
					break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				CommandQueue.push_back(Up);
			} else
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				CommandQueue.push_back(Down);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				CommandQueue.push_back(Left);
			} else
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				CommandQueue.push_back(Right);
			}
			//maybe this fits more in update, but I need RenderWindow...
			for (char iii = 0; iii < CommandQueue.size(); iii++) {
				if (CommandQueue[iii] == X) {
					checkForInteraction(rw);
				}
			}
			return;
		}
	}
	
	//this will never be reached...
	Mode::modeAction action;
	if (mode) {
		action = mode->handleEvent();
		switch(action) {
			case Mode::FadeOutEnd:
				//find out which exitZone we intersect with and change the map accordingly
				for (const auto & exit: currentMap->getExitList()) {
					if (player->intersects(exit.getArea())) {
						changeMap(exit);
					}
				}
				//change mode
				mode = std::unique_ptr<Mode>(new Fade(true, 1.f));
				break;
				
			case Mode::FadeInEnd:
				mode = nullptr;
				break;
				
			case Mode::FadeOutBegin:
				mode = std::unique_ptr<Mode>(new Fade(false, 1.f));
				break;
				
			case Mode::FadeInBegin:
				mode = std::unique_ptr<Mode>(new Fade(true, 1.f));
				break;
				
			case Mode::None:
			default:
				break;
		}
	}
}

void OverworldMode::update(sf::Clock& timer) {
	float elapsed = timer.restart().asSeconds();
	if (mode) {
		mode->update(elapsed);
	} else {
		if (handleMovement(elapsed) || checkExits()) {
			updateView();
		}
	}
}

void OverworldMode::draw(sf::RenderWindow &rw) {
	rw.clear(sf::Color::White);
	rw.setView(view);
	currentMap->drawBackground(rw);
	drawAllBoxes(rw);
	currentMap->drawAllObjects(rw, *player);
	if (mode) {
		mode->draw(rw);
	}
	player->drawCenter(rw);
	rw.display();
}

void OverworldMode::changeMap(ZoneExit exit) {
	MapID nextZone = exit.getNextZone();
	if (nextZone != currentMap->ID) {
		//change maps
		switch (nextZone) {
			case MapID::Starting:
				currentMap = std::unique_ptr<MapSection>(new StartingZone(resources));
				break;
				
			case MapID::BigField:
				currentMap = std::unique_ptr<MapSection>(new BigField(resources));
				break;
						
			default:
				//just in case.  It's better than a game crash.
				currentMap = std::unique_ptr<MapSection>(new StartingZone(resources));
				break;
		}
	}
	sf::Vector2f transitionOffset = exit.getMoveOffset();
	player->move(transitionOffset.x, transitionOffset.y);
	view.move(transitionOffset);
}

bool OverworldMode::handleMovement(float elapsed) {
	sf::Vector2f moveVec (0,0);
	for (int iii = 0; iii > CommandQueue.size(); iii++) {
		switch (CommandQueue[iii]) {
			case Up:
				moveVec.y -= 100;
				break;
			case Down:
				moveVec.y += 100;
				break;
			case Left:
				moveVec.x -= 100;
				break;
			case Right:
				moveVec.x += 100;
				break;
			default:
				break;
		}
	}
	moveVec *= elapsed;
	//handle movement on X axis
	player->move(moveVec.x, 0);
	for (auto const & sprite: currentMap->getSpriteList()) {
		sprite.collideX(*player, moveVec.x);
	}
	//handle movement on Y axis
	player->move(0, moveVec.y);
	for (auto const & sprite: currentMap->getSpriteList()) {
		sprite.collideY(*player, moveVec.y);
	}
	player->update(elapsed);
	if (moveVec == sf::Vector2f(0,0)) {
		return false;
	}
	return true;
}

bool OverworldMode::checkExits()
{
	for (const auto & exit: currentMap->getExitList()) {
		if (player->intersects(exit.getArea())) {
			mode = std::unique_ptr<Mode>(new Fade(false, 1.f));
			return true;
		}
	}
	return false;
}

void OverworldMode::checkTriggers() {
	for (const auto & it: currentMap->getTriggerList()) {
		if (player->intersects(it)) {
			State* unsafePtr = it.proc(conditions);
			if (unsafePtr != nullptr) {
				requestStackAdd(std::unique_ptr<State>(unsafePtr));
			}
		}
	}
}

void OverworldMode::drawPlayerCollision(sf::RenderWindow &rw)
{
	player->drawCollision(rw);
}

void OverworldMode::drawAllBoxes(sf::RenderWindow &rw)
{
	//collision
	for (auto && it: currentMap->getSpriteList()) {
		it.drawCollision(rw);
	}
	drawPlayerCollision(rw);
	
	//triggers
	for (auto && it: currentMap->getTriggerList()) {
		it.drawArea(rw);
	}
}

void OverworldMode::updateView()
{
	sf::Vector2f NewPosition = player->getPosition();
	int viewWidth = view.getSize().x;
	int viewHeight = view.getSize().y;
	
	int backgroundWidth = currentMap->getSize().x;
	int backgroundHeight = currentMap->getSize().y;
	
	if (player->getPosition().x < viewWidth/2) NewPosition.x = viewWidth/2;
	else if (player->getPosition().x > backgroundWidth - viewWidth/2)
		NewPosition.x = backgroundWidth - viewWidth/2;
	
	if (player->getPosition().y < viewHeight/2) NewPosition.y = viewHeight/2;
	else if (player->getPosition().y > backgroundHeight - viewHeight/2)
		NewPosition.y = backgroundHeight - viewHeight/2;

	view.setCenter(NewPosition);
}

void OverworldMode::checkForInteraction(sf::RenderWindow &rw)
{
	DNode* dialoguePtr = player->interact(*currentMap);
	if (dialoguePtr) {
		std::cout << "dialogueMode created\n";
		requestStackAdd(std::unique_ptr<State>(new DialogueMode(dialoguePtr, rw)));
	}
}






