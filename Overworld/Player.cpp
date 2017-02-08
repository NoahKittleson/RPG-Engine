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
Player::Player() {
    texture.loadFromFile(resourcePath() + "Stickmaniac.png");
    walkUp.loadFromFile(resourcePath() + "playerWalkUp.png");
    walkDown.loadFromFile(resourcePath() + "playerWalkDown.png");
    walkRight.loadFromFile(resourcePath() + "playerWalkRight.png");
    setTexture(texture);
    float textureLength = texture.getSize().x;
    float textureHeight = texture.getSize().y;
    box = sf::FloatRect(-textureLength/4, -textureHeight/4,
                        textureLength/2, textureHeight/2);
    setOrigin(textureLength/2, textureHeight/2);
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

int Player::getBase() const {
    return getPosition().y + getTextureRect().height/2;
}

void Player::update(sf::Vector2f moveVec) {
    if (moveVec.x > 0) {
        setTexture(walkRight);
    } else if (moveVec.x < 0) {
        setScale(-getScale().x, getScale().y);
    }
    if (moveVec.y > 0) {
        setTexture(walkUp);
    } else if (moveVec.y > 0) {
        setTexture(walkDown);
    }
}
