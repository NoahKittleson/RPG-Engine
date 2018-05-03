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
	
	std::unique_ptr<sf::Texture> fuckIHadTheseAllAlong;
	
    //Whenever you add a new texture, add to this list
    std::map<sf::String, Textures::ID> textureIDMap;
	textureIDMap.insert(std::make_pair("Mountains.jpg", Textures::ID::Mountains));
    textureIDMap.insert(std::make_pair("Stickmaniac.png", Textures::ID::Stickmaniac));
    textureIDMap.insert(std::make_pair("BasicIdle.png", Textures::ID::BasicIdle));
    textureIDMap.insert(std::make_pair("BadAttackAnimation.png", Textures::ID::BadAttackAnimation));
    textureIDMap.insert(std::make_pair("GetHitAnimation.png", Textures::ID::GetHitAnimation));
    textureIDMap.insert(std::make_pair("RollingWheat.png", Textures::ID::RollingWheat));
    textureIDMap.insert(std::make_pair("Scarecrow.png", Textures::ID::Scarecrow));
    textureIDMap.insert(std::make_pair("cute_image.jpg", Textures::ID::CuteImage));
    textureIDMap.insert(std::make_pair("icon.png", Textures::ID::Icon));
    textureIDMap.insert(std::make_pair("tree.png", Textures::ID::Tree));
    textureIDMap.insert(std::make_pair("PlayerWalkingUp.png", Textures::ID::PlayerWalkingUp));
    textureIDMap.insert(std::make_pair("PlayerWalkingDown.png", Textures::ID::PlayerWalkingDown));
    textureIDMap.insert(std::make_pair("PlayerWalkingLeft.png", Textures::ID::PlayerWalkingLeft));
    textureIDMap.insert(std::make_pair("PlayerWalkingRight.png", Textures::ID::PlayerWalkingRight));
	textureIDMap.insert(std::make_pair("Campfire.png", Textures::ID::Campfire));
	textureIDMap.insert(std::make_pair("Yak.png", Textures::ID::Yak));
	textureIDMap.insert(std::make_pair("testbackground.png", Textures::ID::TestBackground));
	textureIDMap.insert(std::make_pair("pond.png", Textures::ID::Pond));
	
	
    for (auto ID : textureIDMap) {
        textureMap[ID.second].loadFromFile(resourcePath() + ID.first);
    }
    textureIDMap.clear();
	
    //Whenever you add a new font, add to this list
	std::map<sf::String, Fonts::ID> fontIDMap;
	fontIDMap.insert(std::make_pair("sansation.ttf", Fonts::ID::Sansation));

    for (auto && ID : fontIDMap) {
        fontMap[ID.second].loadFromFile(resourcePath() + ID.first);
	}
    fontIDMap.clear();
	
    //Whenever you add a new sound file, add to this list
	std::map<sf::String, Music::ID> musicIDMap;
    musicIDMap.insert(std::make_pair("nice_music.ogg", Music::NiceMusic));
	
    for (auto && ID: musicIDMap) {
        musicMap[ID.second].openFromFile(resourcePath() + ID.first);
    }
}

//Get a texture/sound/font by giving the full file name.
//If nothing is found returns the first result in IDList

const sf::Texture& ResourceHolder::getTexture(Textures::ID ID) const
{
    assert(!textureMap.empty());
    auto find = textureMap.find(ID);
    if (find != textureMap.end()) {
        return find->second;
    }
    else return textureMap.begin()->second;
}

const sf::Font& ResourceHolder::getFont(Fonts::ID ID) const
{
    assert(!fontMap.empty());
    auto find = fontMap.find(ID);
    if (find != fontMap.end()) {
        return find->second;
    }
    else return fontMap.begin()->second;
}

const sf::Music& ResourceHolder::getMusic(Music::ID ID) const
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
