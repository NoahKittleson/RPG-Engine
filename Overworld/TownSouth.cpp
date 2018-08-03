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
	MapObject store (make_unique<GraphicsComponent>(resources.getTexture(Textures::Store1), sf::Vector2f (150,550)));
	store.setScale(scale);
	store.addCollisionBox(-41 * scale, 12 * scale, 80 * scale, 13 * scale);
	addObject(store);
	
	//A smith shop
	MapObject smith (make_unique<GraphicsComponent>(resources.getTexture(Textures::BuildingOutline6), sf::Vector2f (700,375)));
	smith.setScale(scale);
	smith.addCollisionBox(-55 * scale, 10 * scale, 110 * scale, 20 * scale);
	addObject(smith);
	
	//A Chapel
	MapObject chapel (make_unique<GraphicsComponent>(resources.getTexture(Textures::BuildingOutline4), sf::Vector2f (500,700)));
	chapel.setScale(scale);
	chapel.addCollisionBox(-53 * scale, 20 * scale, 106 * scale, 30 * scale);
	addObject(chapel);
	
	//An Inn
	MapObject Inn (make_unique<GraphicsComponent>(resources.getTexture(Textures::BuildingOutline5), sf::Vector2f (500,250)));
	Inn.setScale(scale);
	Inn.addCollisionBox(-55 * scale, 15 * scale, 100 * scale, 30 * scale);
	//Inn.offsetBase(-7 * scale);
	addObject(Inn);
	
	//The Clocktower
	MapObject clocktower (make_unique<GraphicsComponent>(resources.getTexture(Textures::Clocktower), sf::Vector2f (700,500)));
	clocktower.setScale(scale);
	clocktower.addCollisionBox(-20 * scale, -50 * scale, 40 * scale, 110 * scale);
	addObject(clocktower);
	
	//The Fountain
	MapObject fountain (make_unique<GraphicsComponent>(resources.getTexture(Textures::Fountain), sf::Vector2f (400,500)));
	fountain.setScale(scale);
	fountain.addCollisionBox(-15 * scale, 10 * scale, 29 * scale, 6 * scale);
	addObject(fountain);
	
	//The Booth
	MapObject booth (make_unique<GraphicsComponent>(resources.getTexture(Textures::Booth), sf::Vector2f (150,700)));
	booth.setScale(scale);
	booth.addCollisionBox(-25 * scale, 13 * scale, 50 * scale, 12 * scale);
	addObject(booth);
	
	//Sitting Soldier
	MapObject soldierSitting (make_unique<GraphicsComponent>(resources.getTexture(Textures::SittingSoldier), sf::Vector2f (150,200)));
	soldierSitting.setScale(scale);
	soldierSitting.addCollisionBox(-5 * scale, 10 * scale, 10 * scale, 2 * scale);
	addObject(soldierSitting);
	
	//Saluting Soldier
	MapObject soldierStanding (make_unique<GraphicsComponent>(resources.getTexture(Textures::SalutingSoldier), sf::Vector2f (360,360)));
	soldierStanding.setScale(scale);
	soldierStanding.addCollisionBox(-3 * scale, 10 * scale, 6 * scale, 2 * scale);
	addObject(soldierStanding);
	
	//The Colonel
	MapObject theColonel (make_unique<GraphicsComponent>(resources.getTexture(Textures::TheColonel), sf::Vector2f (400,360)));
	theColonel.setScale(scale);
	theColonel.addCollisionBox(-3 * scale, 10 * scale, 6 * scale, 2 * scale);
	addObject(theColonel);
	
	//The Waves
	MapObject waves (make_unique<GraphicsComponent>(resources.getTexture(Textures::WavesSouth), sf::Vector2f (127,200)));
	waves.setScale(scale);
	waves.addCollisionBox(-3 * scale, 10 * scale, 6 * scale, 2 * scale);
	addObject(waves);

	
	//Set up Trigger for Talking
	std::function<State*()> createDialogue = [&resources]() -> State*
	{
		auto dialogue = DialogueFactory::create(Dialogue::Test001, resources);
		return new DialogueMode(dialogue);
	};
	
	ConditionMap prereqs;
	//prereqs[Condition::ChangedMap] = true;
	triggers.emplace_back(prereqs, createDialogue, sf::FloatRect(220,100,100,50));
	
	
	
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
