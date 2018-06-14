//
//  Beach.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/24/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "Beach.hpp"


Beach::Beach(const ResourceHolder& resources)
: MapSection(MapID::Beach, "nice_music.ogg")
{
	background.setTexture(resources.getTexture(Textures::Beach));
	background.setScale(4, 4);
	
	//Waves
	std::vector<sf::FloatRect> boxList;
	//boxlist.emplace_back(-5, 57, 10, 5);
	sf::Vector2f size = sf::Vector2f(resources.getTexture(Textures::Waves).getSize().x,
									 resources.getTexture(Textures::Waves).getSize().y);
	MapObject Waves (make_unique<AnimatedComponent>(resources.getTexture(Textures::Waves), sf::Vector2f(size.x/2,size.y/2), 0.2, sf::Vector2i(size.x, size.y)), boxList);
	
	
	Waves.offsetBase(-size.x/2);
	Waves.setScale(4.f);
	addObject(Waves);
	boxList.clear();
	
	//Set up Zone Exits
	sf::Vector2i totalArea = sf::Vector2i(background.getTexture()->getSize().x * background.getScale().x,
										  background.getTexture()->getSize().y * background.getScale().y);

	//top, left, right, bottom
	exits.emplace_back(sf::FloatRect(0,-100,totalArea.x,100), sf::Vector2f(0,20), MapID::StartingZone);
	exits.emplace_back(sf::FloatRect(-100,0,100,totalArea.y), sf::Vector2f(20,0), MapID::StartingZone);
	exits.emplace_back(sf::FloatRect(totalArea.x,0,100,totalArea.y), sf::Vector2f(0-totalArea.x,0), MapID::StartingZone);
	exits.emplace_back(sf::FloatRect(0,totalArea.y,totalArea.x,100), sf::Vector2f(0,-20), MapID::StartingZone);
}
