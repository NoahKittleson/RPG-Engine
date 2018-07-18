//
//  Beach.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/24/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "BeachWest.hpp"


BeachWest::BeachWest(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::BeachWest, "nice_music.ogg", sf::Vector2f(0, 350 * scale))
{
	background.setTexture(resources.getTexture(Textures::BeachWest));
	background.setScale(scale, scale);
	
	//this is *mostly* a test....
	waterZones.emplace_back(sf::FloatRect(0,0,325,1600));
	
	//Waves
	std::vector<sf::FloatRect> boxList;
	sf::Vector2f size = sf::Vector2f(200, 400); 						//magic number
	boxList.emplace_back(-400, -800, 200, 1600);						//ho boy look how magic these numbers are

	MapObject Waves (make_unique<AnimatedComponent>(resources.getTexture(Textures::Waves), sf::Vector2f(size.x * scale/2, size.y * scale/2), 0.2, sf::Vector2i(size.x, size.y)), boxList);
	
	Waves.offsetBase(-size.y * scale);
	Waves.setScale(scale);
	addObject(Waves);
	boxList.clear();
	
	MapObject Girl (make_unique<GraphicsComponent>(resources.getTexture(Textures::BikiniBabe), sf::Vector2f(300,200)));
	Girl.addCollisionBox(-4 * scale, 12 * scale, 8 * scale, 4 * scale);
	Girl.setScale(scale);
	addObject(Girl);

	//Set up Zone Exits
	sf::Vector2i totalArea = sf::Vector2i(background.getTexture()->getSize().x * background.getScale().x,
										  background.getTexture()->getSize().y * background.getScale().y);

	//top, left, right, bottom
	exits.emplace_back(sf::FloatRect(0,-100,totalArea.x,100),
					   sf::Vector2f(0, mapClearance), MapID::BeachNorth);		//top
	exits.emplace_back(sf::FloatRect(totalArea.x,0,100,150*scale),
					   sf::Vector2f(-mapClearance,0), MapID::Start);			//top right
	exits.emplace_back(sf::FloatRect(totalArea.x,150*scale,100,totalArea.y-(150*scale)),
					   sf::Vector2f(-mapClearance,0), MapID::SouthOfStart);		//bottom right
	exits.emplace_back(sf::FloatRect(0,totalArea.y,totalArea.x,100),
					   sf::Vector2f(0, mapClearance), MapID::BeachSouth);		//bottom
}
