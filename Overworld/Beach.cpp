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
	int scale = 4;
	std::vector<sf::FloatRect> boxList;
	sf::Vector2f size = sf::Vector2f(200, 400); 						//magic number
	boxList.emplace_back(-400, -800, 200, 1600);						//ho boy look how magic these numbers are
	boxList.emplace_back(-200, -800, 30, 1200);
	boxList.emplace_back(-200, -800, 15, 1300);
	boxList.emplace_back(-170, -800, 30, 200);
	boxList.emplace_back(-170, -800, 15, 300);
	boxList.emplace_back(-140, -800, 30, 150);
	boxList.emplace_back(-110, -800, 30, 80);
	boxList.emplace_back(-110, -800, 15, 110);
	boxList.emplace_back(-100, -800, 40, 50);
	boxList.emplace_back(-60, -800, 20, 20);




	MapObject Waves (make_unique<AnimatedComponent>(resources.getTexture(Textures::Waves), sf::Vector2f(size.x * scale/2, size.y * scale/2), 0.2, sf::Vector2i(size.x, size.y)), boxList);
	
	Waves.offsetBase(-size.y * scale);
	Waves.setScale(scale);
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
