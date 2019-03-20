//
//  MountainSouth.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MountainSouth.hpp"

MountainSouth::MountainSouth(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::MountainSouth, NoMusic, sf::Vector2f(375 * scale, 125 * scale)) {
	background.setTexture(resources.getTexture(Textures::MountainSouth));
	background.setScale(scale, scale);
	
	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(0, -100, 125 * scale, 100),
					   sf::Vector2f(0, -mapClearance), MapID::MountainWest);			//top left
	exits.emplace_back(sf::FloatRect(125 * scale, -100, 230 * scale, 100),
					   sf::Vector2f(0, -mapClearance), MapID::MountainEast);			//top right
	exits.emplace_back(sf::FloatRect(-100, 0, 100, totalArea.y),
					   sf::Vector2f(-mapClearance, 0), MapID::BeachNorth);				//entire left
	exits.emplace_back(sf::FloatRect(totalArea.x, 0, 100, totalArea.y),
					   sf::Vector2f(mapClearance, 0), MapID::TownEast);					//entire right
	exits.emplace_back(sf::FloatRect(0, totalArea.y, 100 * scale, 100),
					   sf::Vector2f(0, mapClearance), MapID::Start);					//bottom left
	exits.emplace_back(sf::FloatRect(100 * scale, totalArea.y, 255 * scale, 100),
					   sf::Vector2f(0, mapClearance), MapID::Forest);					//bottom right
	
}
