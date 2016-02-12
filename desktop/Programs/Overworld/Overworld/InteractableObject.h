//
//  InteractableObject.h
//  Overworld
//
//  Created by Noah Kittleson on 4/21/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "DialogueThread.h"
#include "PrefixHeader.pch"

class VisualObject
{
public:
	VisualObject(const sf::Texture&, sf::Vector2f);
    
    void draw(sf::RenderWindow &rw) const;
    sf::Vector2f getPosition() const;
	//virtual float getBasePosition() const;
	void setPosition(float x, float y);
	void move(float x, float y);
	virtual void setScale(float x);
	
	void setFrame(int frameNo);
	void nextFrame();
	
protected:
	sf::Sprite spr;
};

class InteractableObject: public VisualObject
{
public:
	InteractableObject(const sf::Texture&, sf::Vector2f, std::list<sf::FloatRect>&);
	
    void DrawCollisionBoxes(sf::RenderWindow &rw);
	void setScale(float x);
	bool intersects(sf::FloatRect);
	const std::list<sf::FloatRect>& getCollisionBoxList() const;
	DialogueThread* getDialogue();
	void addDialogue(DialogueThread&);
	
private:
	DialogueThread* whatItSays = nullptr;
	std::list<sf::FloatRect> collisionBoxList;
	
};

class Player: public VisualObject
{
public:
	Player(const sf::Texture&, sf::Vector2f);
	void move(float x, float y);
	sf::FloatRect getAbsCollisionBox() const;
	
private:
	const sf::FloatRect collisionBox;
	//float getBasePosition() const override;
};





