//
//  DialogueFactory.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/23/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "DialogueFactory.hpp"

NodePtr DialogueFactory::create(ID toCreate, const ResourceHolder& rh) {
	switch (toCreate) {
		case Error: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Sansation), ID::None);
			node->addText("An Unexpected Error has occured.");
			node->addText("As if There are expected errors?");
			node->addText("Anyway, sorry about that.");
			return node;
		}
			
		case None: {
			return nullptr;
		}
			
		case Test001: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Sansation), ID::Test002);
			node->addText("This is a test of the non-emergency systems.");
			return node;
		}
			
		case Test002: {
			std::shared_ptr<TalkNode> node = std::make_shared<TalkNode>(rh.getFont(Fonts::Sansation), ID::None);
			node->addText("Thank you for your cooperation.");
			return node;
		}
			
//		default:					//I am specifically not going to have a default block so that I know what's missing
//			break;
	}
}
