//
//  StartingZone.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/31/16.
//  Copyright © 2016 Noah. All rights reserved.
//

#include "StartingZone.h"

#define NO_OF_TALKNODES 3
#define NO_OF_OPTIONNODES 1
#define NO_OF_SPRITES 28			//24 wheats, 1 scarecrow, 2 trees, and 1 unanimated wheat

StartingZone::StartingZone(const ResourceHolder& resources)
: MapSection(MapID::Starting, "nice_music.ogg"), talkNodeHolder(NO_OF_TALKNODES, resources.getFont(Fonts::Sansation)),optionNodeHolder(NO_OF_OPTIONNODES, resources.getFont(Fonts::Sansation)) {
	
	std::vector<sf::FloatRect> boxList;
    background.setTexture(resources.getTexture(Textures::TestBackground));
	background.setScale(4, 4);
	sprites.reserve(NO_OF_SPRITES);
	
	//Set up Dialogues
	TalkNode* hey =	&talkNodeHolder[0];
	TalkNode* optionOne = &talkNodeHolder[1];
	TalkNode* optionTwo = &talkNodeHolder[2];
	
	OptionNode* choice = &optionNodeHolder.back();
	
	hey->addText("Looky loo this thing is working!");
	hey->addText("And there's a second text too!");
	hey->setNext(choice);
	
	optionOne->addText("uhh....");
	optionOne->addText("well I got nothing");
	optionOne->addCondition(Condition::First);
	
	optionTwo->addText("well fine then");
	
	choice->addText("Talk some more", optionOne);
	choice->addText("Just leave", optionTwo);
	
	
	//Top-right Tree
	std::vector<sf::FloatRect> boxlist;
	boxlist.emplace_back(-5, 57, 10, 5);
	sprites.emplace_back(make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree), sf::Vector2f(600,90)), boxlist, hey);
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
	
	//Collision Wheat
//	boxlist.clear();
//	int xWheat = resources.getTexture(Textures::RollingWheat).getSize().x/2;
//	int yWheat = resources.getTexture(Textures::RollingWheat).getSize().y/2;
//	boxlist.emplace_back(-xWheat/2, -yWheat/2, xWheat, yWheat);
//	sprites.emplace_back(make_unique<GraphicsComponent>(resources.getTexture(Textures::RollingWheat), sf::Vector2f(300,300)), boxlist);
	
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
    sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * background.getScale().x, totalArea.y * background.getScale().y);

    MapID zoneID = MapID::BigField;
    exits.emplace_back(sf::FloatRect(0,-100,totalArea.x,100), sf::Vector2f(0,totalArea.y-70.f), zoneID);
    exits.emplace_back(sf::FloatRect(-100,0,100,totalArea.y), sf::Vector2f(totalArea.x-50.f,0), zoneID);
    exits.emplace_back(sf::FloatRect(totalArea.x,0,100,totalArea.y), sf::Vector2f(50.f-totalArea.x,0), zoneID);
    exits.emplace_back(sf::FloatRect(0,totalArea.y,totalArea.x,100), sf::Vector2f(0,70.f-totalArea.y), zoneID);
	
}






