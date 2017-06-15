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
: MapSection(MapID::Starting, "nice_music.ogg"), talkNodeHolder(NO_OF_TALKNODES, resources.getFont("sansation.ttf")),optionNodeHolder(NO_OF_OPTIONNODES, resources.getFont("sansation.ttf")) {
	
    std::vector<sf::FloatRect> emptyList;
    background.setTexture(resources.getTexture("cute_image.jpg"));
	sprites.reserve(NO_OF_SPRITES);
    
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
            sprites.emplace_back(new AnimatedComponent(resources.getTexture("RollingWheat.png"), position, 0.2f, sf::Vector2i(32,32)), emptyList);
            sprites.back().addTime(timeOffset * (iii * columns + jjj));
			sprites.back().setScale(3.f);
			position += sf::Vector2f(verticalGap, 0);
        }
//        sprites.push_back(Wheat);
//        Wheat.addTime(timeOffset);
		position += sf::Vector2f(-verticalGap * (columns - 1) + rowOffset, horizontalGap);
    }
	
	//Scarecrow
	sprites.emplace_back(new DelayedAnimation(resources.getTexture("Scarecrow.png"), sf::Vector2f(500,250), 0.1f, sf::Vector2i(32,32), 3.0f), emptyList);
	sprites.back().setScale(3.f);
	
    //Set up Interactable Sprite				//CURRENTLY DEACTIVATED
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
    
    {
        int xIcon = resources.getTexture("tree.png").getSize().x/2;
        int yIcon = resources.getTexture("tree.png").getSize().y/2;
		sf::FloatRect Rectangle (-xIcon/2, -yIcon/2, xIcon, yIcon);
        std::vector<sf::FloatRect> boxlist;
        
        //L block Icon
        boxlist.emplace_back(0, 0, 10, 50);
        boxlist.emplace_back(0, 0, 50, 10);
		//this sprites should be added earlier if it is to be drawn in the correct order
		sprites.emplace_back(new GraphicsComponent(resources.getTexture("tree.png"), sf::Vector2f(600,100)), boxlist, hey);

        sprites.back().setScale(4.f);
        
        //Collision Wheat
        boxlist.clear();
        int xWheat = resources.getTexture("RollingWheat.png").getSize().x/2;
        int yWheat = resources.getTexture("RollingWheat.png").getSize().y/2;
        boxlist.push_back(sf::FloatRect(-xWheat/2, -yWheat/2, xWheat, yWheat));
        sprites.emplace_back(new GraphicsComponent(resources.getTexture("RollingWheat.png"),
                                                sf::Vector2f(300,300)), boxlist);
        
        boxlist.clear();
        boxlist.push_back(Rectangle);
        sprites.emplace_back(new GraphicsComponent(resources.getTexture("tree.png"), sf::Vector2f (150,400)), boxlist);
        sprites.back().setScale(4.f);
    }
    
    //Set up Trigger for Fighting
    //...nothing right now...
    
    //Set up Zone Exits
    sf::Vector2u totalArea = background.getTexture()->getSize();

    MapID zoneID = MapID::BigField;
    exits.emplace_back(sf::FloatRect(0,-100,totalArea.x,100), sf::Vector2f(0,totalArea.y-70.f), zoneID);
    exits.emplace_back(sf::FloatRect(-100,0,100,totalArea.y), sf::Vector2f(totalArea.x-50.f,0), zoneID);
    exits.emplace_back(sf::FloatRect(totalArea.x,0,100,totalArea.y), sf::Vector2f(50.f-totalArea.x,0), zoneID);
    exits.emplace_back(sf::FloatRect(0,totalArea.y,totalArea.x,100), sf::Vector2f(0,70.f-totalArea.y), zoneID);
					
//	for (auto && sprite : sprites) {
//		if (sprite.getTexture()) {
//			std::cout << "initialized with ptr\n";
//		} else std::cout << "initialized with NULLptr\n";
//	}
	
}






