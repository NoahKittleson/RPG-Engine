//
//  BeachSouth.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "BeachSouth.hpp"


BeachSouth::BeachSouth(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::BeachSouth, None, sf::Vector2f(0, 750 * scale)) {
	background.setTexture(resources.getTexture(Textures::BeachSouth));
	background.setScale(scale, scale);
	
	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(0, -100, 200 * scale, 100),
					   sf::Vector2f(0, -mapClearance), MapID::BeachWest);			//top left
	exits.emplace_back(sf::FloatRect(200 * scale, -100, 275 * scale, 100),
					   sf::Vector2f(0, -mapClearance), MapID::SouthOfStart);		//top right
	exits.emplace_back(sf::FloatRect(totalArea.x, 0, 100, totalArea.y),
					   sf::Vector2f(mapClearance, 0), MapID::TownSouth);			//entire right

	
	
}
