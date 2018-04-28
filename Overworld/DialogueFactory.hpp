//
//  DialogueFactory.hpp
//  Overworld
//
//  Created by Noah Kittleson on 4/23/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "TalkNode.h"
#include "OptionNode.h"
#include "ResourceHolder.h"
#include "DialogueIDs.hpp"

//using NodePtr = std::shared_ptr<DNode>;

class DialogueFactory
{
public:
	DialogueFactory() = delete;
	static NodePtr create(Dialogue::ID toCreate, const ResourceHolder& rh);
	
private:
	
};
