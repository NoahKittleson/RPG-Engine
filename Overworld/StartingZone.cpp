//
//  StartingZone.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/31/16.
//  Copyright © 2016 Noah. All rights reserved.
//

#include "StartingZone.h"

StartingZone::StartingZone(ResourceHolder& resources) : MapSection() {
    
    std::vector<sf::FloatRect> emptyList;
    background.setTexture(resources.getTexture("cute_image.jpg"));
    
    //Set up Non-interactable wheat field
    TalkingSprite WheatField (resources.getTexture("RollingWheat.png"), sf::Vector2f(400,100), emptyList, nullptr);
    WheatField.setScale(3.0f, 3.0f);
    for (int iii = 0; iii < 6; iii++) {
        sprites.push_back(WheatField);
        WheatField.move(20, 0);
        sprites.push_back(WheatField);
        WheatField.move(0, 20);
    }
    
    //Set up Interactable Sprite
    //!!! WARNING : THIS IS A MEMORY LEAK !!!//
    TalkNode* hey = new TalkNode(resources.getFont("sansation.ttf"));
    hey->addText("Hey look this thing is working!");
    hey->addText("And there's a second text too!");
    {
        int xIcon = resources.getTexture("icon.png").getSize().x/2;
        int yIcon = resources.getTexture("icon.png").getSize().y/2;
        sf::FloatRect Rectangle (-xIcon/2, -yIcon/2, xIcon, yIcon);
        std::vector<sf::FloatRect> boxlist;
        
        //L block Icon
        boxlist.emplace_back(0, 0, 10, 50);
        boxlist.emplace_back(0, 0, 50, 10);
        sprites.emplace_back(resources.getTexture("icon.png"), sf::Vector2f (600,100), boxlist, nullptr);
        
        //Collision Wheat
        boxlist.clear();
        int xWheat = resources.getTexture("RollingWheat.png").getSize().x/2;
        int yWheat = resources.getTexture("RollingWheat.png").getSize().y/2;
        boxlist.push_back(sf::FloatRect(-xWheat/2, -yWheat/2, xWheat, yWheat));
        sprites.emplace_back(TalkingSprite(resources.getTexture("RollingWheat.png"),
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
    //Trigger killzone (sf::FloatRect(400,0,500,500), EnemyList);
    //this->triggers.emplace_back(sf::FloatRect(400,0,500,500), EnemyVector);
    miniTriggers.emplace_back(sf::FloatRect(500,50,50,50), "fight");
    
    //Set up Zone Exits
    //1920 by 1200 mountain jpg
    {
        std::string ZoneID = "NextZone";
        ZoneExit top(sf::FloatRect(0,-100,1920,100), sf::Vector2f(0,550), ZoneID);
        ZoneExit left(sf::FloatRect(-100,0,100,1200), sf::Vector2f(750,0), ZoneID);
        ZoneExit right(sf::FloatRect(1920,0,100,1200), sf::Vector2f(-1870,0), ZoneID);
        ZoneExit bottom(sf::FloatRect(0,1200,1920,100), sf::Vector2f(0,-1150), ZoneID);
        exits.push_back(top);
        exits.push_back(left);
        exits.push_back(right);
        exits.push_back(bottom);
    }
}