//
//  Fade.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/25/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "Mode.hpp"

enum FadeDirection {in, out};

class Fade : public Mode {
public:
    Fade(FadeDirection inOrOut, float duration);
	~Fade();
	void update(float elapsed, State* context) override;
	void draw(sf::RenderWindow &rw) override;
	void handleInput(sf::RenderWindow &rw) override;
    
protected:
    const float totalDuration;
    float fadePercent = 0.f;
    FadeDirection fadeDir;
    sf::RectangleShape jankScreenFade;
};
