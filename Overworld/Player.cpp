//
//  Player.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/28/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "Player.h"

//Player Constructor is very hacky, but will work for now.
//Later, have it initialized with a sprite from ResourceHolder
Player::Player(const ResourceHolder& resources)
    : MapSprite(sf::IntRect(0,0,16,16), 0.1f), walkingState(Stand),
    walkUp(&resources.getTexture("PlayerWalkingUp.png")), walkDown(&resources.getTexture("PlayerWalkingDown.png")),
    walkLeft(&resources.getTexture("PlayerWalkingLeft.png")), walkRight(&resources.getTexture("PlayerWalkingRight.png"))
{
    setTexture(*walkDown);
    int textureHeight = walkDown->getSize().y;
    
    frameSize = sf::IntRect(0,0,textureHeight, textureHeight);
    setTextureRect(frameSize);
    setOrigin(textureHeight/2, textureHeight/2);
    box = sf::IntRect(-textureHeight/4, -textureHeight/2,
                        textureHeight/2, textureHeight);
    setPosition(100, 100);
}

sf::IntRect Player::getAbsBox() {
    auto position = getPosition();
    auto scale = getScale().x;
    sf::IntRect absolutePosition (position.x + box.left * scale,
                                    position.y + box.top * scale,
                                    box.width * scale,
                                    box.height * scale);
    return absolutePosition;
}

void Player::update(sf::Vector2f moveVec, float elapsed) {
    if (!moveVec.y && !moveVec.x) {
        changeState(Stand);
        //delete return if I make an idle animation
        return;
    }
    
    if (moveVec.y < 0) {
        changeState(Up);
    } else if (moveVec.y > 0) {
        changeState(Down);
    }
    if (moveVec.x < 0) {
        changeState(Left);
    } else if (moveVec.x > 0) {
        changeState(Right);
    }
    animate(elapsed);
}

void Player::changeState(Player::Direction newDir) {
    if (walkingState == newDir) {
        return;
    }
    else switch (newDir) {
        case Up:
            setTexture(*walkUp);
            break;
            
        case Down:
            setTexture(*walkDown);
            break;
            
        case Left:
            setTexture(*walkLeft);
            break;
            
        case Right:
            setTexture(*walkRight);
            break;
            
        default:
            //right now this catches Stand.  Create case Stand if I add idle animation.
            break;
    }
}
