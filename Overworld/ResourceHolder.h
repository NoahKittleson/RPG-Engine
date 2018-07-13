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
		Stickmaniac,
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
		Campfire,
		Yak,
		Pond,
		Bush,
		Waves,
		SmallWheat,
		BrickHouse,
		DeadTree,
		DialogueBar,
		
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

