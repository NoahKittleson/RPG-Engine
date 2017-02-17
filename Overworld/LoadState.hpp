//
//  LoadState.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/12/17.
//  Copyright © 2017 Noah. All rights reserved.
//
#pragma once
#include "State.h"


class LoadState: public State
{
public:
    LoadState(StateStack& stack);
    ActionID handleEvent();
    void update(sf::RenderWindow&, sf::Clock&);
    void draw(sf::RenderWindow&);
};

//Things to do:
//1. Change Map to not be dynamically allocated.  Get rid of dynamic allocation.  Currently there is memory leak- TOP PRIORITY
