//
//  GraphicsComponent.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "GraphicsComponent.hpp"

GraphicsComponent::GraphicsComponent(sf::Texture& texture, sf::Vector2f position)
{
    setTexture(texture);
    setPosition(position);
}


void GraphicsComponent::update(MapObject& obj, float elapsed) {
    return;
}

void GraphicsComponent::addTime(float delta) {
    return;
}

