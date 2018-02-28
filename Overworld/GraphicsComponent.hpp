//
//  GraphicsComponent.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "MapObject.hpp"


class MapObject;

class GraphicsComponent : public sf::Sprite
{
public:
    virtual ~GraphicsComponent() {}
    GraphicsComponent (const sf::Texture& texture, sf::Vector2f position);
    virtual void update(float elapsed);
    virtual void addTime(float delta);
	virtual int getBase() const;
	virtual void offsetBase(float x);
	
private:
	float baseOffset = 0.f;
	

};
