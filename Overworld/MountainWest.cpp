//
//  MountainWest.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MountainWest.hpp"

MountainWest::MountainWest(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::MountainWest, "") {
	background.setTexture(resources.getTexture(Textures::MountainWest));
	background.setScale(scale, scale);

	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(totalArea.x, 0, 100, totalArea.y),
					   sf::Vector2f(-totalArea.x + mapClearance, 0), MapID::MountainEast);				//entire right
	exits.emplace_back(sf::FloatRect(0, totalArea.y, 375 * scale, 100),
					   sf::Vector2f(0, -totalArea.y + mapClearance), MapID::BeachNorth);				//bottom left
	exits.emplace_back(sf::FloatRect(375 * scale, totalArea.y, (totalArea.x - 375) * scale, 100),
					   sf::Vector2f(-375 * scale, -totalArea.y + mapClearance), MapID::MountainSouth);	//bottom left
	
}
