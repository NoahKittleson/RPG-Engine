//
//  DialogueIDs.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/23/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

namespace Dialogue {
	enum class ID { Intro01, Intro02, Error, None, Test001, Test002, Test003, GuardStop1, GuardStop2, ColonelGreeting01, StandingGuard01 };
	enum class Speaker { Narrator, Gabriela, Marquez, SittingGuard, Unknown, System, TheColonel, OldLady, StandingGuard };
	
	sf::String speakerToText(Dialogue::Speaker speaker);
}



