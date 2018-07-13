//
//  Forest.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "Forest.hpp"

Forest::Forest(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::Forest, "", sf::Vector2f(550 * scale, 350 * scale)) {
	background.setTexture(resources.getTexture(Textures::Forest));
	background.setScale(scale, scale);
	
	//A Dead Tree (or is it?)
	std::vector<sf::FloatRect> boxList;
	boxList.emplace_back(-9 * scale, 10 * scale, 20 * scale, 7 * scale);
	MapObject deadTree (make_unique<GraphicsComponent>(resources.getTexture(Textures::DeadTree), sf::Vector2f (200,200)), boxList);
	deadTree.setScale(scale);
	addObject(deadTree);
	boxList.clear();
	
	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(0, -100, totalArea.x, 100),
					   sf::Vector2f(0, -mapClearance), MapID::MountainSouth);		//entire top
	exits.emplace_back(sf::FloatRect(-100, 0, 100, 150 * scale),
					   sf::Vector2f(-mapClearance, 0), MapID::Start);				//top left
	exits.emplace_back(sf::FloatRect(-100, 150 * scale, 100, 125 * scale),
					   sf::Vector2f(-mapClearance, 0), MapID::SouthOfStart);		//bottom left
	exits.emplace_back(sf::FloatRect(totalArea.x, 0, 100, 45 * scale),
					   sf::Vector2f(mapClearance, 0), MapID::TownEast);				//top right
	exits.emplace_back(sf::FloatRect(totalArea.x, 45 * scale, 100, 230 * scale),
					   sf::Vector2f(mapClearance, 0), MapID::Swamp);				//bottom right
	exits.emplace_back(sf::FloatRect(0, totalArea.y, totalArea.x, 100),
					   sf::Vector2f(0, mapClearance), MapID::TownSouth);			//entire bottom
	
	
}
