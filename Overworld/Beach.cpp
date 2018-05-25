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
	
	//Set up Zone Exits
	sf::Vector2i totalArea = sf::Vector2i(background.getTexture()->getSize().x * background.getScale().x,
										  background.getTexture()->getSize().y * background.getScale().y);

	//top, left, right, bottom
	exits.emplace_back(sf::FloatRect(0,-100,totalArea.x,100), sf::Vector2f(0,20), MapID::StartingZone);
	exits.emplace_back(sf::FloatRect(-100,0,100,totalArea.y), sf::Vector2f(20,0), MapID::StartingZone);
	exits.emplace_back(sf::FloatRect(totalArea.x,0,100,totalArea.y), sf::Vector2f(0-totalArea.x,0), MapID::StartingZone);
	exits.emplace_back(sf::FloatRect(0,totalArea.y,totalArea.x,100), sf::Vector2f(0,-20), MapID::StartingZone);
}
