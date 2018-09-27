//
//  SouthOfStart.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "SouthOfStart.hpp"

SouthOfStart::SouthOfStart(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::SouthOfStart, None, sf::Vector2f(200 * scale, 500 * scale)) {
	background.setTexture(resources.getTexture(Textures::SouthOfStart));
	background.setScale(scale, scale);
	
	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(0, -100, totalArea.x, 100),
					   sf::Vector2f(0, -mapClearance), MapID::Start);				//entire top
	exits.emplace_back(sf::FloatRect(-100, 0, 100, totalArea.y),
					   sf::Vector2f(-mapClearance, 0), MapID::BeachWest);			//entire left
	exits.emplace_back(sf::FloatRect(totalArea.x, 0, 100, 125 * scale),
					   sf::Vector2f(mapClearance, 0), MapID::Forest);				//top right
	exits.emplace_back(sf::FloatRect(totalArea.x, 125 * scale, 100, 125 * scale),
					   sf::Vector2f(mapClearance, 0), MapID::TownSouth);			//bottom right
	exits.emplace_back(sf::FloatRect(0, totalArea.y, totalArea.x, 100),
					   sf::Vector2f(0, mapClearance), MapID::BeachSouth);			//entire bottom
	
	
}
