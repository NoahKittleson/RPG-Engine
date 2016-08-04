//
//  StartingZone.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/31/16.
//  Copyright © 2016 Noah. All rights reserved.
//

#include "StartingZone.h"

StartingZone::StartingZone(ResourceHolder& resources) : MapSection() {
    
    sf::Texture dummyTexture = resources.getTexture("icon.png");

    std::vector<sf::FloatRect> emptyList;
    std::vector<sf::Sprite> ObjList;
    
    sf::Texture Wheat = resources.getTexture("RollingWheat.png");
    TalkingSprite WheatField (Wheat, sf::Vector2f(200,50), emptyList, nullptr);
    WheatField.setScale(3.0f, 3.0f);
    
    for (int iii = 0; iii < 6; iii++) {
        ObjList.push_back(WheatField);
        WheatField.move(20, 0);
        ObjList.push_back(WheatField);
        WheatField.move(0, 20);
    }
    
    sf::Font font = resources.getFont("sansation.ttf");
    TalkNode hey(font);
    hey.addText("Hey look this thing is working!");
    hey.addText("And there's a second text too!");
    
    {
        sf::FloatRect Rectangle (dummyTexture.getSize().x/2, dummyTexture.getSize().y/2,10,10);
        std::vector<sf::FloatRect> boxlist;
        
        boxlist.push_back(sf::FloatRect(dummyTexture.getSize().x/2, dummyTexture.getSize().y/2,10,50));
        boxlist.push_back(sf::FloatRect(dummyTexture.getSize().x/2, dummyTexture.getSize().y/2,50,10));
        TalkingSprite Object2 (dummyTexture, sf::Vector2f (900,100), boxlist, nullptr);
        ObjList.push_back(Object2);
        
        boxlist.clear();
        boxlist.push_back(sf::FloatRect(dummyTexture.getSize().x/4,
                                        dummyTexture.getSize().y/4,
                                        dummyTexture.getSize().x/2,
                                        dummyTexture.getSize().y/2));
        ObjList.emplace_back(dummyTexture, sf::Vector2f (300,300), boxlist);
        
        boxlist.clear();
        boxlist.push_back(Rectangle);
        TalkingSprite Object1 (dummyTexture, sf::Vector2f (150,650), boxlist, &hey);
        ObjList.push_back(Object1);
    }
    
    std::list<ZoneExit> StartingZoneExits;			//1920 by 1200 mountain jpg
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