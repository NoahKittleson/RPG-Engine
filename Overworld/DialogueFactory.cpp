//
//  DialogueFactory.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/23/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "DialogueFactory.hpp"

using namespace Dialogue;

NodePtr DialogueFactory::create(ID toCreate, const ResourceHolder& rh) {
	switch (toCreate) {
		case ID::Intro01: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
			node->addText("Welcome to my game.  You can press X to continue to the next dialogue.", Speaker::Unknown);
			node->addText("Use the Arrow Keys to walk around.  Go ahead and explore a little bit.", Speaker::Unknown);
			return node;
		}
			
		case ID::Intro02: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
			node->addText("And by the way, you can use X while walking around to interact with certain things and people.", Speaker::Unknown);
			node->addText("Not everyone is friendly though.  You might get into a fight.", Speaker::Unknown);
			node->addText("If you do, I'm sure you'll figure it out.  X is select, Z is go back, and the arrow keys navigate.", Speaker::Unknown);
			node->addText("Anyway, have fun.", Speaker::Unknown);
			return node;
		}
			
		case ID::Error: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
			node->addText("An Unexpected Error has occured.", Speaker::System);
			node->addText("As if There are expected errors?", Speaker::System);
			node->addText("Anyway, sorry about that.", Speaker::System);
			return node;
		}
			
		case ID::None: {
			return nullptr;
		}
			
		case ID::Test001: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
			node->addText("This is a test of the non-emergency systems.", Speaker::Narrator);
			node->addText("(Is this even going to show up?)", Speaker::Narrator);
			std::vector<Condition> reqForNext;
			reqForNext.push_back(Condition::First);
			DPath path1 (ID::Test003, reqForNext);
			node->addPath(path1);
			reqForNext.clear();
			DPath path2 (ID::Test002, reqForNext);
			node->addPath(path2);
			return node;
		}
			
		case ID::Test002: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
			node->addText("Thank you for your cooperation.", Speaker::Narrator);
			node->addConsequence(Condition::First);
			return node;
		}
			
		case ID::Test003: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
			node->addText("Oh wait, this all seems very familiar.", Speaker::Narrator);
			return node;
		}
			
		case ID::GuardStop1: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
			node->addText("Hold it right there, ma'am.  The military is currently using this town as our base of operations.  While the rebels are stationed nearby we can't let any unauthorized personel in.", Speaker::SittingGuard);
			node->addText("If you need to buy supplies, there's another town up to the North-east.", Speaker::SittingGuard);
			node->addText("You don't look too threatening though.  If you want you can try talking to the Colonel and he might let you in.", Speaker::SittingGuard);
			node->addText("He's around the side, guarding the exit to the East.", Speaker::SittingGuard);
			node->addText("Say 'Hi' for me, will ya?", Speaker::SittingGuard);
			return node;
		}
			
		case ID::GuardStop2: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
			node->addText("Hey, come on lady.  I already told you.", Speaker::SittingGuard);
			node->addText("No entry, got it?  Don't make me get up out of this chair.", Speaker::SittingGuard);
			node->addText("If you want to make a fuss, go find to the Colonel.  He's usually at the Eastern entrance.", Speaker::SittingGuard);
			return node;
		}
			
		case ID::ColonelGreeting01: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
			node->addText("Morning, Ma'am.  What business do you have here?", Speaker::TheColonel);
			node->addText("I just need to buy some vanilla", Speaker::OldLady);
			node->addText("Oh, Vanilla. What are you making?", Speaker::TheColonel);
			node->addText(".....", Speaker::OldLady);
			node->addText("I remember my grandma used to make vanilla bean cakes when we visited on Sundays.", Speaker::TheColonel);
			node->addText("Sometimes with lemon.  Or maybe lime?  I can't remember anymore.", Speaker::TheColonel);
			node->addText("I haven't had any since she died.  God knows you never eat like that in the army.", Speaker::TheColonel);
			node->addText("I'm not making vanilla bean cakes.", Speaker::OldLady);
			node->addText("Sorry.", Speaker::OldLady);
			node->addText("No need to apologize. You should be able to find what you need in town.  We've requisitioned most of the meat, fish, and bread but all the fancy stuff like vanilla we left.", Speaker::TheColonel);
			node->addText("You're clearly no threat.", Speaker::TheColonel);
			node->addConsequence(Condition::TownSouthAccess);
			return node;
		}
			
		case ID::StandingGuard01: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
			node->addText("Civilian, halt!", Speaker::StandingGuard);
			node->addText("There is to be no unauthorized personnel entering in this location at this time.", Speaker::StandingGuard);
			node->addText("Er.  I mean, at this location.", Speaker::StandingGuard);
			node->addText("Sorry.", Speaker::StandingGuard);
			return node;
		}
			
//		case ID::MoreDialogue: {
//			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), toCreate);
//			node->addText("Did you just come out of the forest?", Speaker::StandingGuard);
//			node->addText("Not often we get travellers who come from there.", Speaker::StandingGuard);
//			node->addText("I don't know where we came from.", Speaker::StandingGuard);
//
//			node->addText("Once when I was a kid I saw something weird out in the forest", Speaker::StandingGuard);
//			node->addText("", Speaker::StandingGuard);
//
//			//have some dialogue that's a relative or child chiding the mom for... something??
//
//		}
			
//		default:					//I am specifically not going to have a default block so that I know what's missing
//			break;
	}
}


//This is my attempt to NOT have all the dialogue hard coded into the game, but rather have it all written out in a file and perform a lookup/parse whenever I need it.
std::shared_ptr<DNode> DialogueFactory::loadFromFile(int DialogueID, ResourceHolder& rh) {
	std::ifstream inputFile;
	inputFile.open("dialogue.txt", std::ios::in | std::ios::binary);
	
	//if dialogue file cannot be read, the game cannot reasonably be played.
	assert(inputFile);
	
	//this is bad.  Don't do this
	std::string allDialogue;
	inputFile >> allDialogue;
	
	//this searches lines for target dialogue ID one by one, then prints them.
	std::string searchTerm = "[" + std::to_string(DialogueID) + "]";
	std::string oneLine;
	while (inputFile) {
		getline(inputFile, oneLine);
		if (oneLine.find(searchTerm) != std::string::npos) {
			std::cout << oneLine;
		}
	}
	//return a dummy DNode????
	
	inputFile.close();
	std::cout << "Dialogue load completed successfully.\n";
}


