//
//  OverworldMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/22/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "OverworldMode.h"

#define COLLISION_BOX_EXTRA 10


OverworldMode::OverworldMode() {
	view.setSize(sf::Vector2f(1024,768));			//this is very much cheating but I don't want to figure this out right now.
	view.zoom(0.5);
	view.setCenter(player->getPosition());
	updateView();
	
	audioPlayer.playMusic(currentMap->music);
}

void OverworldMode::handleInput(sf::RenderWindow& rw) {
	CommandQueue.clear();
	//just some activePhase housekeeping that needs to happen either first thing or last thing
	if (!activePhase.empty() && activePhase.getCurrentT()->isDone()) {
		activePhase.requestPop();
	}
	activePhase.applyPendingChanges();

	
	if (!rw.hasFocus()) {
		requestStackAdd(make_unique<PauseState>(rw));
		return;
	}
	if (!activePhase.empty()) {
		activePhase.getCurrentT()->handleInput(rw);
		return;
	} else {
		sf::Event event;
		while (rw.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab) {
				debugMode = !debugMode;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
				requestStackAdd(make_unique<PauseState>(rw));

			}
			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i mousePosInWindow = sf::Mouse::getPosition(rw);
				sf::Vector2u windowSize = rw.getSize();
				sf::Vector2i MouseRelativeToCenter (mousePosInWindow.x - windowSize.x/2, mousePosInWindow.y - windowSize.y/2);
				sf::Vector2f viewCenter = rw.getView().getCenter();
				sf::Vector2f finalPos (viewCenter.x + MouseRelativeToCenter.x/2, viewCenter.y + MouseRelativeToCenter.y/2);
				
				std::cout << "Click Coordinates: " << finalPos.x << ", " << finalPos.y << ".\n";
			}
			switch (event.key.code) {
				case sf::Keyboard::X:
					//to prevent events caused from key release
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
						CommandQueue.push_back(X);
						//maybe this fits more in update, but I need RenderWindow...
						checkForInteraction(rw);
					}
					break;
					
				case sf::Keyboard::Z:
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						CommandQueue.push_back(Z);
					}
					break;

				case sf::Keyboard::Escape:
					rw.close();
					break;

				default:
					break;
			}
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
	}
}

void OverworldMode::update(sf::Clock& timer) {
	float elapsed = timer.restart().asSeconds();
	if (!activePhase.empty()) {
		activePhase.getCurrentT()->update(elapsed, this);
	} else {
		checkTriggers();
		int index = checkExits();
		if (index >= 0) {
			if (mapChange == true) {
				mapChange = false;
				changeMap(currentMap->getExitList()[index]);
			} else {
			activePhase.requestAdd(std::unique_ptr<Mode>(new Fade(out, 1.f)));
			mapChange = true;
			}
		} else if (handleMovement(elapsed)) {
			updateView();
		}
		currentMap->update(elapsed);
	}
	
	if (!activePhase.empty() && activePhase.getCurrentT()->isDone()) {
		activePhase.requestPop();
	}
//			case fadeOut: {
//				currentMode = fadeIn;
//				int exitIndex = checkExits();
//				if (exitIndex >= 0) {
//					ZoneExit exit = currentMap->getExitList()[exitIndex];
//					player->move(currentMap->getGlobalPosition());
//					player->move(exit.getMoveOffset());
//					currentMap = MapFactory::create(exit.getNextZone(), resources, conditions);
//					player->move(-currentMap->getGlobalPosition());
//					handleOOB();
//					updateView();
//					audioPlayer.playMusic(currentMap->music);
//				}
//				mode = std::unique_ptr<Mode>(new Fade(in, 1.f));
//				std::cout << "Mode changed to Fade.\n";
//			}
		
//			case battleFadeOut:
//				currentMode = fadeIn;
//				mode = std::unique_ptr<Mode>(new Fade(in, 1.f));
//				//create new state from trigger
//				for (int iii = 0; iii < currentMap->getTriggerList().size(); iii++) {
//					if (player->intersects(currentMap->getTriggerList()[iii])) {
//						State* unsafePtr = currentMap->getTriggerList()[iii].proc(conditions);
//						if (unsafePtr != nullptr) {
//							currentMap->popTriggerAt(iii);					//I should find a better way to pop triggers
//							requestStackAdd(std::unique_ptr<State>(unsafePtr));
//							std::cout << "Battlestate created.\n";
//						}
//					}

}

void OverworldMode::draw(sf::RenderWindow &rw) {
	rw.clear(sf::Color::White);
	rw.setView(view);
	currentMap->drawBackground(rw);
	currentMap->drawExits(rw);
	currentMap->drawAllObjects(rw, *player);
	currentMap->drawLighting(rw);
	if (!activePhase.empty()) {
		activePhase.getCurrentT()->draw(rw);
	} else {
		if (debugMode) {
			drawAllBoxes(rw);
			player->drawBase(rw);
		}
	}
	player->drawCenter(rw);
	rw.display();
}

void OverworldMode::changeMap(ZoneExit exit) {
	MapID nextZone = exit.getNextZone();
	if (nextZone != currentMap->ID) {
		currentMap = MapFactory::create(nextZone, resources, conditions);
		//mode = std::unique_ptr<Mode>(new Fade(in, 1.f));	//axz
	}
	sf::Vector2f transitionOffset = exit.getMoveOffset();
	player->move(transitionOffset.x, transitionOffset.y);
	view.move(transitionOffset);
	audioPlayer.playMusic(currentMap->music);
}

bool OverworldMode::handleMovement(float elapsed) {
	sf::Vector2f moveVec (0.f, 0.f);
	for (int iii = 0; iii < CommandQueue.size(); iii++) {
		switch (CommandQueue[iii]) {
			case Up:
				moveVec.y -= 100.f;
				break;
			case Down:
				moveVec.y += 100.f;
				break;
			case Left:
				moveVec.x -= 100.f;
				break;
			case Right:
				moveVec.x += 100.f;
				break;
			default:
				break;
		}
	}
	moveVec *= elapsed;
	//handle movement on X axis
	player->move(moveVec.x, 0);
	for (auto const & sprite: currentMap->getSpriteList()) {
		sprite->collideX(*player, moveVec.x);
	}
	//handle movement on Y axis
	player->move(0, moveVec.y);
	for (auto const & sprite: currentMap->getSpriteList()) {
		sprite->collideY(*player, moveVec.y);
	}
	player->update(elapsed);
	if (moveVec == sf::Vector2f(0,0)) {
		return false;
	} else return true;
}

int OverworldMode::checkExits() {
	for (int iii = 0; iii < currentMap->getExitList().size(); iii++) {
		if (player->intersects(currentMap->getExitList()[iii].getArea())) {
			return iii;
		}
	}
	return -1;
}

void OverworldMode::checkTriggers() {
	for (int iii = 0; iii < currentMap->getTriggerList().size(); iii++) {
		if (player->intersects(currentMap->getTriggerList()[iii])) {
			if (currentMap->getTriggerList()[iii].meetsReqs(conditions)) {
				switch (currentMap->getTriggerList()[iii].getEffect()) {
					case GroundTrigger::blink:
						activePhase.requestAdd(std::unique_ptr<Mode>(new BlinkFade(out, 1.5f)));
						break;
						
					case GroundTrigger::fade:
						//this might be wonky.  Ye be warned.
						activePhase.requestAdd(std::unique_ptr<Mode>(new Fade(out, 1.5f)));
						break;
						
					case GroundTrigger::none:
						State* unsafePtr = currentMap->getTriggerList()[iii].proc(conditions);
						if (unsafePtr != nullptr) {
							currentMap->popTriggerAt(iii);					//I should find a better way to pop triggers
							requestStackAdd(std::unique_ptr<State>(unsafePtr));
							std::cout << "New State created.\n";
						} else {
							delete unsafePtr;
						}
						break;
				}
				
				//what if instead...
				//cueUpChange(blinkFade);
				//cueUpChange(triggerList[iii]);
			}
		}
	}
}

void OverworldMode::drawPlayerCollision(sf::RenderWindow &rw) {
	player->drawCollision(rw);
}

void OverworldMode::drawAllBoxes(sf::RenderWindow &rw) {
	currentMap->drawAllBoxes(rw);
	drawPlayerCollision(rw);
}

void OverworldMode::updateView() {
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

void OverworldMode::checkForInteraction(sf::RenderWindow &rw) {
	NodePtr dialoguePtr = player->interact(*currentMap);
	if (dialoguePtr) {
		std::cout << "dialogueMode created\n";
		requestStackAdd(make_unique<DialogueMode>(dialoguePtr));
	} else std::cout << "Nothing found to talk with.\n";
}

void OverworldMode::handleOOB() const {
	if (currentMap->getSize().x < player->getPosition().x) {
		player->setPosition(currentMap->getSize().x-20, player->getPosition().y);	//magic number 20
	}
	if (currentMap->getSize().y < player->getPosition().y) {
		player->setPosition(player->getPosition().x, currentMap->getSize().y-40);	//magic number 40
	}
	if (player->getPosition().x < 0) {
		player->setPosition(20, player->getPosition().y);							//magic number 20
	}
	if (player->getPosition().x < 0) {
		player->setPosition(player->getPosition().x, 40);							//magic number 40
	}
}






