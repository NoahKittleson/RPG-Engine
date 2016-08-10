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

class Game
{
public:
    Game();
    ~Game();
	
	static void run();
	static sf::RenderWindow mainWindow;
	static StateStack gameStack;
	static ResourceHolder resourceHolder;
	static sf::Clock gameTimer;
};


//I'm considering a change from layers to states, in order to make things more ordered, readable, understandable, and followable.
//I'd like to compile a list of things that each state (Overworld, Battle, and Dialogue) need in order to function, then I could
//just keep each one here, as private memebers and call each one accordingly (switch states easily).
//Overworld needs:
//	-clock
//	-rw
//	-mapsection
//	-playerSprite
//
//Battlemode needs:
//	-clock
//	-rw
//	-party
//
//Dialoguemode needs:
//	-clock
//	-rw
//	-DialogueThread (probably from InteractableObject)
//	-mapsection (only for drawing purposes)
//	-playerSprite (only for drawing)