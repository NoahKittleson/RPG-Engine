//
//  BlinkFade.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/22/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "Fade.hpp"

class BlinkFade : public Fade
{
public:
	BlinkFade(bool inOut, float duration);
	void update(float elapsed, State* context) override;
	
private:
	bool fadeToBlack = true;
	float blinkTimer = 0.f;
	float blinkLength = 0.3f; 				//magic number?
};
