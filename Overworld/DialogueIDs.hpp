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

namespace Dialogue {
	enum class ID { Intro01, Intro02, Error, None, Test001, Test002, Test003, GuardStop1, GuardStop2, ColonelGreeting01, StandingGuard01 };
	enum class Speaker { Narrator, Gabriela, Marquez, SittingGuard, Unknown, System, TheColonel, OldLady, StandingGuard };
	
	typedef boost::bimap<Dialogue::Speaker, std::string> speakerBiMap;
	typedef speakerBiMap::value_type idPair;
	
	sf::String speakerToText(Dialogue::Speaker speaker);
	Dialogue::Speaker textToSpeaker(std::string text);
	
	//static std::map<Dialogue::Speaker, std::string> speakerMap;
	speakerBiMap getSpeakerMap();
	
	static map<int, char> m = {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};
	static speakerBiMap test = {{Speaker::Narrator, "test"}, {Speaker::Gabriela, "one"}, {Speaker::Marquez, "two"}, {Speaker::OldLady, "dddd"}};
	
}

struct Identifier {
	sf::String characterName;
	Dialogue::Speaker characterID;
	//font?
	//art?
};



