//
//  TownSouth.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "TownSouth.hpp"

TownSouth::TownSouth(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::TownSouth, "", sf::Vector2f(475 * scale, 625 * scale)) {
	background.setTexture(resources.getTexture(Textures::TownSouth));
	background.setScale(scale, scale);
	
	
	//A store
	MapObject store (make_unique<GraphicsComponent>(resources.getTexture(Textures::Store1), sf::Vector2f (300,300)));
	store.setScale(scale);
	store.addCollisionBox(-41 * scale, 12 * scale, 80 * scale, 13 * scale);
	addObject(store);
	
	//Sitting Soldier
	MapObject soldierSitting (make_unique<GraphicsComponent>(resources.getTexture(Textures::SittingSoldier), sf::Vector2f (150,200)));
	soldierSitting.setScale(scale);
	soldierSitting.addCollisionBox(-5 * scale, 10 * scale, 10 * scale, 2 * scale);
	addObject(soldierSitting);
	
	//Saluting Soldier
	MapObject soldierStanding (make_unique<GraphicsComponent>(resources.getTexture(Textures::SalutingSoldier), sf::Vector2f (200,200)));
	soldierStanding.setScale(scale);
	soldierStanding.addCollisionBox(-3 * scale, 10 * scale, 6 * scale, 2 * scale);
	addObject(soldierStanding);
	
	//Saluting Soldier
	MapObject theColonel (make_unique<GraphicsComponent>(resources.getTexture(Textures::TheColonel), sf::Vector2f (250,200)));
	theColonel.setScale(scale);
	theColonel.addCollisionBox(-3 * scale, 10 * scale, 6 * scale, 2 * scale);
	addObject(theColonel);

	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(0, -100, totalArea.x, 100),
					   sf::Vector2f(0, -mapClearance), MapID::Forest);				//entire top
	exits.emplace_back(sf::FloatRect(-100, 0, 100, 125 * scale),
					   sf::Vector2f(-mapClearance, 0), MapID::SouthOfStart);		//top left
	exits.emplace_back(sf::FloatRect(-100, 125 * scale, 100, 250 * scale),
					   sf::Vector2f(-mapClearance, 0), MapID::BeachSouth);			//top left
	exits.emplace_back(sf::FloatRect(totalArea.x, 0, 100, 95 * scale),
					   sf::Vector2f(mapClearance, 0), MapID::Swamp);				//top right
	exits.emplace_back(sf::FloatRect(totalArea.x, 95 * scale, 100, 280 * scale),
					   sf::Vector2f(mapClearance, 0), MapID::LighthouseCoast);		//bottom right

	
	
	
}
