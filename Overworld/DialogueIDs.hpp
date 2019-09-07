//
//  DialogueIDs.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/23/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include <boost/bimap.hpp>
#include <boost/assign.hpp>

namespace Dialogue {
	enum class ID { Intro01, Intro02, Error, None, Test001, Test002, Test003, GuardStop1, GuardStop2, ColonelGreeting01, StandingGuard01 };
	enum class Speaker { Narrator, Gabriela, Marquez, SittingGuard, Unknown, System, TheColonel, OldLady, StandingGuard };
	
	sf::String speakerToText(Dialogue::Speaker speaker);
	Dialogue::Speaker textToSpeaker(std::string text);
	
//	SpeakerBiMap getSpeakerMap();
//	static SpeakerBiMap test = getSpeakerMap();

	typedef boost::bimap<Dialogue::Speaker, std::string> SpeakerBiMap;
	typedef SpeakerBiMap::value_type idPair;
	
	const static SpeakerBiMap speakerMap = boost::assign::list_of< SpeakerBiMap::relation >
	(Speaker::OldLady, 		"Isabel")
	(Speaker::Narrator,		"Narrator")
	(Speaker::OldLady, 		"Isabel")
	(Speaker::Narrator,		"Narrator")
	(Speaker::Gabriela, 	"Gabriela")
	(Speaker::SittingGuard, "Sitting Guard")
	(Speaker::StandingGuard,"Standing Guard")
	(Speaker::TheColonel, 	"The Colonel")
	(Speaker::Unknown, 		"??????")
	(Speaker::System, 		"System");

	
}

struct Identifier {
	sf::String characterName;
	Dialogue::Speaker characterID;
	//font?
	//art?
};



