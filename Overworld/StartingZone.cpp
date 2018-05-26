//
//  StartingZone.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/31/16.
//  Copyright © 2016 Noah. All rights reserved.
//

#include "StartingZone.h"

#define NO_OF_SPRITES 28			//24 wheats, 1 scarecrow, 2 trees, and 1 unanimated wheat

StartingZone::StartingZone(const ResourceHolder& resources)
: MapSection(MapID::StartingZone, "nice_music.ogg") {
	
	std::vector<sf::FloatRect> boxList;
    background.setTexture(resources.getTexture(Textures::TestBackground));
	background.setScale(4, 4);
	sprites.reserve(NO_OF_SPRITES);
	
	//Top-right Tree
	std::vector<sf::FloatRect> boxlist;
	boxlist.emplace_back(-5, 57, 10, 5);
	sprites.emplace_back(make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree), sf::Vector2f(600,90)), boxlist);
	sprites.back().attachDialogue(DialogueFactory::create(Dialogue::Test001, resources));
	sprites.back().setScale(4.f);
	boxList.clear();
	
    //Set up Non-interactable wheat field
	sf::Vector2f position (200,100);
    char rows = 6;
    char columns = 4;
    float timeOffset = .05;
    int verticalGap = 90;
    int horizontalGap = 20;
    int rowOffset = 20;
    for (int iii = 0; iii < rows; iii++) {
        for (int jjj = 0; jjj < columns-1; jjj++) {
            sprites.emplace_back(make_unique<AnimatedComponent>(resources.getTexture(Textures::RollingWheat), position, 0.2f, sf::Vector2i(32,32)), boxList);
            sprites.back().addTime(timeOffset * (iii * columns + jjj));
			sprites.back().setScale(3.f);
			position += sf::Vector2f(verticalGap, 0);
        }
		position += sf::Vector2f(-verticalGap * (columns - 1) + rowOffset, horizontalGap);
    }
	
	//Scarecrow
	boxList.emplace_back(-8, 45, 8, 2);
	sprites.emplace_back(make_unique<DelayedAnimation>(resources.getTexture(Textures::Scarecrow), sf::Vector2f(500,250), 0.1f, sf::Vector2i(32,32), 3.0f), boxList);
	sprites.back().setScale(3.f);
	boxList.clear();
	
	//A Bush
	sprites.emplace_back(make_unique<GraphicsComponent>(resources.getTexture(Textures::Bush), sf::Vector2f (350,310)), boxList);
	sprites.back().setScale(4.f);
	boxList.clear();
	
	//Yak
	boxList.push_back(sf::FloatRect(-30,15,50,15));		//magic numbers galore.
	sprites.emplace_back(make_unique<AnimatedComponent>(resources.getTexture(Textures::Yak), sf::Vector2f(100,325), 0.1f, sf::Vector2i(40,40)), boxList);
	sprites.back().setScale(3.f);
	sprites.back().offsetBase(-30);
	boxList.clear();
	
	//Campfire
	boxList.push_back(sf::FloatRect(-30,70,50,25));		//magic numbers galore.
	boxList.push_back(sf::FloatRect(-40,80,70,10));		//magic numbers galore.
	sprites.emplace_back(make_unique<AnimatedComponent>(resources.getTexture(Textures::Campfire), sf::Vector2f(600,300), 0.1f, sf::Vector2i(32,64)), boxList);
	sprites.back().setScale(3.f);
	boxList.clear();
	
	//The Pond
	boxList.emplace_back(-140,-40,280,80);
	boxList.emplace_back(-50,-60,100,120);
	
	sprites.emplace_back(make_unique<AnimatedComponent>(resources.getTexture(Textures::Pond), sf::Vector2f(620,452), 0.3f, sf::Vector2i(80,32)), boxList);
	sprites.back().setScale(4.f);
	sprites.back().offsetBase(-100);
	boxList.clear();
	
	//Another Tree
	boxList.emplace_back(-5, 57, 10, 5);
	sprites.emplace_back(make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree), sf::Vector2f (150,400)), boxList);
	sprites.back().setScale(4.f);
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






