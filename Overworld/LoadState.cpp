//
//  LoadState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/12/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "LoadState.hpp"

LoadState::LoadState(StateStack& SS) {
    stack = &SS;
	currentMap = std::unique_ptr<MapSection>(new StartingZone (resources));
    
    //set up party
	party.push_back(CharacterGenerator::create(resources, Combatant::Pringus));
	party.push_back(CharacterGenerator::create(resources, Combatant::Dingus));
    
    //set up player sprite
	std::vector<sf::FloatRect> collisionList;
	collisionList.push_back(sf::FloatRect(-10,25,20,5));				//magic numbers all round
	player = make_unique<PlayerObject>(graphicsPtr(new WalkingAnimation(resources.getTexture(Textures::PlayerWalkingUp),
												resources.getTexture(Textures::PlayerWalkingDown),
												resources.getTexture(Textures::PlayerWalkingLeft),
												resources.getTexture(Textures::PlayerWalkingRight),
												sf::Vector2f(50,50), 0.1f, sf::Vector2i(16,16))), collisionList);

	
    //load conditions into ConditionList
    //(not yet)
}

void LoadState::handleInput(sf::RenderWindow& rw) {
    return;
}

void LoadState::update(sf::Clock&) {
    //nothing yet... eventually loading bar?
}

void LoadState::draw(sf::RenderWindow& rw) {
    rw.clear(sf::Color::Black);
    //nothing yet... eventually loading bar?
}
