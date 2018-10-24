//
//  DialogueIDs.cpp
//  Overworld
//
//  Created by Noah Kittleson on 10/23/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "DialogueIDs.hpp"

sf::String Dialogue::speakerToText(Dialogue::Speaker speaker) {
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
