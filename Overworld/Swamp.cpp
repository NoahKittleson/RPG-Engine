//
//  Swamp.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "Swamp.hpp"

Swamp::Swamp(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::Swamp, NoMusic, sf::Vector2f(730 * scale, 415 * scale)) {
	background.setTexture(resources.getTexture(Textures::Swamp));
	background.setScale(scale, scale);
	
	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(0, -100, totalArea.x, 100),
					   sf::Vector2f(0, -mapClearance), MapID::TownEast);			//entire top
	exits.emplace_back(sf::FloatRect(-100, 0, 100, 230 * scale),
					   sf::Vector2f(-mapClearance, 0), MapID::Forest);				//top left
	exits.emplace_back(sf::FloatRect(-100, 230 * scale, 100, 40 * scale),
					   sf::Vector2f(-mapClearance, 0), MapID::TownSouth);			//bottom left
	exits.emplace_back(sf::FloatRect(0, totalArea.y, totalArea.x, 100),
					   sf::Vector2f(0, mapClearance), MapID::LighthouseCoast);		//entire bottom
	
	
}
