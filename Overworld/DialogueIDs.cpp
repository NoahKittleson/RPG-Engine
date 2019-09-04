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
		case Dialogue::Speaker::Narrator:
			return "Unreliable Narrator";
			
		case Dialogue::Speaker::Gabriela:
			return "Gabriela";
			
		case Dialogue::Speaker::Marquez:
			return "Marquez";
			
		case Dialogue::Speaker::SittingGuard:
			return "Sitting Guard";
			
		case Dialogue::Speaker::StandingGuard:
			return "Standing Guard";
			
		case Dialogue::Speaker::Unknown:
			return "?????";
			
		case Dialogue::Speaker::TheColonel:
			return "The Colonel";
			
		case Dialogue::Speaker::OldLady:
			return "Isabel";
			
		case Dialogue::Speaker::System:
			return "System";
	}
}

//Now I just need a way of having speakerMap initialized at all times

Dialogue::Speaker Dialogue::textToSpeaker(std::string text) {
	for (auto & character : speakerMap) {
		if (character.second == text) {
			return character.first;
		}
	}
	//speaker not found
	return Speaker::Unknown;
}

//sf::String Dialogue::speakerToText(Dialogue::Speaker speaker) {
//	return speakerMap[speaker];
//}


boost::bimap<Dialogue::Speaker, std::string> Dialogue::getSpeakerMap() {
	boost::bimap<Dialogue::Speaker, std::string> map;
	map.insert(idPair(Speaker::OldLady, 		"Isabel"));
	map.insert(idPair(Speaker::Narrator,		"Narrator"));
	map.insert(idPair(Speaker::Gabriela, 		"Gabriela"));
	map.insert(idPair(Speaker::SittingGuard, 	"Sitting Guard"));
	map.insert(idPair(Speaker::StandingGuard, 	"Standing Guard"));
	map.insert(idPair(Speaker::TheColonel, 		"The Colonel"));
	map.insert(idPair(Speaker::Unknown, 		"??????"));
	map.insert(idPair(Speaker::System, 			"System"));
}



