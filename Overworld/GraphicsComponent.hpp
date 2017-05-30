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

class GraphicsComponent : public sf::Sprite                 //this might be a bad idea.  If it is then just make Sprite a member
{
public:
    virtual ~GraphicsComponent() {}
    GraphicsComponent (const sf::Texture& texture, sf::Vector2f position);
    virtual void update(MapObject& obj, float elapsed);         //I never use the Obj item called in.  Will I in the future?
    virtual void addTime(float delta);

};
