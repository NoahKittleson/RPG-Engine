//
//  FadeIn.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/25/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once

class FadeIn  :public OverworldState {
public:
    void update(elapsed) override;
    void draw(rw) override;
    void handleInput() override;
private:
    
};
