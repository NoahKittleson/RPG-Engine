//
//  MapObject.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "GraphicsComponent.hpp"
//#include "InputComponent.hpp"
//#include "PhysicsComponent.hpp"

class GraphicsComponent;

class MapObject {
public:
    MapObject(GraphicsComponent* gc);
    
    void setPosition(float x, float y);
    sf::Vector2f getPosition();                     //I might not want to even commit to something as simple as these...
    int getBase() const;
    void drawBase(sf::RenderWindow &rw) const;
    void addTime(float delta);

    
    void update(float elapsed);
    void draw(sf::RenderWindow &rw);
    
private:
    GraphicsComponent* graphics;
    //Maybe consider doing these later?
    //PhysicsComponent* physics;
    //InputComponent* input;
    
};
