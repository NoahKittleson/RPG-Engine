//
//  Screen.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/31/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class Screen : public sf::RenderWindow {
public:
	Screen();
	void ViewToMap();
	void ViewToHUD();
	
private:
	sf::View HUD;
	sf::View mapView;
	
	bool onHUD;
};
