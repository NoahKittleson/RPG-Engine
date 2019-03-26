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

void GraphicsComponent::drawCropped(int pixelCropX, int pixelCropY, sf::RenderWindow &rw) {
	const sf::IntRect original = getTextureRect();
	sf::IntRect cropped = original;
	if (pixelCropX > 0) {
		cropped.width -= pixelCropX;
	} else {
		cropped.left -= pixelCropX;
		cropped.width += pixelCropX;
	}
	if (pixelCropY > 0) {
		cropped.height -= pixelCropY;
	} else {
		cropped.top -= pixelCropY;
		cropped.height += pixelCropY;
	}
	setTextureRect(cropped);

	rw.draw(*this);
	setTextureRect(original);
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

float GraphicsComponent::getBase() const {
	return getPosition().y + (getTextureRect().height * getScale().y) -(getOrigin().y * getScale().y) + baseOffset;
}

void GraphicsComponent::offsetBase(float x) {
	baseOffset += x;
}

void GraphicsComponent::attachAudio(AudioHandler& attachMe) {
	audio = &attachMe;
}


