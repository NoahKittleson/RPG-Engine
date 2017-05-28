//
//  PlayerMovement.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/26/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "InputComponent.hpp"

class PlayerMovement : public InputComponent {
public:
	virtual void move(float elapsed) override;
	
private:
	
	
};
