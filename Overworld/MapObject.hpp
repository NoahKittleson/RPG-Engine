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
#include "DNode.h"
//#include "InputComponent.hpp"

using RectVec = std::vector<sf::IntRect>;

class GraphicsComponent;

class MapObject {
public:
	MapObject(GraphicsComponent* gc, RectVec collision);
	~MapObject();
	MapObject(const MapObject& obj);  // copy constructor
	
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    void update(float elapsed);
	
	//graphics
    void draw(sf::RenderWindow &rw) const;
	void addTime(float delta);
	int getBase() const;
	void drawBase(sf::RenderWindow &rw) const;
	void setScale(float);
	void move(float x, float y);
	void move(sf::Vector2f xy);
	
	//physics
	void collideX(MapObject &PC, float x) const;
	void collideY(MapObject &PC, float y) const;
	void drawCollision(sf::RenderWindow& rw);
	bool intersects(sf::IntRect);
	
	//dialogue
	DNode* getDNode() const;
	
private:
	//graphics
    GraphicsComponent* graphics;
	
	//physics
	RectVec collisionBoxes;
	
	//input
	//InputComponent* input;
	
	//interaction
	//DialogueComponent* dialogue;
	
	
	//where do I store the walkingState?
	
};
