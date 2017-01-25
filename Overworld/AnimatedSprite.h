//
//  AnimatedSprite.h
//  BattleMode
//
//  Created by Noah Kittleson on 6/2/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class AnimatedSprite            //shouldn't this extend from sprite?
{
public:
    AnimatedSprite(const sf::Vector2i&, float, const sf::Texture& texture);
    AnimatedSprite(const AnimatedSprite& other);
    
    void animate(float elapsed, sf::RenderWindow &rw);
    void setTexture(const sf::Texture&);
    void setScale(float, float);
    void setPosition(float x, float y);
    void move(sf::Vector2f);
    void setNextAnimation(const sf::Texture&);
    bool compare(const sf::Texture*);                         //true if same texture, false if not.
    sf::Vector2f getPosition();
    char isOnFrame();
    void draw(sf::RenderWindow &rw);
    
private:
    void next_frame();
    
    sf::Sprite _sprite;
    const sf::IntRect _frameSize;
    const sf::Texture* _nextAnimation = nullptr;  //nullptr: loops, ptr = non-looping, change to this after animation ends.
    
    const float _timePerFrame;
    float _totalelapsed = 0;
};
