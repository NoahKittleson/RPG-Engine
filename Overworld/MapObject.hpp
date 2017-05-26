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
//#include "PhysicsComponent.hpp"
//#include "InputComponent.hpp"

class GraphicsComponent;
class PhysicsComponent;

class MapObject {
public:
    MapObject(GraphicsComponent* gc, PhysicsComponent* pc);
	
    void setPosition(float x, float y);
    sf::Vector2f getPosition();                     //I might not want to even commit to something as simple as these...
    int getBase() const;
    void drawBase(sf::RenderWindow &rw) const;
    void addTime(float delta);

    void update(float elapsed);
    void draw(sf::RenderWindow &rw);
	
	//physics
	void collideX(MapObject &PC, sf::Vector2f moveVec);
	void collideY(MapObject &PC, sf::Vector2f moveVec);

	
private:
    GraphicsComponent* graphics;
    PhysicsComponent* physics;
    //InputComponent* input;
	
	//physics component
	const std::vector<sf::IntRect> collisionBoxes;
	
};
