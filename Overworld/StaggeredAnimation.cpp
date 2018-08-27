//
//  StaggeredAnimation.cpp
//  Overworld
//
//  Created by Noah Kittleson on 8/26/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "StaggeredAnimation.hpp"


StaggeredAnimation::StaggeredAnimation(const sf::Texture& t, sf::Vector2f pos, float defaultTimePerFrame, sf::Vector2i frame) : AnimatedComponent(t, pos, defaultTimePerFrame, frame)  {
	int framesInSprite = t.getSize().x / frame.x;
	for (int iii = 0; iii < framesInSprite; iii++) {
		timePerFrames.push_back(defaultTimePerFrame);
	}
}

void StaggeredAnimation::update(float elapsed) {
	totalElapsed += elapsed;
	if (totalElapsed >= timePerFrames.get()) {
		nextFrame();
		++timePerFrames;
		totalElapsed = 0;
	}
}

void StaggeredAnimation::changeTimePerFrameAt(float time, int frameNo) {
	if (frameNo < timePerFrames.size() && frameNo > 0) {
		timePerFrames[frameNo-1] = time;
	} else {
		//it doesn't work
		std::cout << "Staggered Animation: frame list not long enough.";
	}
}

std::unique_ptr<GraphicsComponent> StaggeredAnimation::getCopy() {
	return std::unique_ptr<GraphicsComponent> (new StaggeredAnimation (*this));
}
