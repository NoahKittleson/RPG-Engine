//
//  AnimationSheet.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/20/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "AnimationSheet.hpp"


void AnimationSheet::setIdle(const sf::Texture& texture) {
	idle = &texture;
}
const sf::Texture* AnimationSheet::getIdle() const {
	return idle;
}
void AnimationSheet::setDead(const sf::Texture& texture) {
	dead = &texture;
}
const sf::Texture* AnimationSheet::getDead() const {
	return dead;
}
void AnimationSheet::setGetHit(const sf::Texture& texture) {
	getHit = &texture;
}
const sf::Texture* AnimationSheet::getGetHit() const {
	return getHit;
}
void AnimationSheet::setGetKilled(const sf::Texture& texture) {
	getKilled = &texture;
}
const sf::Texture* AnimationSheet::getGetKilled() const {
	return getKilled;
}
