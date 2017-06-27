//
//  ResourceHolder.cpp
//  Overworld
//
//  Created by Noah Kittleson on 12/4/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "ResourceHolder.h"

ResourceHolder::ResourceHolder()
{
    //assure there is only ever one ResourceHolder
    assert(!instantiated);
    instantiated = true;
    
    //Whenever you add a new texture, add to this list
    std::list<sf::String> IDList;
    IDList.push_back("Mountains.jpg");
    IDList.push_back("Stickmaniac.png");
    IDList.push_back("BasicIdle.png");
    IDList.push_back("BadAttackAnimation.png");
    IDList.push_back("GetHitAnimation.png");
    IDList.push_back("RollingWheat.png");
    IDList.push_back("Scarecrow.png");
    IDList.push_back("cute_image.jpg");
    IDList.push_back("icon.png");
    IDList.push_back("tree.png");
    IDList.push_back("PlayerWalkingUp.png");
    IDList.push_back("PlayerWalkingDown.png");
    IDList.push_back("PlayerWalkingLeft.png");
    IDList.push_back("PlayerWalkingRight.png");
	IDList.push_back("Campfire.png");
	IDList.push_back("Yak.png");

	
    for (auto ID: IDList) {
        textureMap[ID].loadFromFile(resourcePath() + ID);
    }
    
    IDList.clear();
    //Whenever you add a new font, add to this list
    IDList.push_back("sansation.ttf");
    
    for (auto && ID: IDList) {
        fontMap[ID].loadFromFile(resourcePath() + ID);
    }
    
    IDList.clear();
    //Whenever you add a new sound file, add to this list
    IDList.push_back("nice_music.ogg");
    for (auto && ID: IDList) {
        musicMap[ID].openFromFile(resourcePath() + ID);
    }
}

//Get a texture/sound/font by giving the full file name.
//If nothing is found returns the first result in IDList

const sf::Texture& ResourceHolder::getTexture(sf::String ID) const
{
    assert(!textureMap.empty());
    auto find = textureMap.find(ID);
    if (find != textureMap.end()) {
        return find->second;
    }
    else return textureMap.begin()->second;
}

const sf::Font& ResourceHolder::getFont(sf::String ID) const
{
    assert(!fontMap.empty());
    auto find = fontMap.find(ID);
    if (find != fontMap.end()) {
        return find->second;
    }
    else return fontMap.begin()->second;
}

const sf::Music& ResourceHolder::getMusic(sf::String ID) const
{
    assert(!textureMap.empty());
    auto find = musicMap.find(ID);
    if (find != musicMap.end()) {
        return find->second;
    }
    else return musicMap.begin()->second;
}

bool ResourceHolder::instantiated = false;


//std::map<sf::String, sf::Texture> ResourceHolder::textureMap;
//std::map<sf::String, sf::Font> ResourceHolder::fontMap;
//std::map<sf::String, sf::Music> ResourceHolder::musicMap;
