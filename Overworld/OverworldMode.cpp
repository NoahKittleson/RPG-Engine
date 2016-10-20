//
//  OverworldMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/22/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "OverworldMode.h"

#define COLLISION_BOX_EXTRA 10


OverworldMode::OverworldMode(MapSection* map)
{
	currentMap = map;

	view.setSize(sf::Vector2f(1024,768));			//this is very much cheating but I don't want to figure this out right now.
	view.zoom(0.5);
	view.setCenter(playerSprite.getPosition());
	
	playerSprite.setScale(4.0f, 4.0f);
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
	checkTriggers(rw);		//only applicable if player moved...
	updateView();			//applicable if player moves OR if zone is changed.
	rw.setView(view);
	//animate?
	currentMap->drawBackground(rw);
	currentMap->drawAllObjects(rw, playerSprite);
	drawAllBoxes(rw);
	
	rw.display();
}

void OverworldMode::draw(sf::RenderWindow &rw) {

}

std::string OverworldMode::handleEvent() {
	for (const auto & it: currentMap->miniTriggers) {
		if (it.getZone().intersects(playerSprite.getAbsBox())) {
			return it.getActionID();
		}
	}
	return "";
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
	playerSprite.move(moveVec.x, 0);
	handlePlayerCollision(sf::Vector2f(moveVec.x, 0));
	playerSprite.move(0, moveVec.y);
	handlePlayerCollision(sf::Vector2f(0, moveVec.y));
}

void OverworldMode::handlePlayerCollision(sf::Vector2f moveVec)
{
	//sf::FloatRect playerRect = playerSprite.getAbsBox();
	
	for (auto const & sprite: currentMap->getSpriteList()) {
		if (sprite.intersects(playerSprite.getAbsBox())) {
			sprite.collide(playerSprite, moveVec);
		}
	}
	
	//probably move this to TalkingSprite.collide();
	//sf::FloatRect playerRect = playerSprite.getAbsBox();
	/*for (auto const & itObj : currentMap->getSpriteList()) {
		for (auto const & itBox : itObj.getCollisionBoxList()) {
			if (playerRect.intersects(itBox)) {
				if (moveVec.x == 0 && moveVec.y > 0) {			//moving down
					playerSprite.setPosition(playerSprite.getPosition().x,
											 itBox.top - playerRect.height/2);
				}
				else if (moveVec.x == 0 && moveVec.y < 0){		//moving up
					playerSprite.setPosition(playerSprite.getPosition().x,
											 itBox.top + itBox.height + playerRect.height/2);
											 //itBox.top + itBox.height * 1.5f);
				}
				else if (moveVec.x > 0 && moveVec.y == 0){		//moving right
					playerSprite.setPosition(itBox.left - playerRect.width/2,
											 playerSprite.getPosition().y);
				}
				else if (moveVec.x < 0 && moveVec.y == 0){		//moving left	
					playerSprite.setPosition(itBox.left + itBox.width + playerRect.height/2,
											 playerSprite.getPosition().y);
				}
			}
		}
	}*/
}

void OverworldMode::checkExits()
{
	for (const auto & exit: currentMap->getExitList()) {
		if (exit.intersects(playerSprite.getAbsBox()) && exit.getNextZone() != "") {
//			currentMap = exit.getNextZone();
			//SHOULD BE SOMETHING LIKE: currentMap = World.getMap(exit.getNextZone());
			//Or better yet: switchToMap("string");
			exit.MoveSpriteToNewZone(playerSprite, view);
			return;
		}
	}
}

void OverworldMode::checkTriggers(sf::RenderWindow &rw) {
	for (const auto & it: currentMap->getTriggerList()) {
		if (it.intersects(playerSprite.getAbsBox())) {
			//addToStack(it.procTrigger(rw));
			switch(it.getDataType()) {
				case DataType::Fight:
					//fix later
					//addToStack(new BattleMode (it.getData().enemyVec));
					break;
				case DataType::Talk:
					//fix later
					//addToStack(new DialogueMode (it.getData().conversation, rw));
					break;
			}
		}
	}
}

/*			switch(it.getType()) {
				case ActionType::Fight:
					addToStack(new BattleMode (*static_cast<FightZone*>(it)->enemylist));
					break;
				case ActionType::None:
					break;
				case ActionType::Dialogue:
					addToStack(new DialogueMode (static_cast<DialogueZone*>(it)->dialogue, rw));
					break;
				case ActionType::OverWorld:
					break;
			}
		}
	}
}*/


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
	Rectangle.setSize(sf::Vector2f(playerSprite.getAbsBox().width,
								   playerSprite.getAbsBox().height));
	Rectangle.setPosition(playerSprite.getAbsBox().left,
						  playerSprite.getAbsBox().top );
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
	sf::Vector2f NewPosition = playerSprite.getPosition();
	int viewWidth = view.getSize().x;
	int viewHeight = view.getSize().y;
	
	int backgroundWidth = currentMap->getSize().x;
	int backgroundHeight = currentMap->getSize().y;
	
	if (playerSprite.getPosition().x < viewWidth/2) NewPosition.x = viewWidth/2;
	else if (playerSprite.getPosition().x > backgroundWidth - viewWidth/2)
		NewPosition.x = backgroundWidth - viewWidth/2;
	
	if (playerSprite.getPosition().y < viewHeight/2) NewPosition.y = viewHeight/2;
	else if (playerSprite.getPosition().y > backgroundHeight - viewHeight/2)
		NewPosition.y = backgroundHeight - viewHeight/2;

	view.setCenter(NewPosition);
}

void OverworldMode::checkForInteraction(sf::RenderWindow &rw)
{
	sf::FloatRect bigCollision = playerSprite.getAbsBox();
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

//Candidates for moving or complete removal--

/*
void OverworldMode::InteractionLoop(sf::RenderWindow &rw, InteractableObject& obj)
{
	std::stringstream ss;
	float totalElapsed = 0;
	
	while(rw.isOpen()) {
		totalElapsed += _gameClock.restart().asSeconds();
		
		sf::Event event;
		while (rw.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rw.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
				if (ss.str().size() >= obj.GetText().getString().getSize()) {
					obj.CurrentText++;
					return;
				}
				ss.str("");
				//ss << obj.WhatItSays.getString().toAnsiString();
				ss << obj.GetText().getString().toAnsiString();
			}
		}
		rw.clear(sf::Color::White);
		
		rw.setView(_view);
		_currentMap->DrawAllObjects(rw, _playerCharacter);
		//_playerCharacter.Draw(rw);
		
		//make a HUD view, set it, and then draw a message box with the WhatItSays text
		sf::View HUD = rw.getDefaultView();
		rw.setView(HUD);
		static sf::RectangleShape MessageRect (sf::Vector2f(0,0));
		MessageRect.setSize(sf::Vector2f(800,200));
		MessageRect.setFillColor(sf::Color::Magenta);
		rw.draw(MessageRect);
		rw.draw(getGradualText(obj.GetText(), totalElapsed, ss));
		
		rw.display();
	}
}

void OverworldMode::InteractionLoopNEW(sf::RenderWindow &rw, DialogueThread* spool)
{
	sf::Font font;
	font.loadFromFile("sansation.ttf");
	sf::Text Display ("", font, 32);
	Display.setColor(sf::Color::Black);
	
	std::list<sf::String>::iterator it = spool->getDialogue().begin();
	
	sf::Clock clock;
	float elapsed;
	float totalElapsed{0};
	
	while (rw.isOpen()) {
		
		sf::Event event;
		elapsed = clock.restart().asSeconds();
		totalElapsed += elapsed;
		while (rw.pollEvent(event)) {
			
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				it++;
				if (it == spool->getDialogue().end()) {
					if (spool->getChoices().empty()) {
						return;
					}
					spool = getDecision(spool->getChoices(), rw, clock);
					it = spool->getDialogue().begin();
				}
				Display.setString("");
				totalElapsed = 0;
			}
		}
		Display.setString(getGradualTextNEW(*it, Display.getString(), totalElapsed));
		
		rw.clear(sf::Color::White);
		rw.draw(Display);
		rw.display();
	}
}

DialogueThread* OverworldMode::getDecision(std::list<DialogueThread*> choices, sf::RenderWindow &rw, sf::Clock& timer)
{
	if (choices.size() == 1) {
		return *choices.begin();
	}
	
	sf::Font font;
	font.loadFromFile("sansation.ttf");
	sf::Text Display("BAD ERROR", font, 32);
	Display.setColor(sf::Color::Black);
	std::list<DialogueThread*>::iterator iter = choices.begin();
	
	while (rw.isOpen()) {
		rw.clear(sf::Color::White);
		timer.restart();                                //this is where I will make float elapsed if I have need of it
		
		int Ypos = 0;
		for (auto&& it: choices) {
			Display.setString(it->getStartingOption());
			Display.setPosition(0, Ypos);
			Ypos += 50;
			
			if (it == *iter) {
				Display.setColor(sf::Color::Red);
			}
			rw.draw(Display);
			Display.setColor(sf::Color::Black);
		}
		
		sf::Event event;
		while (rw.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
				if (iter == choices.begin()) {
					iter = choices.end();
				}
				iter--;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
				iter++;
				if (iter == choices.end()) {
					iter = choices.begin();
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				return *iter;
			}
		}
		rw.display();
	}
	//I don't think this can be reached, but in case it does...
	return *iter;
}*/





