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

class InteractableSprite: public sf::Sprite
{
public:
    InteractableSprite(const sf::Texture&, sf::Vector2f, const std::vector<sf::FloatRect>&,
                       
                       DNode* text, float timePerFrame = 0);
    void DrawCollisionBoxes(sf::RenderWindow &rw) const;
    //DNode* getDialogue() const;
    
    bool intersects(sf::FloatRect) const;
    void collide(Player&, sf::Vector2f movement) const;
    DNode* interact(sf::FloatRect);
    //void animate(float elapsed, sf::RenderWindow &rw);
    void addTime (float delta);
    

    
private:
    void next_frame();
    
    DNode* whatItSays = nullptr;
    std::vector<sf::FloatRect> collisionBoxList;
    
    sf::IntRect frameSize;
    sf::Texture* nextAnimation = nullptr;  //nullptr: loops, ptr = non-looping, change to this after animation ends.
    float timePerFrame;
    float totalelapsed = 0;
    
};
