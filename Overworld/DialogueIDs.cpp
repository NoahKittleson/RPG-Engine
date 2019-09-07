//
//  DialogueIDs.cpp
//  Overworld
//
//  Created by Noah Kittleson on 10/23/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "DialogueIDs.hpp"

Dialogue::Speaker Dialogue::textToSpeaker(std::string text) {
	auto pair = speakerMap.right.find(text);
	if (pair != speakerMap.right.end()) {
		return pair->second;
	}
	return Speaker::Unknown;
}

sf::String Dialogue::speakerToText(Dialogue::Speaker speaker) {
	auto pair = speakerMap.left.find(speaker);
	if (pair != speakerMap.left.end()) {
		return pair->second;
	}
	return "Unknown";
}


//SET FOR REMOVAL IF ABOVE WORKS^^^

//boost::bimap<Dialogue::Speaker, std::string> Dialogue::getSpeakerMap() {
//	boost::bimap<Dialogue::Speaker, std::string> map;
//	map.insert(idPair(Speaker::OldLady, 		"Isabel"));
//	map.insert(idPair(Speaker::Narrator,		"Narrator"));
//	map.insert(idPair(Speaker::Gabriela, 		"Gabriela"));
//	map.insert(idPair(Speaker::SittingGuard, 	"Sitting Guard"));
//	map.insert(idPair(Speaker::StandingGuard, 	"Standing Guard"));
//	map.insert(idPair(Speaker::TheColonel, 		"The Colonel"));
//	map.insert(idPair(Speaker::Unknown, 		"??????"));
//	map.insert(idPair(Speaker::System, 			"System"));
//	return map;
//}
//sf::String Dialogue::speakerToText(Dialogue::Speaker speaker) {
//	switch (speaker) {
//		case Dialogue::Speaker::Narrator:
//			return "Unreliable Narrator";
//
//		case Dialogue::Speaker::Gabriela:
//			return "Gabriela";
//
//		case Dialogue::Speaker::Marquez:
//			return "Marquez";
//
//		case Dialogue::Speaker::SittingGuard:
//			return "Sitting Guard";
//
//		case Dialogue::Speaker::StandingGuard:
//			return "Standing Guard";
//
//		case Dialogue::Speaker::Unknown:
//			return "?????";
//
//		case Dialogue::Speaker::TheColonel:
//			return "The Colonel";
//
//		case Dialogue::Speaker::OldLady:
//			return "Isabel";
//
//		case Dialogue::Speaker::System:
//			return "System";
//	}
//}




