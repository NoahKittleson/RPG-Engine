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

class Player : public MapSprite
{
public:
    Player();
    sf::FloatRect getAbsBox();
    int getBase() const;
    void drawBase(sf::RenderWindow &rw);
    void update(sf::Vector2f moveVec, float elapsed);
    
private:
    sf::FloatRect box;
    //every one of these should be texture ptrs
    sf::Texture walkUp;
    sf::Texture walkDown;
    sf::Texture walkLeft;
    sf::Texture walkRight;
};

//things to do-
//1.Draw out similarities between this and TalkingSprite (also really consider renaming talkingSprite)
//2.Switch to a state-based system for movementTexture stuff
//3.Get the constructor away from being so extremely hard-coded
