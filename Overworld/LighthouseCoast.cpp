//
//  LighthouseCoast.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "LighthouseCoast.hpp"


LighthouseCoast::LighthouseCoast(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::LighthouseCoast, "", sf::Vector2f(730 * scale, 720 * scale)) {
	background.setTexture(resources.getTexture(Textures::LightHouseCoast));
	background.setScale(scale, scale);
	
	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(0, -100, totalArea.x, 100),
					   sf::Vector2f(0, -mapClearance), MapID::Swamp);				//entire top
	exits.emplace_back(sf::FloatRect(-100, 0, 100, totalArea.y),
					   sf::Vector2f(-mapClearance, 0), MapID::TownSouth);			//top left

	
	
}
