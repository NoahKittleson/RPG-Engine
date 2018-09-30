//
//  Mode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 3/10/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "Mode.hpp"

Mode::~Mode() {
    /*just for derived classes*/
}

bool Mode::isDone() const {
	return done;
};

