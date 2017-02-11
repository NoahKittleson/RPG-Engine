//
//  InteractableSprite.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "InteractableSprite.h"


InteractableSprite::InteractableSprite(const sf::Texture& texture, sf::Vector2f position,
                             const std::vector<sf::FloatRect>& collisionList, DNode* text, float timePerFrame)
: collisionBoxList(collisionList), whatItSays(text), timePerFrame(timePerFrame), frameSize(sf::IntRect(0,0,texture.getSize().y, texture.getSize().y))   //yes, this is meant to have texture.getSize().y twice, because all my animation sheets are square
{
    setOrigin(frameSize.width/2, frameSize.height/2);
    for (auto && it : collisionBoxList) {
        it.left += position.x;
        it.top += position.y;
    }
    setTexture(texture);
    setTextureRect(frameSize);
    //float offset = std::rand()%100;
    //totalelapsed = offset/100;
    //totalelapsed = offset;
    setPosition(position);
  
}

//InteractableSprite::InteractableSprite(const InteractableSprite& other)
//:collisionBoxList(other.collisionBoxList), whatItSays(other.whatItSays), timePerFrame(other.timePerFrame), frameSize(other.frameSize), nextAnimation(other.nextAnimation)
//{
//    
//}

void InteractableSprite::DrawCollisionBoxes(sf::RenderWindow &rw) const
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Red);
    for (auto const & it: collisionBoxList) {
        rectangle.setSize(sf::Vector2f(it.width, it.height));
        rectangle.setPosition(it.left, it.top);
        rw.draw(rectangle);
    }
}


void InteractableSprite::collide(Player &PC, sf::Vector2f moveVec) const {
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
                PC.setPosition(itBox.left + itBox.width + playerRect.width/2,
                               PC.getPosition().y);
            }
        }
    }
}

bool InteractableSprite::intersects(sf::FloatRect rect) const {
    for (auto && it: collisionBoxList) {
        if (rect.intersects(it)) {
            return true;
        }
    }
    return false;
}


DNode* InteractableSprite::interact(sf::FloatRect rect) {
    for (auto && box: collisionBoxList) {
        if (box.intersects(rect)) {
            return whatItSays;
        }
    }
    return nullptr;
}

void InteractableSprite::animate(float elapsed, sf::RenderWindow &rw)       //non looped animation stays on final frame
{
    if (timePerFrame == 0) return;
    totalelapsed+= elapsed;
    while (totalelapsed >= timePerFrame) {
        totalelapsed -= timePerFrame;
        next_frame();
    }
    
    rw.draw(*this);
}

void InteractableSprite::next_frame() {
    if (getTextureRect().left + frameSize.width >= getTexture()->getSize().x) {
        setTextureRect(frameSize);
        if (nextAnimation) {
            setTexture(*nextAnimation);
        }
    }
    else setTextureRect(sf::IntRect(getTextureRect().left + frameSize.width,
                                   getTextureRect().top,
                                   getTextureRect().width,
                                   getTextureRect().height ));
}

void InteractableSprite::addTime(float delta) {
    totalelapsed += delta;
}






