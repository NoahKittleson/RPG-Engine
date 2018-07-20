//
//  AnimationSheet.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/20/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class AnimationSheet {
public:
	void setIdle(const sf::Texture&);
	const sf::Texture* getIdle() const;
	void setDead(const sf::Texture&);
	const sf::Texture* getDead() const;
	void setGetHit(const sf::Texture&);
	const sf::Texture* getGetHit() const;
	void setGetKilled(const sf::Texture&);
	const sf::Texture* getGetKilled() const;
	
private:
	const sf::Texture* idle = nullptr;
	//sf::Texture* lowHealthIdle = nullptr;
	const sf::Texture* dead = nullptr;
	const sf::Texture* getHit = nullptr;
	const sf::Texture* getKilled = nullptr;
};
