//
//  StaggeredAnimation.cpp
//  Overworld
//
//  Created by Noah Kittleson on 8/26/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "StaggeredAnimation.hpp"


StaggeredAnimation::StaggeredAnimation(const sf::Texture& t, sf::Vector2f pos, IterVector<float> FPS, sf::Vector2i frame) : AnimatedComponent(t, pos, 1, frame), frameLengths(FPS)  {
	int framesInSprite = t.getSize().x / frame.x;
	if (frameLengths.size() != framesInSprite) {
		std::cout << "Staggered Animation frame number mismatch. " << framesInSprite << " in texture, " << t.getSize().x << " in vector\n";
	}
}

void StaggeredAnimation::update(float elapsed) {
	totalElapsed += elapsed;
	if (totalElapsed >= frameLengths.get()) {
		nextFrame();
		++frameLengths;
	}
}

std::unique_ptr<GraphicsComponent> StaggeredAnimation::getCopy() {
	return std::unique_ptr<GraphicsComponent> (new StaggeredAnimation (*this));
}
