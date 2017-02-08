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

class Player : public sf::Sprite
{
public:
    Player();
    sf::FloatRect getAbsBox();
    int getBase() const;
    void update(sf::Vector2f moveVec, float elapsed);
    
private:
    //stats used for animation
    float timePerFrame = 0.1f;
    float totalElapsed = 0;
    sf::IntRect frameSize;
    void nextFrame();
    void animate(float elapsed);
    
    sf::FloatRect box;
    sf::Texture texture;
    //every one of these should be texture ptrs
    sf::Texture walkUp;
    sf::Texture walkDown;
    sf::Texture walkRight;
};

//things to do-
//1.Draw out similarities between this and TalkingSprite (also really consider renaming talkingSprite)
//2.Switch to a state-based system for movementTexture stuff
//3.Get the constructor away from being so extremely hard-coded
