//
//  AnimatedSprite.cpp
//  BattleMode
//
//  Created by Noah Kittleson on 6/2/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite(const sf::Vector2i& FrameSize, float TimePerFrame, const sf::Texture& texture, float repeatDelay)
: _frameSize(sf::IntRect(0, 0, FrameSize.x, FrameSize.y)), _timePerFrame(TimePerFrame), repeatDelay(repeatDelay)
{
    this->setTexture(texture);
//    if (getTexture()) {
//        std::cout << "initialized with ptr\n";
//    } else
//    std::cout << "initialized with NULLptr\n";
    this->setTextureRect(_frameSize);
    setOrigin(FrameSize.x/2, FrameSize.y/2);
}


AnimatedSprite::AnimatedSprite(const AnimatedSprite& other)
: _frameSize(other._frameSize), repeatDelay(other.repeatDelay),
_timePerFrame(other._timePerFrame), _totalelapsed(other._totalelapsed)
{
    setTexture(*other.getTexture());
    setPosition(other.getPosition());
    setScale(other.getScale());
}

void AnimatedSprite::update(float elapsed)       //non looped animation stays on final frame
{
    //don't handle cases of impossible timePerFrames
    if (_timePerFrame <= 0) {
        return;
    }
    _totalelapsed += elapsed;
    
    if (!waiting || _totalelapsed >= repeatDelay) {
        waiting = false;
        while (_totalelapsed >= _timePerFrame) {
            _totalelapsed -= _timePerFrame;
            if (repeatDelay && atEnd()) {
                waiting = true;
                return;
            }
            next_frame();
        }
    }
}

void AnimatedSprite::next_frame()
{
    if (atEnd()) {
        setTextureRect(_frameSize);
    }
    else setTextureRect(sf::IntRect(getTextureRect().left + _frameSize.width,
                                    getTextureRect().top,
                                    getTextureRect().width,
                                    getTextureRect().height ));
}

bool AnimatedSprite::atEnd() {
    if (getTextureRect().left + _frameSize.width >= getTexture()->getSize().x) {
        return true;
    }
    return false;
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







