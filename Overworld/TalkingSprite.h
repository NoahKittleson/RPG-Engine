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

class TalkingSprite: public sf::Sprite
{
public:
    TalkingSprite(const sf::Texture&, sf::Vector2f, std::vector<sf::FloatRect>&, DNode* text);
    TalkingSprite(const sf::Texture& texture, sf::Vector2f position, std::vector<sf::FloatRect>& collisionList, DNode* text, sf::Vector2u frameSize, float timePerFrame);
    void DrawCollisionBoxes(sf::RenderWindow &rw) const;
    //DNode* getDialogue() const;
    
    int getBase() const;
    bool intersects(sf::FloatRect) const;
    void collide(Player&, sf::Vector2f movement) const;
    DNode* interact(sf::FloatRect);
    void animate(float elapsed, sf::RenderWindow &rw);
    
private:
    void next_frame();
    
    DNode* whatItSays = nullptr;
    std::vector<sf::FloatRect> collisionBoxList;
    
    const sf::IntRect frameSize;
    const sf::Texture* nextAnimation = nullptr;  //nullptr: loops, ptr = non-looping, change to this after animation ends.
    const float timePerFrame;
    float totalelapsed = 0;
};
