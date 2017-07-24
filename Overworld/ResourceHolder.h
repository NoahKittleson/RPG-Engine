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
		Mountains,
		Stickmaniac,
		BasicIdle,
		BadAttackAnimation,
		GetHitAnimation,
		RollingWheat,
		Scarecrow,
		cute_image,
		icon,
		tree,
		PlayerWalkingUp,
		PlayerWalkingDown,
		PlayerWalkingLeft,
		PlayerWalkingRight,
		Campfire,
		Yak
	};
}

namespace Fonts {
	enum class ID {
		Sansation
	};
}

namespace Music {
	enum ID {
		nice_music
	};
}

class ResourceHolder : public sf::NonCopyable
{
public:
    ResourceHolder();
    
    const sf::Texture& getTexture(Textures::ID ID) const;
    const sf::Font& getFont(sf::String ID) const;
    const sf::Music& getMusic(sf::String ID) const;
    
private:
    static bool instantiated;
    
    std::map<Textures::ID, sf::Texture> textureMap;
    std::map<sf::String, sf::Font> fontMap;
    std::map<sf::String, sf::Music> musicMap;
};

