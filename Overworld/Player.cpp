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
    walkUp.loadFromFile(resourcePath() + "PlayerWalkingUp.png");
    walkDown.loadFromFile(resourcePath() + "PlayerWalkingDown.png");
    walkRight.loadFromFile(resourcePath() + "PlayerWalkingRight.png");
    setTexture(texture);
    //float textureLength = texture.getSize().x;        //all sprites are square.
    float textureHeight = texture.getSize().y;
    
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

int Player::getBase() const {
    return getPosition().y + (getTextureRect().height * getScale().y) - (getOrigin().y * getScale().y);
}

void Player::drawBase(sf::RenderWindow &rw) {
    sf::RectangleShape rect (sf::Vector2f(20, 1));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(getPosition().x, getBase());
    rw.draw(rect);
}

void Player::update(sf::Vector2f moveVec, float elapsed) {
    if (moveVec.x > 0) {
        setTexture(walkRight);
        //setScale(std::abs(getScale().x), getScale().y);
    } else if (moveVec.x < 0) {
        setTexture(walkRight);
        //setScale(-std::abs(getScale().x), getScale().y);
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

void Player::animate(float elapsed) {
    if (timePerFrame == 0) return;
    totalElapsed+= elapsed;
    while (totalElapsed >= timePerFrame) {
        totalElapsed -= timePerFrame;
        nextFrame();
    }
}

void Player::nextFrame() {
    if (getTextureRect().left + frameSize.width >= getTexture()->getSize().x) {
        setTextureRect(frameSize);
    }
    else setTextureRect(sf::IntRect(getTextureRect().left + frameSize.width,
                                    getTextureRect().top,
                                    getTextureRect().width,
                                    getTextureRect().height ));
}
