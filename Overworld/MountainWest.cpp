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
	
	MapID zoneID = MapID::Start;
	exits.emplace_back(sf::FloatRect(0,-100,totalArea.x,100), sf::Vector2f(0,totalArea.y-150), zoneID);
	exits.emplace_back(sf::FloatRect(-100,0,100,totalArea.y), sf::Vector2f(totalArea.x-150,0), zoneID);
	exits.emplace_back(sf::FloatRect(totalArea.x,0,100,totalArea.y), sf::Vector2f(-totalArea.x+150,0), zoneID);
	exits.emplace_back(sf::FloatRect(0,totalArea.y,totalArea.x,100), sf::Vector2f(0,-totalArea.y+150), zoneID);
	
}
