//
//  MapSection.h
//  Overworld
//
//  Created by Noah Kittleson on 6/4/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "ActionZone.h"
#include "InteractableObject.h"

class ZoneExit;

typedef std::list<ZoneExit> ZE_List;
typedef std::list<InteractableObject> IO_List;
typedef std::list<ActionZone*> AZptr_List;


class MapSection: sf::NonCopyable
{
public:
    MapSection(sf::String filename, ZE_List& zonelist, IO_List&,  AZptr_List&);
    
    void DrawAllObjects(sf::RenderWindow &rw, Player&);
    void AddExit(sf::FloatRect pos, sf::Vector2f offset, MapSection* next);
    IO_List& getObjectList();
    const ZE_List& getExitList();
    const AZptr_List& getTriggerList();
    const sf::Texture& getBackground();
    
private:
    void addObject(const InteractableObject&);
    
    sf::Texture backgroundTexture;
    AZptr_List triggerList;
    ZE_List exitList;
    IO_List objList;
};


class ZoneExit
{
public:
    ZoneExit(sf::FloatRect pos, sf::Vector2f offset, MapSection*& next)
    : coordinates(pos), coordinateOffset(offset), newZone(next)
    {
    }
    sf::FloatRect getCoordinates() const;
    MapSection* getNextZone() const;
    void MoveSpriteToNewZone(Player&, sf::View&) const;
    
private:
    MapSection*& newZone;
    const sf::FloatRect coordinates;
    const sf::Vector2f coordinateOffset;
    
    friend class MapSection;
};








