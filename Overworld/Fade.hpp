//
//  Fade.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/25/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "Mode.hpp"

class Fade : public Mode {
public:
    ~Fade() {
        std::cout << "Fade destroyed\n";
    }
    
    Fade(bool inOut, float duration);                //fade in true, fade out false... Yes I realize this is terrible
    void update(float elapsed) override;
    void draw(sf::RenderWindow &rw) override;
    void handleInput(sf::RenderWindow &rw, float elapsed) override;
    modeAction handleEvent() override;
    
private:
    const float totalDuration;
    float fadePercent = 0.f;
    bool inOrOut;
    sf::RectangleShape jankScreenFade;
};
