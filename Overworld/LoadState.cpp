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
    playerSprite = new Player(resources);
    
    //load conditions into ConditionList
    //(not yet)
}

std::string LoadState::handleEvent() {
    return "";
}

void LoadState::update(sf::RenderWindow&, sf::Clock&) {
    //nothing yet... eventually loading bar?
}

void LoadState::draw(sf::RenderWindow&) {
    //nothing yet... eventually loading bar?
}
