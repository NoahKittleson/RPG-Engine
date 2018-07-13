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
		case Dialogue::Error: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Error);
			node->addText("An Unexpected Error has occured.");
			node->addText("As if There are expected errors?");
			node->addText("Anyway, sorry about that.");
			return node;
		}
			
		case Dialogue::None: {
			return nullptr;
		}
			
		case Dialogue::Test001: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Test001);
			node->addText("This is a test of the non-emergency systems.");
			node->addText("(Is this even going to show up?)");
			std::vector<Condition> reqForNext;
			reqForNext.push_back(Condition::First);
			DPath path1 (reqForNext, Dialogue::Test003);
			node->addPath(path1);
			reqForNext.clear();
			DPath path2 (reqForNext, Dialogue::Test002);
			node->addPath(path2);
			return node;
		}
			
		case Dialogue::Test002: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Test002);
			node->addText("Thank you for your cooperation.");
			node->addConsequence(Condition::First);
			return node;
		}
			
		case Dialogue::Test003: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Bramble), Dialogue::Test003);
			node->addText("Oh wait, this all seems very familiar.");
			return node;
		}
			
//		default:					//I am specifically not going to have a default block so that I know what's missing
//			break;
	}
}
