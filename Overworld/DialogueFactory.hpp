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

class DialogueFactory
{
public:
	DialogueFactory() = 0;
	enum ID { Error, None, Test001, Test002, };
	static NodePtr create(ID toCreate, const ResourceHolder& rh);
	
private:
	
};
