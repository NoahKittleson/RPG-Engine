//
//  GraphicsComponent.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "GraphicsComponent.hpp"

GraphicsComponent::GraphicsComponent(const sf::Texture& texture, sf::Vector2f position)
{
	setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    setTexture(texture);
    setPosition(position);
}


void GraphicsComponent::update(MapObject& obj, float elapsed) {
    return;
}

void GraphicsComponent::addTime(float delta) {
    return;
}

int GraphicsComponent::getBase() const {
	return getPosition().y + (getTextureRect().height * getScale().y) -(getOrigin().y * getScale().y);
}

