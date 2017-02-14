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
: MapSection(MapID::BigField), talkNodeHolder(NO_OF_TALKNODES, resources.getFont("sansation.ttf")),
optionNodeHolder(NO_OF_OPTIONNODES, resources.getFont("sansation.ttf")) {
    
    std::vector<sf::IntRect> emptyList;
    background.setTexture(resources.getTexture("cute_image.jpg"));
    
    //Set up Non-interactable wheat field
    InteractableSprite WheatField (resources.getTexture("RollingWheat.png"), sf::Vector2f(400,100), emptyList, nullptr);
    WheatField.setScale(3.0f, 3.0f);
    for (int iii = 0; iii < 6; iii++) {
        sprites.push_back(WheatField);
        WheatField.move(20, 0);
        sprites.push_back(WheatField);
        WheatField.move(0, 20);
    }
    
    //Set up Interactable Sprite
    TalkNode* hey = &talkNodeHolder[0];
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
    choice->addText("Just leave", optionTwo);
    
    {
        int xIcon = resources.getTexture("icon.png").getSize().x/2;
        int yIcon = resources.getTexture("icon.png").getSize().y/2;
        sf::IntRect Rectangle (-xIcon/2, -yIcon/2, xIcon, yIcon);
        std::vector<sf::IntRect> boxlist;
        
        //L block Icon
        boxlist.emplace_back(0, 0, 10, 50);
        boxlist.emplace_back(0, 0, 50, 10);
        sprites.emplace_back(resources.getTexture("icon.png"), sf::Vector2f (600,100), boxlist, nullptr);
        
        //Collision Wheat
        boxlist.clear();
        int xWheat = resources.getTexture("RollingWheat.png").getSize().x/2;
        int yWheat = resources.getTexture("RollingWheat.png").getSize().y/2;
        boxlist.push_back(sf::IntRect(-xWheat/2, -yWheat/2, xWheat, yWheat));
        sprites.emplace_back(InteractableSprite(resources.getTexture("RollingWheat.png"),
                                           sf::Vector2f (300,300), boxlist, nullptr));
        
        boxlist.clear();
        boxlist.push_back(Rectangle);
        sprites.emplace_back(resources.getTexture("icon.png"), sf::Vector2f (150,400), boxlist, hey);
    }
    
    //Set up Trigger for Fighting
    std::vector<Character> EnemyVector;
    EnemyVector.emplace_back(300, 100,  30, resources.getTexture("RollingWheat.png"),
                             resources.getFont("sansation.ttf"), "GrainMan", ".", true,
                             resources.getTexture("RollingWheat.png"));

    
    //Set up Zone Exits
    sf::Vector2u totalArea = background.getTexture()->getSize();
    
    MapID zoneID = MapID::Starting;
    exits.emplace_back(sf::IntRect(0,-100,totalArea.x,100), sf::Vector2f(0,totalArea.y-150), zoneID);
    exits.emplace_back(sf::IntRect(-100,0,100,totalArea.y), sf::Vector2f(totalArea.x-150,0), zoneID);
    exits.emplace_back(sf::IntRect(totalArea.x,0,100,totalArea.y), sf::Vector2f(-totalArea.x+150,0), zoneID);
    exits.emplace_back(sf::IntRect(0,totalArea.y,totalArea.x,100), sf::Vector2f(0,-totalArea.y+150), zoneID);
    
}
