//
//  AnimatedSprite.cpp
//  BattleMode
//
//  Created by Noah Kittleson on 6/2/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite(const sf::Vector2i& FrameSize, float TimePerFrame, const sf::Texture& texture)
: _frameSize(sf::IntRect(0, 0, FrameSize.x, FrameSize.y)), _timePerFrame(TimePerFrame)
{
    this->setTexture(texture);
    this->setTextureRect(_frameSize);
    setOrigin(FrameSize.x/2, FrameSize.y/2);
}

AnimatedSprite::AnimatedSprite(const AnimatedSprite& other)
: _frameSize(other._frameSize), _nextAnimation(other._nextAnimation),
_timePerFrame(other._timePerFrame), _totalelapsed(other._totalelapsed)
{
    
}

void AnimatedSprite::animate(float elapsed)       //non looped animation stays on final frame
{
    _totalelapsed += elapsed;
    while (_totalelapsed >= _timePerFrame) {
        _totalelapsed -= _timePerFrame;
        next_frame();
    }
}

void AnimatedSprite::next_frame()
{
    if (getTextureRect().left + _frameSize.width >= getTexture()->getSize().x) {
        setTextureRect(_frameSize);
        if (_nextAnimation) {
            setTexture(*_nextAnimation);
        }
    }
    else
        setTextureRect(sf::IntRect(getTextureRect().left + _frameSize.width,
                                   getTextureRect().top,
                                   getTextureRect().width,
                                   getTextureRect().height ));
}

void AnimatedSprite::setTexture(const sf::Texture& texture)
{
    //will this cause infinite loop?  I only want to call base class setTexture
    sf::Sprite::setTexture(texture);
    setTextureRect(_frameSize);

}

void AnimatedSprite::setNextAnimation(const sf::Texture& next)
{
    _nextAnimation = &next;
}

bool AnimatedSprite::compare(const sf::Texture* other)            //compares addresses.
{
    if (other == getTexture()) {
        return true;
    }
    return false;
}

char AnimatedSprite::isOnFrame()        //first frame = 0
{
    return getTextureRect().left/_frameSize.width;
}







