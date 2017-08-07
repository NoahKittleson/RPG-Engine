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
    party.emplace_back(500, 450, 75, resources.getTexture(Textures::BasicIdle),
					   resources.getFont(Fonts::Sansation), "Pringus", "CLASH", false,
                       resources.getTexture(Textures::GetHitAnimation));
    party.back()._recoveryAbility.setProperties(Ability::Heal, 100);
    Ability ability1 ("BigPunch", "Makes a big punch", 100, false, false,
                      resources.getTexture(Textures::BadAttackAnimation));
    ability1.setReq(Ability::ManaCost, 100);
    Ability ability2 ("SmallPunch", "Makes a smaller punch" , 50, false, false,
                      resources.getTexture(Textures::BadAttackAnimation));
    ability2.setReq(Ability::ManaCost, 50);
    party.back().addAbility(ability1);
    party.back().addAbility(ability2);
    
    //set up player sprite
	std::vector<sf::FloatRect> emptyList;
	emptyList.push_back(sf::FloatRect(10,10,20,20));
	player = make_unique<PlayerObject>(graphicsPtr(new WalkingAnimation(resources.getTexture(Textures::PlayerWalkingUp),
												resources.getTexture(Textures::PlayerWalkingDown),
												resources.getTexture(Textures::PlayerWalkingLeft),
												resources.getTexture(Textures::PlayerWalkingRight),
												sf::Vector2f(50,50), 0.1f, sf::Vector2i(16,16))), emptyList);

	
    //load conditions into ConditionList
    //(not yet)
}

void LoadState::handleEvent() {
    return;
}

void LoadState::update(sf::RenderWindow&, sf::Clock&) {
    //nothing yet... eventually loading bar?
}

void LoadState::draw(sf::RenderWindow& rw) {
    rw.clear(sf::Color::Black);
    //nothing yet... eventually loading bar?
}
