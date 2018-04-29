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
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Sansation), Dialogue::None);
			node->addText("An Unexpected Error has occured.");
			node->addText("As if There are expected errors?");
			node->addText("Anyway, sorry about that.");
			return node;
		}
			
		case Dialogue::None: {
			return nullptr;
		}
			
		case Dialogue::Test001: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Sansation), Dialogue::Test002);
			node->addText("This is a test of the non-emergency systems.");
			node->addText("(Is this even going to show up?)");
			node->addConsequence(Condition::First);
			return node;
		}
			
		case Dialogue::Test002: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Sansation), Dialogue::Test003);
			node->addText("Thank you for your cooperation.");
			return node;
		}
			
		case Dialogue::Test003: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Sansation), Dialogue::None);
			node->addText("Oh wait, this all seems very familiar.");
			node->addPreReq(Condition::First);
			return node;
		}
			
//		default:					//I am specifically not going to have a default block so that I know what's missing
//			break;
	}
}
