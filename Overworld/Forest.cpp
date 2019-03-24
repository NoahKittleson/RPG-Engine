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
	//deadTree.addCollisionBox(-18 * scale, 20 * scale, 42 * scale, 11 * scale);
	deadTree.addCollisionBox(-3 * scale, 19 * scale, 14 * scale, 7 * scale);
	deadTree.offsetBase(-13 * scale);
	addObject(deadTree);
	
	MapObject Tree1 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree1), sf::Vector2f (80,80)));
	Tree1.setScale(scale);
	Tree1.addCollisionBox(-10 * scale, 40 * scale, 12 * scale, 7 * scale);
	Tree1.offsetBase(-15 * scale);
	addObject(Tree1);
	
	MapObject Tree2 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree2), sf::Vector2f (600,400)));
	Tree2.setScale(scale);
	Tree2.addCollisionBox(-9 * scale, 24 * scale, 14 * scale, 7 * scale);
	Tree2.offsetBase(-8 * scale);
	addObject(Tree2);
	
	MapObject Tree3 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree3), sf::Vector2f (700,220)));
	Tree3.setScale(scale);
	Tree3.addCollisionBox(-9 * scale, 23 * scale, 14 * scale, 7 * scale);
	Tree3.offsetBase(-9 * scale);
	addObject(Tree3);
	
	MapObject Tree4 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree4), sf::Vector2f (400,120)));
	Tree4.setScale(scale);
	Tree4.addCollisionBox(-6 * scale, 26 * scale, 10 * scale, 7 * scale);
	Tree4.offsetBase(-6 * scale);
	addObject(Tree4);
	
	MapObject Tree5 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree5), sf::Vector2f (400,450)));
	Tree5.setScale(scale);
	Tree5.addCollisionBox(-5 * scale, 25 * scale, 10 * scale, 5 * scale);
	Tree5.offsetBase(-7 * scale);
	addObject(Tree5);
	
	MapObject Tree6 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree6), sf::Vector2f (200,500)));
	Tree6.setScale(scale);
	Tree6.addCollisionBox(-6 * scale, 25 * scale, 10 * scale, 6 * scale);
	Tree6.offsetBase(-7 * scale);
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
