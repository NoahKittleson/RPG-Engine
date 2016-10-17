//
//  TalkingSprite.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "TalkingSprite.h"


TalkingSprite::TalkingSprite(const sf::Texture& texture, sf::Vector2f position, std::vector<sf::FloatRect>& collisionList, DNode* text)
: collisionBoxList(collisionList), whatItSays(text)
{
    
    for (auto && it : collisionBoxList) {
        it.left += position.x;
        it.top += position.y;
    }
    setTexture(texture);
    setPosition(position);
}

void TalkingSprite::DrawCollisionBoxes(sf::RenderWindow &rw) const
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Red);
    for (auto const & it: collisionBoxList) {
        rectangle.setSize(sf::Vector2f(it.width, it.height));
        rectangle.setPosition(it.left, it.top);
        rw.draw(rectangle);
    }
}


void TalkingSprite::collide(Player &PC, sf::Vector2f moveVec) const {
    sf::FloatRect playerRect = PC.getAbsBox();
    
    for (auto const & itBox : collisionBoxList) {
        if (playerRect.intersects(itBox)) {
            if (moveVec.x == 0 && moveVec.y > 0) {			//moving down
                PC.setPosition(PC.getPosition().x,
                               itBox.top - playerRect.height/2);
            }
            else if (moveVec.x == 0 && moveVec.y < 0){		//moving up
                PC.setPosition(PC.getPosition().x,
                               itBox.top + itBox.height + playerRect.height/2);
            }
            else if (moveVec.x > 0 && moveVec.y == 0){		//moving right
                PC.setPosition(itBox.left - playerRect.width/2,
                               PC.getPosition().y);
            }
            else if (moveVec.x < 0 && moveVec.y == 0){		//moving left
                PC.setPosition(itBox.left + itBox.width + playerRect.width /2,
                               PC.getPosition().y);
            }
        }
    }
}

bool TalkingSprite::intersects(sf::FloatRect rect) const {
    for (auto && it: collisionBoxList) {
        if (rect.intersects(it)) {
            return true;
        }
    }
    return false;
}


DNode* TalkingSprite::interact(sf::FloatRect rect) {
    for (auto && box: collisionBoxList) {
        if (box.intersects(rect)) {
            return whatItSays;
        }
    }
    return nullptr;
}








