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

StartingZone::StartingZone(const ResourceHolder& resources)
: MapSection(), talkNodeHolder(NO_OF_TALKNODES, resources.getFont("sansation.ttf")),
                optionNodeHolder(NO_OF_OPTIONNODES, resources.getFont("sansation.ttf")) {
    
    std::vector<sf::IntRect> emptyList;
    background.setTexture(resources.getTexture("cute_image.jpg"));
    
    //Set up Non-interactable wheat field
    InteractableSprite WheatField (resources.getTexture("RollingWheat.png"), sf::Vector2f(200,100), emptyList, nullptr, 0.4);
    WheatField.setScale(3.0f, 3.0f);
    char rows = 6;
    char columns = 4;
    float timeOffset = .05;
    int verticalGap = 90;
    int horizontalGap = 20;
    int rowOffset = 20;
    for (int iii = 0; iii < rows; iii++) {
        for (int jjj = 0; jjj < columns-1; jjj++) {
            sprites.push_back(WheatField);
            WheatField.addTime(timeOffset);
            WheatField.move(verticalGap, 0);
        }
        sprites.push_back(WheatField);
        WheatField.addTime(timeOffset);
        WheatField.move(-verticalGap * (columns - 1) + rowOffset, horizontalGap);
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
    //...nothing right now...
    
    //Set up Zone Exits
    //1920 by 1200 mountain jpg
    {
        std::string ZoneID = "NextZone";
        ZoneExit top(sf::IntRect(0,-100,1920,100), sf::Vector2f(0,550), ZoneID);
        ZoneExit left(sf::IntRect(-100,0,100,1200), sf::Vector2f(750,0), ZoneID);
        ZoneExit right(sf::IntRect(1920,0,100,1200), sf::Vector2f(-1870,0), ZoneID);
        ZoneExit bottom(sf::IntRect(0,1200,1920,100), sf::Vector2f(0,-1150), ZoneID);
        exits.push_back(top);
        exits.push_back(left);
        exits.push_back(right);
        exits.push_back(bottom);
    }
    
}
