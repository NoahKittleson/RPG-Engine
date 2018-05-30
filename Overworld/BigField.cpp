//
//  BigField.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/24/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "BigField.hpp"

#define NO_OF_TALKNODES 3
#define NO_OF_OPTIONNODES 1

BigField::BigField(const ResourceHolder& resources)
: MapSection(MapID::BigField, "") {
    std::vector<sf::FloatRect> emptyList;
    background.setTexture(resources.getTexture(Textures::Mountains));
    
    //Set up Non-interactable wheat field
	sf::Vector2f position (200,100);
	
    for (int iii = 0; iii < 6; iii++) {
        MapObject fuck (make_unique<AnimatedComponent>(resources.getTexture(Textures::RollingWheat), position, 0.2f, sf::Vector2i(32,32)), emptyList);
		addObject(fuck);
		position += sf::Vector2f(20, 0);
        MapObject shit (make_unique<AnimatedComponent>(resources.getTexture(Textures::RollingWheat), sf::Vector2f(200,100), 0.2f, sf::Vector2i(32,32)), emptyList);
		addObject(shit);
		position += sf::Vector2f(0, 20);
    }
    
    //Set up Interactable Sprite
    /*TalkNode* hey = &talkNodeHolder[0];
    TalkNode* optionOne = &talkNodeHolder[1];
    TalkNode* optionTwo = &talkNodeHolder[2];
    
    OptionNode* choice = &optionNodeHolder.back();
    
    hey->addText("Looky loo this thing is working!");
    hey->addText("And there's a second text too!");
    hey->setNext(choice);
    
    optionOne->addText("uhh....");
    optionOne->addText("well I got nothing");
    
    optionTwo->addText("well fine then");
    
    choice->addText("Talk some more", optionOne);
    choice->addText("Just leave", optionTwo);*/
    
    {
        int xIcon = resources.getTexture(Textures::Tree).getSize().x/2;
        int yIcon = resources.getTexture(Textures::Tree).getSize().y/2;
        sf::FloatRect Rectangle (-xIcon/2, -yIcon/2, xIcon, yIcon);
        std::vector<sf::FloatRect> boxlist;
        
		//L block Tree
		boxlist.emplace_back(0, 0, 10, 50);
		boxlist.emplace_back(0, 0, 50, 10);
		//this sprites should be added earlier if it is to be drawn in the correct order
		MapObject Tree (make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree), sf::Vector2f(600,100)), boxlist);
		Tree.setScale(4.f);
		addObject(Tree);
		
//		//Collision Wheat
//		boxlist.clear();
//		int xWheat = resources.getTexture(Textures::RollingWheat).getSize().x/2;
//		int yWheat = resources.getTexture(Textures::RollingWheat).getSize().y/2;
//		boxlist.push_back(sf::FloatRect(-xWheat/2, -yWheat/2, xWheat, yWheat));
//		sprites.emplace_back(make_unique<GraphicsComponent>(resources.getTexture(Textures::RollingWheat),
//												   sf::Vector2f(300,300)), boxlist);
//
//		boxlist.clear();
//		boxlist.push_back(Rectangle);
//		sprites.emplace_back(make_unique<GraphicsComponent>(resources.getTexture(Textures::Tree), sf::Vector2f (150,400)), boxlist);
//		sprites.back().setScale(4.f);
		
	}
	
    //Set up Trigger for Fighting
//    std::vector<Character> EnemyVector;
//    EnemyVector.emplace_back(300, 100,  30, resources.getTexture(Textures::RollingWheat),
//							 resources.getFont(Fonts::Sansation), "GrainMan", ".", true,
//                             resources.getTexture(Textures::RollingWheat));

    
    //Set up Zone Exits
    sf::Vector2u totalArea = background.getTexture()->getSize();
    
    MapID zoneID = MapID::StartingZone;
    exits.emplace_back(sf::FloatRect(0,-100,totalArea.x,100), sf::Vector2f(0,totalArea.y-150), zoneID);
    exits.emplace_back(sf::FloatRect(-100,0,100,totalArea.y), sf::Vector2f(totalArea.x-150,0), zoneID);
    exits.emplace_back(sf::FloatRect(totalArea.x,0,100,totalArea.y), sf::Vector2f(-totalArea.x+150,0), zoneID);
    exits.emplace_back(sf::FloatRect(0,totalArea.y,totalArea.x,100), sf::Vector2f(0,-totalArea.y+150), zoneID);
    
}
