//
//  BigField.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/24/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "BeachNorth.hpp"


BeachNorth::BeachNorth(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::BeachNorth, "", sf::Vector2f(0 * scale, 125 * scale)) {
    background.setTexture(resources.getTexture(Textures::BeachNorth));
	background.setScale(scale, scale);
	
	std::vector<sf::FloatRect> boxList;
	
	//Cabin
	boxList.emplace_back(-56 * scale, 16 * scale, 102 * scale, 16 * scale);		//magic numbers all round
	MapObject brickHouse (make_unique<GraphicsComponent>(resources.getTexture(Textures::BrickHouse), sf::Vector2f (150 * scale, 150 * scale)), boxList);
	brickHouse.setScale(scale);
	addObject(brickHouse);
	boxList.clear();
	
	
    //Set up Zone Exits
    sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
    
    exits.emplace_back(sf::FloatRect(0,-100,totalArea.x,100),
					   sf::Vector2f(0, -mapClearance), MapID::MountainWest);		//top
    exits.emplace_back(sf::FloatRect(totalArea.x,0,100,totalArea.y),
					   sf::Vector2f(mapClearance, 0), MapID::MountainSouth);		//right
    exits.emplace_back(sf::FloatRect(0,totalArea.y,200*scale,100),
					   sf::Vector2f(0, mapClearance), MapID::BeachWest);			//bottom left
	exits.emplace_back(sf::FloatRect(200*scale,totalArea.y,totalArea.x-(200*scale),100),
					   sf::Vector2f(0, mapClearance), MapID::Start);				//bottom right

    
}
