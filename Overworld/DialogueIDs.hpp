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
	enum ID { Intro01, Intro02, Error, None, Test001, Test002, Test003, GuardStop1, GuardStop2 };
	enum Speaker { Narrator, Gabriela, Marquez, SittingGuard, Unknown, System };
	
	sf::String speakerToText(Dialogue::Speaker speaker) {
		switch (speaker) {
			case Dialogue::Narrator:
				return "Unreliable Narrator";
				
			case Dialogue::Gabriela:
				return "Gabriela";
				
			case Dialogue::Marquez:
				return "Marquez";
				
			case Dialogue::SittingGuard:
				return "Sitting Guard";
				
			case Dialogue::Unknown:
				return "?????";
				
			case Dialogue::System:
				return "System";
		}
	}
}



