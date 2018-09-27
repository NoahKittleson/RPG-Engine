//
//  MountainEast.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MountainEast.hpp"


MountainEast::MountainEast(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::MountainEast, None, sf::Vector2f(500 * scale,0)) {
	background.setTexture(resources.getTexture(Textures::MountainEast));
	background.setScale(scale, scale);
	
	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(-100, 0, 100, totalArea.y),
					   sf::Vector2f(-mapClearance, 0), MapID::MountainWest);			//entire left
	exits.emplace_back(sf::FloatRect(0, totalArea.y, 230 * scale, 100),
					   sf::Vector2f(0, mapClearance), MapID::MountainSouth);			//bottom left
	exits.emplace_back(sf::FloatRect(230 * scale, totalArea.y, totalArea.x - (230 * scale), 100),
					   sf::Vector2f(0, mapClearance), MapID::TownEast);					//bottom right
	
}
