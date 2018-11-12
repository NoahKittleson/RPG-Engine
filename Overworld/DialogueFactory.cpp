//
//  DialogueFactory.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/23/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "DialogueFactory.hpp"


NodePtr DialogueFactory::create(Dialogue::ID toCreate, const ResourceHolder& rh) {
	switch (toCreate) {
		case Dialogue::Intro01: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Intro01, Dialogue::Unknown);
			node->addText("Welcome to my game.  You can press X to continue to the next dialogue.");
			node->addText("Use the Arrow Keys to walk around.  Go ahead and explore a little bit.");
			return node;
		}
			
		case Dialogue::Intro02: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Intro02, Dialogue::Unknown);
			node->addText("And by the way, you can use X while walking around to interact with certain things and people.");
			node->addText("Not everyone is friendly though.  You might get into a fight.");
			node->addText("If you do, I'm sure you'll figure it out.  X is select, Z is go back, and the arrow keys navigate.");
			node->addText("Anyway, have fun.");
			return node;
		}
			
		case Dialogue::Error: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Error, Dialogue::System);
			node->addText("An Unexpected Error has occured.");
			node->addText("As if There are expected errors?");
			node->addText("Anyway, sorry about that.");
			return node;
		}
			
		case Dialogue::None: {
			return nullptr;
		}
			
		case Dialogue::Test001: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Test001, Dialogue::Narrator);
			node->addText("This is a test of the non-emergency systems.");
			node->addText("(Is this even going to show up?)");
			std::vector<Condition> reqForNext;
			reqForNext.push_back(Condition::First);
			DPath path1 (Dialogue::Test003, reqForNext);
			node->addPath(path1);
			reqForNext.clear();
			DPath path2 (Dialogue::Test002, reqForNext);
			node->addPath(path2);
			return node;
		}
			
		case Dialogue::Test002: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Test002, Dialogue::Narrator);
			node->addText("Thank you for your cooperation.");
			node->addConsequence(Condition::First);
			return node;
		}
			
		case Dialogue::Test003: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Test003, Dialogue::Narrator);
			node->addText("Oh wait, this all seems very familiar.");
			return node;
		}
			
		case Dialogue::GuardStop1: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::GuardStop1, Dialogue::SittingGuard);
			node->addText("Hold it right there, ma'am.  The military is currently using this town as our base of operations.  While the rebels are stationed nearby we can't let any unauthorized personel in.");
			node->addText("If you need to buy supplies, there's another town up to the North-east.");
			node->addText("You don't look too threatening though.  If you want you can try talking to the Colonel and he might let you in.");
			node->addText("He's around the side, guarding the exit to the East.");
			node->addText("Say 'Hi' for me, will ya?");
			return node;
		}
			
		case Dialogue::GuardStop2: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::GuardStop2, Dialogue::SittingGuard);
			node->addText("Hey, come on lady.  I already told you.");
			node->addText("No entry, got it?  Don't make me get up out of this chair.");
			node->addText("If you want to make a fuss, go find to the Colonel.  He's usually at the Eastern entrance.");
			return node;
		}
			
		case Dialogue::ColonelGreeting01: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::ColonelGreeting01, Dialogue::TheColonel);
			node->addText("Morning, Ma'am.  What business do you have here?");
			node->addPath(DPath(Dialogue::ColonelGreeting02));
			return node;
		}
			
		case Dialogue::ColonelGreeting02: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::ColonelGreeting02, Dialogue::OldLady);
			node->addText("I need to buy a loaf of bread.");
			node->addPath(DPath(Dialogue::ColonelGreeting02));
			return node;
		}
			
//		default:					//I am specifically not going to have a default block so that I know what's missing
//			break;
	}
}

