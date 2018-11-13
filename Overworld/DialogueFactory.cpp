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
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Intro01);
			node->addText("Welcome to my game.  You can press X to continue to the next dialogue.", Dialogue::Unknown);
			node->addText("Use the Arrow Keys to walk around.  Go ahead and explore a little bit.", Dialogue::Unknown);
			return node;
		}
			
		case Dialogue::Intro02: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Intro02);
			node->addText("And by the way, you can use X while walking around to interact with certain things and people.", Dialogue::Unknown);
			node->addText("Not everyone is friendly though.  You might get into a fight.", Dialogue::Unknown);
			node->addText("If you do, I'm sure you'll figure it out.  X is select, Z is go back, and the arrow keys navigate.", Dialogue::Unknown);
			node->addText("Anyway, have fun.", Dialogue::Unknown);
			return node;
		}
			
		case Dialogue::Error: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Error);
			node->addText("An Unexpected Error has occured.", Dialogue::System);
			node->addText("As if There are expected errors?", Dialogue::System);
			node->addText("Anyway, sorry about that.", Dialogue::System);
			return node;
		}
			
		case Dialogue::None: {
			return nullptr;
		}
			
		case Dialogue::Test001: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Test001);
			node->addText("This is a test of the non-emergency systems.", Dialogue::Narrator);
			node->addText("(Is this even going to show up?)", Dialogue::Narrator);
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
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Test002);
			node->addText("Thank you for your cooperation.", Dialogue::Narrator);
			node->addConsequence(Condition::First);
			return node;
		}
			
		case Dialogue::Test003: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Test003);
			node->addText("Oh wait, this all seems very familiar.", Dialogue::Narrator);
			return node;
		}
			
		case Dialogue::GuardStop1: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::GuardStop1);
			node->addText("Hold it right there, ma'am.  The military is currently using this town as our base of operations.  While the rebels are stationed nearby we can't let any unauthorized personel in.", Dialogue::SittingGuard);
			node->addText("If you need to buy supplies, there's another town up to the North-east.", Dialogue::SittingGuard);
			node->addText("You don't look too threatening though.  If you want you can try talking to the Colonel and he might let you in.", Dialogue::SittingGuard);
			node->addText("He's around the side, guarding the exit to the East.", Dialogue::SittingGuard);
			node->addText("Say 'Hi' for me, will ya?", Dialogue::SittingGuard);
			return node;
		}
			
		case Dialogue::GuardStop2: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::GuardStop2);
			node->addText("Hey, come on lady.  I already told you.", Dialogue::SittingGuard);
			node->addText("No entry, got it?  Don't make me get up out of this chair.", Dialogue::SittingGuard);
			node->addText("If you want to make a fuss, go find to the Colonel.  He's usually at the Eastern entrance.", Dialogue::SittingGuard);
			return node;
		}
			
		case Dialogue::ColonelGreeting01: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::ColonelGreeting01);
			node->addText("Morning, Ma'am.  What business do you have here?", Dialogue::TheColonel);
			node->addText("I just need to buy some vanilla", Dialogue::OldLady);
			node->addText("Oh, Vanilla. What are you making?", Dialogue::TheColonel);
			node->addText(".....", Dialogue::OldLady);
			node->addText("I remember my grandma used to make vanilla bean cakes when we visited on Sundays.", Dialogue::TheColonel);
			node->addText("Sometimes with lemon.  Or maybe lime?  I can't remember anymore.", Dialogue::TheColonel);
			node->addText("I haven't had any since she died.  God knows you never eat like that in the army.", Dialogue::TheColonel);
			node->addText("I'm not making vanilla bean cakes.", Dialogue::OldLady);
			node->addText("Sorry.", Dialogue::OldLady);
			node->addText("No need to apologize. You should be able to find what you need in town.  We've requisitioned most of the meat, fish, and bread but all the fancy stuff like vanilla we left.", Dialogue::TheColonel);
			node->addText("You're clearly no threat.", Dialogue::TheColonel);
			return node;
		}
			
//		default:					//I am specifically not going to have a default block so that I know what's missing
//			break;
	}
}

