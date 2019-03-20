//
//  Forest.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "Forest.hpp"

Forest::Forest(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::Forest, NoMusic, sf::Vector2f(550 * scale, 350 * scale)) {
	background.setTexture(resources.getTexture(Textures::Forest));
	background.setScale(scale, scale);
	
	//A Dead Tree (or is it?)
	MapObject deadTree (make_unique<GraphicsComponent>(resources.getTexture(Textures::DeadTree), sf::Vector2f (200,200)));
	deadTree.setScale(scale);
	deadTree.addCollisionBox(-19 * scale, 20 * scale, 44 * scale, 11 * scale);
	addObject(deadTree);
	
	MapObject Tree1 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree1), sf::Vector2f (250,250)));
	Tree1.setScale(scale);
	addObject(Tree1);
	
	MapObject Tree2 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree2), sf::Vector2f (150,200)));
	Tree2.setScale(scale);
	addObject(Tree2);
	
	MapObject Tree3 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree3), sf::Vector2f (240,120)));
	Tree3.setScale(scale);
	addObject(Tree3);
	
	MapObject Tree4 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree4), sf::Vector2f (260,210)));
	Tree4.setScale(scale);
	addObject(Tree4);
	
	MapObject Tree5 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree5), sf::Vector2f (170,210)));
	Tree5.setScale(scale);
	addObject(Tree5);
	
	MapObject Tree6 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree6), sf::Vector2f (170,120)));
	Tree6.setScale(scale);
	addObject(Tree6);
	
	
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
