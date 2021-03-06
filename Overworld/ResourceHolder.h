//
//  ResourceHolder.h
//  Overworld
//
//  Created by Noah Kittleson on 12/4/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "ResourcePath.hpp"


namespace Textures {
	enum ID {
		MountainWest,
		MountainEast,
		BeachNorth,
		MountainSouth,
		TownEast,
		BeachWest,
		Start,
		SouthOfStart,
		Forest,
		Swamp,
		BeachSouth,
		TownSouth,
		LightHouseCoast,
		BasicIdle,
		BadAttackAnimation,
		GetHitAnimation,
		BigWheat,
		Scarecrow,
		Icon,
		Tree,
		PlayerWalkingUp,
		PlayerWalkingDown,
		PlayerWalkingLeft,
		PlayerWalkingRight,
		PlayerWalkingUp2,
		PlayerWalkingDown2,
		PlayerWalkingLeft2,
		PlayerWalkingRight2,
		Campfire,
		Yak,
		Pond,
		Bush,
		WavesWest,
		SmallWheat,
		BrickHouse,
		DeadTree,
		DialogueBar,
		BikiniBabe,
		BasicDead,
		GetKilled,
		Lighthouse,
		Store1,
		TheColonel,
		SittingSoldierAnim,
		SalutingSoldier,
		Clocktower,
		BuildingOutline2,
		BuildingOutline3,
		BuildingOutline4,
		BuildingOutline5,
		BuildingOutline6,
		BuildingOutline7,
		BuildingOutline8,
		BuildingOutline9,
		Fountain,
		Booth,
		BoothAnimation,
		WavesSouth,
		Docks,
		Point,
		SittingSoldierBig,
		Garden,
		Shed,
		ListeningMan,
		TheDrunk,
		Couple1,
		Couple2,
		Bystander1,
		Bystander2,
		SittingFisherman,
		MainMenuBackground,
		RandomLighting,
		Tree1,
		Tree2,
		Tree3,
		Tree4,
		Tree5,
		Tree6
	};
}

namespace Fonts {
	enum ID {
		Sansation,
		Bramble
	};
}

namespace Music {
	enum ID {
		NiceMusic
	};
}

class ResourceHolder : public sf::NonCopyable
{
public:
    ResourceHolder();
    
    const sf::Texture& getTexture(Textures::ID ID) const;
	const sf::Font& getFont(Fonts::ID ID) const;
	const sf::Music& getMusic(Music::ID ID) const;
    
private:
    static bool instantiated;
    
    std::map<Textures::ID, sf::Texture> textureMap;
    std::map<Fonts::ID, sf::Font> fontMap;
    std::map<Music::ID, sf::Music> musicMap;
};

