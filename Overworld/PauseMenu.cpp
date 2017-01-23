//
//  PauseMenu.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/10/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "PauseMenu.hpp"

void PauseMenu::save(const std::string &filename) const{
    std::ofstream outputFile;
    outputFile.open(filename, std::ios::out | std::ios::binary);
    
    //save the party
    for(auto character: this->party) {
        //character.save();
    }
    
    //save the map and position
    
    
    //save the triggerlist / eventlist?
    
    outputFile.close();
}
