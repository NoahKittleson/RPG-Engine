//
//  LoadState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/12/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "LoadState.hpp"
#include "StartingZone.h"

LoadState::LoadState(StateStack& SS) {
    stack = &SS;
    //I REALLY DON'T LIKE THIS - DANGER DANGER
    currentMap = new StartingZone (resources);
    //DANGER DANGER CHANGE SOON AS POSSIBLE
    
    //set up party
    party.emplace_back(500, 450, 75, resources.getTexture("BasicIdle.png"),
                       resources.getFont("sansation.ttf"), "Pringus", "CLASH", false,
                       resources.getTexture("GetHitAnimation.png"));
    party.back()._recoveryAbility.setProperties(Ability::Heal, 100);
    Ability ability1 ("BigPunch", "Makes a big punch", 100, false, false,
                      resources.getTexture("BadAttackAnimation.png"));
    ability1.setReq(Ability::ManaCost, 100);
    Ability ability2 ("SmallPunch", "Makes a smaller punch" , 50, false, false,
                      resources.getTexture("BadAttackAnimation.png"));
    ability2.setReq(Ability::ManaCost, 50);
    party.back().addAbility(ability1);
    party.back().addAbility(ability2);
    
    //set up player sprite
	//this is ludicrously temporary
	std::vector<sf::IntRect> emptyList;
	emptyList.push_back(sf::IntRect(0,0,10,10));
	player = new MapObject(new GraphicsComponent(resources.getTexture("PlayerWalkingDown.png"), sf::Vector2f(50,50)/*, 0.1f, sf::Vector2i(32,32), 3.0f*/), emptyList);

	
    //load conditions into ConditionList
    //(not yet)
}

ActionID LoadState::handleEvent() {
    return ActionID::None;
}

void LoadState::update(sf::RenderWindow&, sf::Clock&) {
    //nothing yet... eventually loading bar?
}

void LoadState::draw(sf::RenderWindow& rw) {
    rw.clear(sf::Color::Black);
    //nothing yet... eventually loading bar?
}
