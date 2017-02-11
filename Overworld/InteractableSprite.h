//
//  TalkingSprite.h
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "Player.h"
#include "DNode.h"

class InteractableSprite: public MapSprite
{
public:
    InteractableSprite(const sf::Texture&, sf::Vector2f, const std::vector<sf::FloatRect>&,
                       DNode* text, float timePerFrame = 0);
    void addTime (float delta);

    void DrawCollisionBoxes(sf::RenderWindow &rw) const;
    //DNode* getDialogue() const;
    bool intersects(sf::FloatRect) const;
    void collide(Player&, sf::Vector2f movement) const;
    DNode* interact(sf::FloatRect);

    
private:
    DNode* whatItSays = nullptr;
    std::vector<sf::FloatRect> collisionBoxList;
    
    //sf::Texture* nextAnimation = nullptr;  //nullptr: loops, ptr = non-looping, change to this after animation ends.
};
