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

std::unique_ptr<GraphicsComponent> GraphicsComponent::getCopy() {
	return std::unique_ptr<GraphicsComponent> (new GraphicsComponent (*this));
}

void GraphicsComponent::update(float elapsed) {
    return;
}

void GraphicsComponent::addTime(float delta) {
    return;
}

int GraphicsComponent::getBase() const {
	return getPosition().y + (getTextureRect().height * getScale().y) -(getOrigin().y * getScale().y) + baseOffset;
}

void GraphicsComponent::offsetBase(float x) {
	baseOffset += x;
}

