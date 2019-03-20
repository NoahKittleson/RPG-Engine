//
//  TownEast.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "TownEast.hpp"


TownEast::TownEast(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::TownEast, NoMusic, sf::Vector2f(730 * scale, 125 * scale)) {
	background.setTexture(resources.getTexture(Textures::TownEast));
	background.setScale(scale, scale);
	
	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(0, -100, totalArea.x, 100),
					   sf::Vector2f(0, -mapClearance), MapID::MountainEast);			//top
	exits.emplace_back(sf::FloatRect(-100, 0, 100, 225 * scale),
					   sf::Vector2f(-mapClearance, 0), MapID::MountainSouth);			//top left
	exits.emplace_back(sf::FloatRect(-100, 225 * scale, 100, 65 * scale),
					   sf::Vector2f(-mapClearance, 0), MapID::Forest);					//bottom left
	exits.emplace_back(sf::FloatRect(0, totalArea.y, totalArea.x, 100),
					   sf::Vector2f(0, mapClearance), MapID::Swamp);					//bottom

	
}
