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
	view.setCenter(playerSprite->getPosition());
	
	playerSprite->setScale(4.0f, 4.0f);
	//playerSprite.setFrame(0);
	//eventually I should set the origin in center of sprite
}

void OverworldMode::update(sf::RenderWindow &rw, sf::Clock& timer)
{
	float elapsed = timer.restart().asSeconds();
	rw.clear(sf::Color::White);
	handleMovement(elapsed);
	handleKeyPress(rw);
	checkExits();			//only applicable if player moves... move to handlemovement?
	checkTriggers();		//only applicable if player moved...
	updateView();			//applicable if player moves OR if zone is changed.
	rw.setView(view);
	for (auto && sprite : currentMap->getSpriteList()) {
		sprite.update(elapsed);
	}
}

void OverworldMode::draw(sf::RenderWindow &rw) {
	currentMap->drawBackground(rw);
	drawAllBoxes(rw);
	currentMap->drawAllObjects(rw, *playerSprite);
	rw.display();
}

ActionID OverworldMode::handleEvent() {
	return checkTriggers();
}

void OverworldMode::handleMovement(float elapsed)
{
	sf::Vector2f moveVec (0,0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		moveVec.y -= 100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		moveVec.y += 100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveVec.x -= 100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		moveVec.x += 100;
	}
	moveVec *= elapsed;
	playerSprite->move(moveVec.x, 0);
	handlePlayerCollision(sf::Vector2f(moveVec.x, 0));
	playerSprite->move(0, moveVec.y);
	handlePlayerCollision(sf::Vector2f(0, moveVec.y));
	playerSprite->update(moveVec, elapsed);
}

void OverworldMode::handlePlayerCollision(sf::Vector2f moveVec)
{
	//sf::FloatRect playerRect = playerSprite.getAbsBox();
	
	for (auto const & sprite: currentMap->getSpriteList()) {
		if (sprite.intersects(playerSprite->getAbsBox())) {
			sprite.collide(*playerSprite, moveVec);
		}
	}
}

void OverworldMode::checkExits()
{
	for (const auto & exit: currentMap->getExitList()) {
		if (exit.intersects(playerSprite->getAbsBox())) {
			auto nextZone = exit.getNextZone();
			if (nextZone != currentMap->ID) {
				delete currentMap;
				switch (nextZone) {
					case MapID::Starting:
						currentMap = new StartingZone(resources);
						break;
						
					case MapID::BigField:
						currentMap = new BigField(resources);
						break;
						
					default:
						//just in case.  It's better than a game crash.
						currentMap = new StartingZone(resources);
						break;
				}
			}
			sf::Vector2f transitionOffset = exit.getMoveOffset();
			playerSprite->move(transitionOffset.x, transitionOffset.y);
			view.move(transitionOffset);
			std::cout << "player moved to: " << playerSprite->getPosition().x << ", " << playerSprite->getPosition().y << "\n";
			return;
		}
	}
}

ActionID OverworldMode::checkTriggers() {
	for (const auto & it: currentMap->getTriggerList()) {
		if (it.intersects(playerSprite->getAbsBox())) {
			ActionID action = it.proc(conditions);
			switch (action) {
				case ActionID::Fight:
					//addToStack(new BattleMode (action));
					//create state
					break;
					
				case ActionID::Talk:
					//addToStack(new DialogueMode (action));
					break;
					
				default:
					break;
			}
		}
	}
	return ActionID::None;
}


void OverworldMode::handleKeyPress(sf::RenderWindow &rw)
{
	sf::Event event;
	while (rw.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			rw.close();
		}
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::X:
					std::cout << "X key pressed\n";
					checkForInteraction(rw);
					break;
					
				case sf::Keyboard::Escape:
					rw.close();
					break;
					
				default:
					break;
			}
		}
	}
}

void OverworldMode::drawPlayerCollision(sf::RenderWindow &rw)
{
	sf::RectangleShape Rectangle;
	Rectangle.setFillColor(sf::Color(0,250,0,125));
	Rectangle.setSize(sf::Vector2f(playerSprite->getAbsBox().width,
								   playerSprite->getAbsBox().height));
	Rectangle.setPosition(playerSprite->getAbsBox().left,
						  playerSprite->getAbsBox().top );
	rw.draw(Rectangle);
}

void OverworldMode::drawAllBoxes(sf::RenderWindow &rw)
{
	for (auto && it: currentMap->getSpriteList()) {
		it.DrawCollisionBoxes(rw);
	}
	drawPlayerCollision(rw);
}

void OverworldMode::updateView()
{
	sf::Vector2f NewPosition = playerSprite->getPosition();
	int viewWidth = view.getSize().x;
	int viewHeight = view.getSize().y;
	
	int backgroundWidth = currentMap->getSize().x;
	int backgroundHeight = currentMap->getSize().y;
	
	if (playerSprite->getPosition().x < viewWidth/2) NewPosition.x = viewWidth/2;
	else if (playerSprite->getPosition().x > backgroundWidth - viewWidth/2)
		NewPosition.x = backgroundWidth - viewWidth/2;
	
	if (playerSprite->getPosition().y < viewHeight/2) NewPosition.y = viewHeight/2;
	else if (playerSprite->getPosition().y > backgroundHeight - viewHeight/2)
		NewPosition.y = backgroundHeight - viewHeight/2;

	view.setCenter(NewPosition);
}

void OverworldMode::checkForInteraction(sf::RenderWindow &rw)
{
	sf::IntRect bigCollision = playerSprite->getAbsBox();
	bigCollision.left -= COLLISION_BOX_EXTRA;
	bigCollision.top -= COLLISION_BOX_EXTRA;
	bigCollision.width += COLLISION_BOX_EXTRA*2;		//X2 to make up for the left offset
	bigCollision.height += COLLISION_BOX_EXTRA*2;
	
	for (auto && obj: currentMap->getSpriteList()) {
		auto dialoguePtr = obj.interact(bigCollision);
		if (dialoguePtr) {
			std::cout << "dialogueMode created\n";
			addToStack( new DialogueMode (dialoguePtr, rw) );
		}
	}
}

void OverworldMode::addDialogueState(DNode* thread, sf::RenderWindow &rw)
{
	auto ptr = new DialogueMode(thread, rw);								//danger danger Will Robinson.
	addToStackAndBreak(ptr);
}





