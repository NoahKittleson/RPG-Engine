//
//  Game.h
//  Overworld
//
//  Created by Noah Kittleson on 4/20/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "OverworldMode.h"
#include "StartingZone.h"
#include "LoadState.hpp"

class Game
{
public:
    Game();
    ~Game();
	
	static void run();
	static sf::RenderWindow mainWindow;
	static StateStack gameStack;
	static sf::Clock gameTimer;
};
