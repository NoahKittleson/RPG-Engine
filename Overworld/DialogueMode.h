//
//  DManager.h
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "TalkNode.h"
#include "OptionNode.h"
#include "State.h"

class DialogueMode : public State
{
public:
    DialogueMode(DNode* start, const sf::RenderWindow&rw);
    
    
    //void update(sf::RenderWindow&, sf::Clock&) override;
    void update(sf::Clock &clock) override;//float elapsed, sf::Event&);
    void draw(sf::RenderWindow&) override;
    void handleInput(sf::RenderWindow& rw) override;
    
private:
    sf::View mapView;
    sf::View HUD;
    
    DNode* currentDNode;
    sf::RectangleShape messageBox;
};
