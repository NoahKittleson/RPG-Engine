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
    void update(sf::Vector2f moveVec);
    
    
private:
    sf::FloatRect box;
    sf::Texture texture;
    //every one of these should be texture ptrs
    sf::Texture walkUp;
    sf::Texture walkDown;
    sf::Texture walkRight;
};
