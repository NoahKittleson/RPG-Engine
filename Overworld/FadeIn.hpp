//
//  FadeIn.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/25/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "Mode.hpp"

class FadeIn : public Mode {
public:
    void update(float elapsed) override;
    void draw(sf::RenderWindow &rw) override;
    void handleInput(sf::RenderWindow &rw, float elapsed) override;
    modeAction handleEvent() override;
    
private:
    float fadeProgress = 0.f;
    
};
