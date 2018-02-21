//
//  PauseMenu.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/10/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "State.h"
#include <fstream>

class PauseMenu: public State {
public:
    PauseMenu();
    
    void update(sf::Clock &clock) override;
    void draw(sf::RenderWindow&) override;
    void handleInput(sf::RenderWindow& rw) override;
    
private:
    IterVector<sf::Text> menuOptions;
    sf::RectangleShape menuBox;
    
    void save (const std::string& filename) const;
    
};


