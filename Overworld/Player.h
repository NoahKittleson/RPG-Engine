//
//  Player.h
//  Overworld
//
//  Created by Noah Kittleson on 2/28/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "ResourcePath.hpp"
#include "MapSprite.hpp"
#include "ResourceHolder.h"

class Player : public MapSprite
{
public:
    Player(const ResourceHolder &rh);
    sf::IntRect getAbsBox();
    void update(sf::Vector2f moveVec, float elapsed);
    
private:
    sf::IntRect box;
	enum Direction {Up, Down, Left, Right, Stand};
	Direction walkingState;
	
	void changeState(Direction newDir);
	
    const sf::Texture* walkUp;
    const sf::Texture* walkDown;
    const sf::Texture* walkLeft;
    const sf::Texture* walkRight;
};

//things to do-
//3.Get the constructor away from being so extremely hard-coded
