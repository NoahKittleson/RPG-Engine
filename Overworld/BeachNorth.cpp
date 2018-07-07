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

    //Set up Non-interactable wheat field
	sf::Vector2f position (200,100);
	std::vector<sf::FloatRect> emptyList;

    for (int iii = 0; iii < 6; iii++) {
        MapObject fuck (make_unique<AnimatedComponent>(resources.getTexture(Textures::BigWheat), position, 0.2f, sf::Vector2i(32,32)), emptyList);
		addObject(fuck);
		position += sf::Vector2f(20, 0);
        MapObject shit (make_unique<AnimatedComponent>(resources.getTexture(Textures::BigWheat), sf::Vector2f(200,100), 0.2f, sf::Vector2i(32,32)), emptyList);
		addObject(shit);
		position += sf::Vector2f(0, 20);
    }
	
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
