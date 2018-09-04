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
	textureIDMap.insert(std::make_pair("PlayerWalkingUp2.png", Textures::ID::PlayerWalkingUp2));
	textureIDMap.insert(std::make_pair("PlayerWalkingDown2.png", Textures::ID::PlayerWalkingDown2));
	textureIDMap.insert(std::make_pair("PlayerWalkingLeft2.png", Textures::ID::PlayerWalkingLeft2));
	textureIDMap.insert(std::make_pair("PlayerWalkingRight2.png", Textures::ID::PlayerWalkingRight2));
	textureIDMap.insert(std::make_pair("Campfire.png", Textures::ID::Campfire));
	textureIDMap.insert(std::make_pair("Yak.png", Textures::ID::Yak));
	textureIDMap.insert(std::make_pair("pond.png", Textures::ID::Pond));
	textureIDMap.insert(std::make_pair("bush.png", Textures::ID::Bush));
	textureIDMap.insert(std::make_pair("WavesWest.png", Textures::ID::WavesWest));
	textureIDMap.insert(std::make_pair("SmallWheat.png", Textures::ID::SmallWheat));
	textureIDMap.insert(std::make_pair("DeadTree.png", Textures::ID::DeadTree));
	textureIDMap.insert(std::make_pair("BrickHouse.png", Textures::ID::BrickHouse));
	textureIDMap.insert(std::make_pair("DialogueBar.png", Textures::ID::DialogueBar));
	textureIDMap.insert(std::make_pair("BikiniBabe.png", Textures::ID::BikiniBabe));
	textureIDMap.insert(std::make_pair("BasicDead.png", Textures::ID::BasicDead));
	textureIDMap.insert(std::make_pair("GetKilled.png", Textures::ID::GetKilled));
	textureIDMap.insert(std::make_pair("Lighthouse.png", Textures::ID::Lighthouse));
	textureIDMap.insert(std::make_pair("StoreOutline.png", Textures::ID::Store1));
	textureIDMap.insert(std::make_pair("ColonelAnim.png", Textures::ID::TheColonel));
	textureIDMap.insert(std::make_pair("SittingSoldierAnim.png", Textures::ID::SittingSoldierAnim));
	textureIDMap.insert(std::make_pair("SalutingSoldier.png", Textures::ID::SalutingSoldier));
	textureIDMap.insert(std::make_pair("Clocktower.png", Textures::ID::Clocktower));
	textureIDMap.insert(std::make_pair("BuildingOutline2.png", Textures::ID::BuildingOutline2));
	textureIDMap.insert(std::make_pair("BuildingOutline3.png", Textures::ID::BuildingOutline3));
	textureIDMap.insert(std::make_pair("BuildingOutline4.png", Textures::ID::BuildingOutline4));
	textureIDMap.insert(std::make_pair("BuildingOutline5.png", Textures::ID::BuildingOutline5));
	textureIDMap.insert(std::make_pair("BuildingOutline6.png", Textures::ID::BuildingOutline6));
	textureIDMap.insert(std::make_pair("BuildingOutline7.png", Textures::ID::BuildingOutline7));
	textureIDMap.insert(std::make_pair("BuildingOutline8.png", Textures::ID::BuildingOutline8));
	textureIDMap.insert(std::make_pair("BuildingOutline9.png", Textures::ID::BuildingOutline9));
	textureIDMap.insert(std::make_pair("Fountain.png", Textures::ID::Fountain));
	textureIDMap.insert(std::make_pair("Booth.png", Textures::ID::Booth));
	textureIDMap.insert(std::make_pair("BoothAnimation.png", Textures::ID::BoothAnimation));
	textureIDMap.insert(std::make_pair("WavesSouth.png", Textures::ID::WavesSouth));
	textureIDMap.insert(std::make_pair("docks.png", Textures::ID::Docks));
	textureIDMap.insert(std::make_pair("point.png", Textures::ID::Point));
	textureIDMap.insert(std::make_pair("SittingSoldierBig.png", Textures::ID::SittingSoldierBig));
	textureIDMap.insert(std::make_pair("Garden.png", Textures::ID::Garden));
	textureIDMap.insert(std::make_pair("Shed.png", Textures::ID::Shed));
	textureIDMap.insert(std::make_pair("ListeningManAnim.png", Textures::ID::ListeningMan));
	textureIDMap.insert(std::make_pair("DrunkAnim.png", Textures::ID::TheDrunk));
	textureIDMap.insert(std::make_pair("Couple1.png", Textures::ID::Couple1));
	textureIDMap.insert(std::make_pair("Couple2.png", Textures::ID::Couple2));
	textureIDMap.insert(std::make_pair("Bystander1.png", Textures::ID::Bystander1));
	textureIDMap.insert(std::make_pair("Bystander2.png", Textures::ID::Bystander2));



	
	
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
