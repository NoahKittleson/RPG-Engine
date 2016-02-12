//
//  InteractableObject.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/21/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "InteractableObject.h"


VisualObject::VisualObject(const sf::Texture& texture, sf::Vector2f position)
{
    spr.setTexture(texture);
	spr.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
	spr.setPosition(position);
}

void VisualObject::draw(sf::RenderWindow &rw) const
{
	rw.draw(spr);
}

sf::Vector2f VisualObject::getPosition() const
{
    return spr.getPosition();
}

//float VisualObject::getBasePosition() const
//{
//	return spr.getPosition().y + spr.getTextureRect().height * spr.getScale().y/2;
//}

void VisualObject::setPosition(float x, float y)
{
	spr.setPosition(x, y);
}

void VisualObject::move(float x, float y)
{
	spr.move(x, y);
}

void VisualObject::setScale(float x)
{
	spr.setScale(x, x);
}

void VisualObject::setFrame(int frameNo)
{
	if (spr.getTexture()->getSize().x == 0 || spr.getTexture()->getSize().y == 0) {
		return;
	}
	
	if (frameNo >= spr.getTexture()->getSize().x/spr.getTexture()->getSize().y) {
		return;
	}
	spr.setTextureRect(sf::IntRect(spr.getTexture()->getSize().y*frameNo,
								   0,
								   spr.getTexture()->getSize().y,
								   spr.getTexture()->getSize().y));
}

void VisualObject::nextFrame()
{
	spr.setTextureRect(sf::IntRect(spr.getTextureRect().height + spr.getTextureRect().left,
									   0,
									   spr.getTextureRect().height,
									   spr.getTextureRect().height));
	if (spr.getTextureRect().left >= spr.getTexture()->getSize().x) {
		setFrame(0);
	}
}

InteractableObject::InteractableObject(const sf::Texture& texture, sf::Vector2f position, std::list<sf::FloatRect>& collisionList)
: VisualObject(texture, position)
{
	for (auto && it: collisionList) {
		sf::Vector2f absolutePosition (it.left + position.x - texture.getSize().x/2, it.top + position.y - texture.getSize().y/2);
		collisionBoxList.emplace_back(absolutePosition.x, absolutePosition.y, it.width, it.height);
	}
}

void InteractableObject::setScale(float x)
{
	spr.setScale(x, x);
	for (auto && it: collisionBoxList)			//I thought floatRect's members were const?
	{
		it.width *= x;
		it.height *= x;
		it.top = (it.top - spr.getPosition().y) * x;
		it.left = (it.left - spr.getPosition().x) * x;
	}
}

void InteractableObject::DrawCollisionBoxes(sf::RenderWindow &rw)
{
	sf::RectangleShape Rectangle;
	Rectangle.setFillColor(sf::Color::Red);
	for (auto && it: collisionBoxList)
	{
		Rectangle.setSize(sf::Vector2f(it.width, it.height));
		Rectangle.setPosition(it.left, it.top);
		rw.draw(Rectangle);
	}
}

bool InteractableObject::intersects(sf::FloatRect item)
{
	for (auto && box: collisionBoxList) {
		if (box.intersects(item)) {
			return true;
		}
	}
	return false;
}

const std::list<sf::FloatRect>& InteractableObject::getCollisionBoxList() const
{
	return collisionBoxList;
}

DialogueThread* InteractableObject::getDialogue()
{
	return whatItSays;
}

void InteractableObject::addDialogue(DialogueThread &add)
{
	whatItSays = &add;
}



Player::Player(const sf::Texture& tex, sf::Vector2f position)
: VisualObject(tex, position), collisionBox(tex.getSize().y/-4.f,			//all use height because length includes other frames.
											tex.getSize().y/-4.f,
											tex.getSize().y/2,
											tex.getSize().y/2 )
{
	spr.setTexture(tex);
	spr.setOrigin(spr.getTextureRect().height/2, spr.getTextureRect().height/2);
}

void Player::move(float x, float y)
{
	spr.move(x, y);
}

sf::FloatRect Player::getAbsCollisionBox() const
{
	auto position = spr.getPosition();
	auto scale = spr.getScale().x;
	sf::FloatRect absolutePosition (position.x + collisionBox.left * scale,
									position.y + collisionBox.top * scale,
									collisionBox.width * scale,
									collisionBox.height * scale);
	return absolutePosition;
}












