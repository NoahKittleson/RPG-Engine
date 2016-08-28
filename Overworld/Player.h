//
//  Player.h
//  Overworld
//
//  Created by Noah Kittleson on 2/28/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"


class Player : public sf::Sprite
{
public:
    Player();
    sf::FloatRect getAbsBox();
    
private:
    sf::FloatRect box;
    sf::Texture texture;
};