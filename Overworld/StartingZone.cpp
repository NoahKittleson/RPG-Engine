//
//  StartingZone.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/31/16.
//  Copyright © 2016 Noah. All rights reserved.
//

#include "StartingZone.h"

StartingZone::StartingZone(const ResourceHolder& resources)
: MapSection(MapID::StartingZone, "nice_music.ogg") {
	
	std::vector<sf::FloatRect> boxList;
    background.setTexture(resources.getTexture(Textures::TestBackground));
	background.setScale(4, 4);
	
	//Top-right Tree
	std::vector<sf::FloatRect> boxlist;
	boxlist.emplace_back(-5, 57, 10, 5);
	MapObject Tree (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree), sf::Vector2f(600,90)), boxlist);
	Tree.attachDialogue(DialogueFactory::create(Dialogue::Test001, resources));
	Tree.setScale(4.f);
	addObject(Tree);
	boxList.clear();
	
	//Another Tree
	boxList.emplace_back(-5, 57, 10, 5);
	MapObject otherTree (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree), sf::Vector2f (150,400)), boxList);
	otherTree.setScale(4.f);
	addObject(otherTree);
	boxList.clear();
	
    //Set up Non-interactable wheat field
	sf::Vector2f position (200,100);
    char rows = 6;
    char columns = 4;
    float timeOffset = .05;
    int verticalGap = 90;
    int horizontalGap = 20;
    int rowOffset = 20;
	
	MapObject Wheat (make_unique<AnimatedComponent>(resources.getTexture(Textures::RollingWheat), position, 0.2f, sf::Vector2i(32,32)), boxList);
    for (int iii = 0; iii < rows; iii++) {
        for (int jjj = 0; jjj < columns-1; jjj++) {
            Wheat.addTime(timeOffset * (iii * columns + jjj));
			Wheat.setScale(3.f);
			Wheat.setPosition(position.x, position.y);
			position += sf::Vector2f(verticalGap, 0);
			addObject(Wheat);
        }
		position += sf::Vector2f(-verticalGap * (columns - 1) + rowOffset, horizontalGap);
    }
	
	//Scarecrow
	boxList.emplace_back(-8, 45, 8, 2);
	MapObject scarecrow (make_unique<DelayedAnimation>(resources.getTexture(Textures::Scarecrow), sf::Vector2f(500,250), 0.1f, sf::Vector2i(32,32), 3.0f), boxList);
	scarecrow.setScale(3.f);
	addObject(scarecrow);
	boxList.clear();
	
	//A Bush
	MapObject bush (make_unique<GraphicsComponent>(resources.getTexture(Textures::Bush), sf::Vector2f (350,310)), boxList);
	bush.setScale(4.f);
	addObject(bush);
	boxList.clear();
	
	//Yak
	boxList.push_back(sf::FloatRect(-30,15,50,15));		//magic numbers galore.
	MapObject yak (make_unique<AnimatedComponent>(resources.getTexture(Textures::Yak), sf::Vector2f(100,325), 0.1f, sf::Vector2i(40,40)), boxList);
	yak.setScale(3.f);
	yak.offsetBase(-30);
	addObject(yak);
	boxList.clear();
	
	//Campfire
	boxList.push_back(sf::FloatRect(-30,70,50,25));		//magic numbers galore.
	boxList.push_back(sf::FloatRect(-40,80,70,10));		//magic numbers galore.
	MapObject campfire (make_unique<AnimatedComponent>(resources.getTexture(Textures::Campfire), sf::Vector2f(600,300), 0.1f, sf::Vector2i(32,64)), boxList);
	campfire.setScale(3.f);
	addObject(campfire);
	boxList.clear();
	
	//The Pond
	boxList.emplace_back(-140,-40,280,80);
	boxList.emplace_back(-50,-60,100,120);
	
	MapObject pond (make_unique<AnimatedComponent>(resources.getTexture(Textures::Pond), sf::Vector2f(620,452), 0.3f, sf::Vector2i(80,32)), boxList);
	pond.setScale(4.f);
	pond.offsetBase(-100);
	addObject(pond);
	boxList.clear();
	
    //Set up Trigger for Fighting
	std::function<State*()> createBattle = [&resources]() -> State*
	{
		std::vector<std::shared_ptr<Character>> enemyVec;
		enemyVec.emplace_back(CharacterGenerator::create(resources, Combatant::Logo));
		return new BattleState(enemyVec);
	};
	ConditionMap prereqs;
	//prereqs[Condition::ChangedMap] = true;
	triggers.emplace_back(prereqs, createBattle, sf::FloatRect(250,150,100,50));
    
    //Set up Zone Exits
	sf::Vector2i totalArea = sf::Vector2i(background.getTexture()->getSize().x * background.getScale().x,
										  background.getTexture()->getSize().y * background.getScale().y);

	exits.emplace_back(sf::FloatRect(0,-100,totalArea.x,100), sf::Vector2f(0,20), MapID::BigField);
    exits.emplace_back(sf::FloatRect(-100,0,100,totalArea.y), sf::Vector2f(totalArea.x-20,0), MapID::Beach);
    exits.emplace_back(sf::FloatRect(totalArea.x,0,100,totalArea.y), sf::Vector2f(-20,0), MapID::BigField);
    exits.emplace_back(sf::FloatRect(0,totalArea.y,totalArea.x,100), sf::Vector2f(0,-20), MapID::BigField);
}






