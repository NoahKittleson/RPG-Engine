//
//  LoadState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/12/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "LoadState.hpp"

LoadState::LoadState(SafeStack<State>& stateStack) {
	stack = &stateStack;
	//load stuff for loading bar, loading text, etc...
}

void LoadState::handleInput(sf::RenderWindow& rw) {
    return;
}

void LoadState::update(sf::Clock&) {
    //nothing yet... eventually loading bar?
}

void LoadState::draw(sf::RenderWindow& rw) {
    rw.clear(sf::Color::Black);
	rw.display();
    //nothing yet... eventually loading bar?
}

void LoadState::load() {
	//load conditions into ConditionList
	//(not yet)
	currentMap = MapFactory::create(MapID::TownSouth, resources, conditions);
	
	//set up party
	party.push_back(CharacterGenerator::create(resources, Combatant::Pringus));
	party.push_back(CharacterGenerator::create(resources, Combatant::Dingus));
	
	//set up player sprite
	player = make_unique<PlayerObject>(graphicsPtr(new WalkingAnimation(resources.getTexture(Textures::PlayerWalkingUp2),
																		resources.getTexture(Textures::PlayerWalkingDown2),
																		resources.getTexture(Textures::PlayerWalkingLeft2),
																		resources.getTexture(Textures::PlayerWalkingRight2),
																		sf::Vector2f(50,50), 0.1f, sf::Vector2i(24,24))));
	player->addCollisionBox(-10,30,20,6);
	player->attachAudio(audioPlayer);
	
	//	player = make_unique<PlayerObject>(graphicsPtr(new WalkingAnimation(resources.getTexture(Textures::PlayerWalkingUp),
	//												resources.getTexture(Textures::PlayerWalkingDown),
	//												resources.getTexture(Textures::PlayerWalkingLeft),
	//												resources.getTexture(Textures::PlayerWalkingRight),
	//												sf::Vector2f(50,50), 0.1f, sf::Vector2i(16,16))), collisionList);
	//	player->addCollisionBox(-10,20,20,5);
	

}

