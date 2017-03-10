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


class ResourceHolder : public sf::NonCopyable
{
public:
    ResourceHolder();
    
    const sf::Texture& getTexture(sf::String ID) const;
    const sf::Font& getFont(sf::String ID) const;
    const sf::Music& getMusic(sf::String ID) const;
    
private:
    static bool instantiated;
    
    std::map<sf::String, sf::Texture> textureMap;
    std::map<sf::String, sf::Font> fontMap;
    std::map<sf::String, sf::Music> musicMap;
};

