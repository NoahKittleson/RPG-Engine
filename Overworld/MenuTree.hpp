//
//  MenuTree.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class MenuTree
{
public:
	MenuTree(/*combatant list?*/);
	MenuTreeNode& getCurrent();
	
private:
	std::vector<MenuTreeNode> children;
	
};
