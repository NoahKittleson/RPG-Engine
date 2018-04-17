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

class GraphicsComponent;

using RectVec = std::vector<sf::FloatRect>;
using graphicsPtr = std::unique_ptr<GraphicsComponent>;

class MapObject {
public:
	MapObject(graphicsPtr&& gc, RectVec collision);
	~MapObject();
	MapObject(const MapObject& obj);  // copy constructor
	
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    void update(float elapsed);
	
	//graphics
    void draw(sf::RenderWindow &rw) const;
	void addTime(float delta);
	void setScale(float);
	void move(float x, float y);
	void move(sf::Vector2f xy);
	void offsetBase(float x);
	
	//physics
	int getBase() const;
	void drawBase(sf::RenderWindow &rw) const;
	void drawCenter(sf::RenderWindow & rw) const;
	void drawCollision(sf::RenderWindow& rw) const;
	
	void collideX(MapObject &PC, float x) const;
	void collideY(MapObject &PC, float y) const;
	bool intersects(sf::FloatRect) const;
	
	//dialogue
	DNode* getDNode() const;
	void addDialogue(std::unique_ptr<DNode> toAdd);
	
protected:
	//graphics
	graphicsPtr graphics;
	
	//physics
	RectVec collisionBoxes;
	
	//interaction
	//DialogueComponent* dialogue;
	//DNode* dialogue;
	std::vector<std::unique_ptr<DNode>> dialogues;
	//what if I instead had the whole list of DialogueNodes that this guy will use?
	
	//where do I store the walkingState?
};

