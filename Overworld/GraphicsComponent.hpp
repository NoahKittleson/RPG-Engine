//
//  GraphicsComponent.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "AudioHandler.hpp"


class GraphicsComponent : public sf::Sprite
{
public:
	virtual ~GraphicsComponent() {}
    GraphicsComponent (const sf::Texture& texture, sf::Vector2f position);
//	GraphicsComponent(GraphicsComponent&&) = default;
//	GraphicsComponent(const GraphicsComponent& obj) = default;  // copy constructor
//	GraphicsComponent& operator=(GraphicsComponent other) { return *this;};	//copy assignment constructor

	virtual std::unique_ptr<GraphicsComponent> getCopy();
	
    virtual void update(float elapsed);
    virtual void addTime(float delta);
	virtual int getBase() const;
	virtual void offsetBase(float x);
	
	virtual void drawCropped(int pixelCropX, int pixelCropY, sf::RenderWindow &rw);
	//^^^crops from right/bottom, unless negative, in which case crops from left/top
	
	virtual void attachAudio(AudioHandler& audio);
	
protected:
	AudioHandler* audio = nullptr;

private:
	float baseOffset = 0.f;
	
};
