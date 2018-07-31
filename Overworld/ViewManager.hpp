//
//  ViewManager.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/31/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class ViewManager {
public:
	void ViewToMap(sf::RenderWindow& rw);
	void ViewToHUD(sf::RenderWindow& rw);
	
private:
	sf::View HUD;
	sf::View mapView;
	
	bool onHUD;
};
