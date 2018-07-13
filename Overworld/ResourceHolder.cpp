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
	//zone backgrounds//
	textureIDMap.insert(std::make_pair("MountainWest.png", Textures::ID::MountainWest));
	textureIDMap.insert(std::make_pair("MountainEast.png", Textures::ID::MountainEast));
	textureIDMap.insert(std::make_pair("BeachNorth.png", Textures::ID::BeachNorth));
	textureIDMap.insert(std::make_pair("MountainSouth.png", Textures::ID::MountainSouth));
	textureIDMap.insert(std::make_pair("TownEast.png", Textures::ID::TownEast));
	textureIDMap.insert(std::make_pair("BeachWest.png", Textures::ID::BeachWest));
	textureIDMap.insert(std::make_pair("Start.png", Textures::ID::Start));
	textureIDMap.insert(std::make_pair("SouthOfStart.png", Textures::ID::SouthOfStart));
	textureIDMap.insert(std::make_pair("Forest.png", Textures::ID::Forest));
	textureIDMap.insert(std::make_pair("Swamp.png", Textures::ID::Swamp));
	textureIDMap.insert(std::make_pair("BeachSouth.png", Textures::ID::BeachSouth));
	textureIDMap.insert(std::make_pair("TownSouth.png", Textures::ID::TownSouth));
	textureIDMap.insert(std::make_pair("LightHouseCoast.png", Textures::ID::LightHouseCoast));
	//props
    textureIDMap.insert(std::make_pair("Stickmaniac.png", Textures::ID::Stickmaniac));
    textureIDMap.insert(std::make_pair("BasicIdle.png", Textures::ID::BasicIdle));
    textureIDMap.insert(std::make_pair("BadAttackAnimation.png", Textures::ID::BadAttackAnimation));
    textureIDMap.insert(std::make_pair("GetHitAnimation.png", Textures::ID::GetHitAnimation));
    textureIDMap.insert(std::make_pair("RollingWheat.png", Textures::ID::BigWheat));
    textureIDMap.insert(std::make_pair("Scarecrow.png", Textures::ID::Scarecrow));
    textureIDMap.insert(std::make_pair("icon.png", Textures::ID::Icon));
    textureIDMap.insert(std::make_pair("tree.png", Textures::ID::Tree));
    textureIDMap.insert(std::make_pair("PlayerWalkingUp.png", Textures::ID::PlayerWalkingUp));
    textureIDMap.insert(std::make_pair("PlayerWalkingDown.png", Textures::ID::PlayerWalkingDown));
    textureIDMap.insert(std::make_pair("PlayerWalkingLeft.png", Textures::ID::PlayerWalkingLeft));
    textureIDMap.insert(std::make_pair("PlayerWalkingRight.png", Textures::ID::PlayerWalkingRight));
	textureIDMap.insert(std::make_pair("Campfire.png", Textures::ID::Campfire));
	textureIDMap.insert(std::make_pair("Yak.png", Textures::ID::Yak));
	textureIDMap.insert(std::make_pair("pond.png", Textures::ID::Pond));
	textureIDMap.insert(std::make_pair("bush.png", Textures::ID::Bush));
	textureIDMap.insert(std::make_pair("Waves.png", Textures::ID::Waves));
	textureIDMap.insert(std::make_pair("SmallWheat.png", Textures::ID::SmallWheat));
	textureIDMap.insert(std::make_pair("DeadTree.png", Textures::ID::DeadTree));
	textureIDMap.insert(std::make_pair("BrickHouse.png", Textures::ID::BrickHouse));
	textureIDMap.insert(std::make_pair("DialogueBar.png", Textures::ID::DialogueBar));
	
    for (auto ID : textureIDMap) {
        textureMap[ID.second].loadFromFile(resourcePath() + ID.first);
    }
    textureIDMap.clear();
	
    //Whenever you add a new font, add to this list
	std::map<sf::String, Fonts::ID> fontIDMap;
	fontIDMap.insert(std::make_pair("sansation.ttf", Fonts::ID::Sansation));
	fontIDMap.insert(std::make_pair("Bramble.ttf", Fonts::ID::Bramble));

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
