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
    std::list<sf::String> IDList;
    IDList.push_back(resourcePath() + "Mountains.jpg");
    IDList.push_back(resourcePath() + "Stickmaniac.png");
    IDList.push_back(resourcePath() + "BasicIdle.png");
    IDList.push_back(resourcePath() + "BadAttackAnimation.png");
    IDList.push_back(resourcePath() + "GetHitAnimation.png");
    IDList.push_back(resourcePath() + "RollingWheat.png");
    IDList.push_back(resourcePath() + "cute_image.jpg");
    IDList.push_back(resourcePath() + "icon.png");
    
    sf::Texture dummy;
    for (auto ID: IDList) {
        textureMap[ID].loadFromFile(ID);
    }
    
    IDList.clear();
    IDList.push_back(resourcePath() + "sansation.ttf");
    
    for (auto && ID: IDList) {
        fontMap[ID].loadFromFile(ID);
    }
    
    IDList.clear();
    IDList.push_back(resourcePath() + "nice_music.ogg");
    for (auto && ID: IDList) {
        musicMap[ID].openFromFile(ID);
    }
}

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



//std::map<sf::String, sf::Texture> ResourceHolder::textureMap;
//std::map<sf::String, sf::Font> ResourceHolder::fontMap;
//std::map<sf::String, sf::Music> ResourceHolder::musicMap;