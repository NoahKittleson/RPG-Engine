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
    TalkingSprite(const sf::Texture&, sf::Vector2f, std::vector<sf::FloatRect>&, DNode*);
    void DrawCollisionBoxes(sf::RenderWindow &rw) const;
    //DNode* getDialogue() const;
    
    bool intersects(sf::FloatRect) const;
    void collide(Player&, sf::Vector2f movement) const;
    DNode* interact(sf::FloatRect);
    
private:
    DNode* whatItSays = nullptr;
    std::vector<sf::FloatRect> collisionBoxList;
};
