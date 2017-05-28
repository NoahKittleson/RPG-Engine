//
//  InputComponent.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/26/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class InputComponent
{
public:
	virtual ~InputComponent() {}
	//InputComponent () {}
	virtual void move(float elapsed);
	
private:
	
};
