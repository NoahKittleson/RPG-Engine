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
			NodePtr node = std::make_shared<TalkNode>(rh.getFont(Fonts::Sansation), ID::None);
			node->addText("An Unexpected Error has occured.");
			node->addText("As if There are expected errors?");
			node->addText("Anyway, sorry about that.");
			break;
		}
			
		case None: {
			return nullptr;
			break;
		}
			
		default:
			break;
	}
}
