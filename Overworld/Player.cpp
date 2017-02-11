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
Player::Player() : MapSprite(sf::IntRect(0,0,16,16), 0.1f) {                //cheating.
    walkUp.loadFromFile(resourcePath() + "PlayerWalkingUp.png");
    walkDown.loadFromFile(resourcePath() + "PlayerWalkingDown.png");
    walkLeft.loadFromFile(resourcePath() + "PlayerWalkingLeft.png");
    walkRight.loadFromFile(resourcePath() + "PlayerWalkingRight.png");
    setTexture(walkDown);
    //float textureLength = texture.getSize().x;        //all sprites are square.
    float textureHeight = walkDown.getSize().y;
    
    frameSize = sf::IntRect(0,0,textureHeight, textureHeight);
    setTextureRect(frameSize);
    setOrigin(textureHeight/2, textureHeight/2);
    box = sf::FloatRect(-textureHeight/4, -textureHeight/2,
                        textureHeight/2, textureHeight);
    setPosition(100, 100);
}

sf::FloatRect Player::getAbsBox() {
    auto position = getPosition();
    auto scale = getScale().x;
    sf::FloatRect absolutePosition (position.x + box.left * scale,
                                    position.y + box.top * scale,
                                    box.width * scale,
                                    box.height * scale);
    return absolutePosition;
}

void Player::update(sf::Vector2f moveVec, float elapsed) {
    if (moveVec.x > 0) {
        setTexture(walkRight);
    } else if (moveVec.x < 0) {
        setTexture(walkLeft);
    }
    if (moveVec.y < 0) {
        setTexture(walkUp);
    } else if (moveVec.y > 0) {
        setTexture(walkDown);
    }
    
    //animate only if player moves
    if (moveVec.y || moveVec.x) {
        animate(elapsed);
    }
}
