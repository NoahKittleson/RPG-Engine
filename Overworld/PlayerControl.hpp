//
//  PlayerControl.hpp
//  Overworld
//
//  Created by Noah Kittleson on 6/9/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "InputComponent.hpp"

class PlayerControl : public InputComponent
{
public:
	virtual void update(float elapsed) override;
	
private:
	virtual void updateSprite(WalkingAnimation* spr);
	
};
