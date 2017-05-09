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
    _sprite.setTexture(texture);
    _sprite.setTextureRect(_frameSize);
    _sprite.setOrigin(FrameSize.x/2, FrameSize.y/2);
}

AnimatedSprite::AnimatedSprite(const AnimatedSprite& other)
: _sprite(other._sprite), _frameSize(other._frameSize), _nextAnimation(other._nextAnimation),
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
    if (_sprite.getTextureRect().left + _frameSize.width >= _sprite.getTexture()->getSize().x) {
        _sprite.setTextureRect(_frameSize);
        if (_nextAnimation) {
            setTexture(*_nextAnimation);
        }
    }
    else
        _sprite.setTextureRect(sf::IntRect(_sprite.getTextureRect().left + _frameSize.width,
                                           _sprite.getTextureRect().top,
                                           _sprite.getTextureRect().width,
                                           _sprite.getTextureRect().height ));
}

void AnimatedSprite::setTexture(const sf::Texture& texture)
{
    _sprite.setTexture(texture);
    _sprite.setTextureRect(_frameSize);
    
    while (_totalelapsed > _timePerFrame) {
        _totalelapsed -= _timePerFrame;
    }
}

void AnimatedSprite::setScale(float xfactor, float yfactor)
{
    _sprite.setScale(xfactor, yfactor);
}

void AnimatedSprite::move(sf::Vector2f coor)
{
    _sprite.move(coor);
}

void AnimatedSprite::setPosition(float x, float y)
{
    _sprite.setPosition(x, y);
}

sf::Vector2f AnimatedSprite::getPosition()
{
    return _sprite.getPosition();
}

void AnimatedSprite::setNextAnimation(const sf::Texture& next)
{
    _nextAnimation = &next;
}

bool AnimatedSprite::compare(const sf::Texture* other)            //compares addresses.
{
    if (other == _sprite.getTexture()) {
        return true;
    }
    return false;
}

char AnimatedSprite::isOnFrame()        //first frame = 0
{
    return _sprite.getTextureRect().left/_frameSize.width;
}

void AnimatedSprite::draw(sf::RenderWindow &rw)
{
    rw.draw(_sprite);
}







