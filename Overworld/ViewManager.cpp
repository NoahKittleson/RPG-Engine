//
//  ViewManager.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/31/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "ViewManager.hpp"

ViewManager::ViewManager(sf::View& hud, sf::View& map, bool onhud)
: HUD(hud), mapView(map), onHUD(onhud)
{
}

void ViewManager::ViewToMap(sf::RenderWindow& rw) {
	if (!onHUD) {
		return;
	} else {
		HUD = rw.getView();
		rw.setView(mapView);
		onHUD = false;
	}
}

void ViewManager::ViewToHUD(sf::RenderWindow& rw) {
	if (onHUD) {
		return;
	} else {
		mapView = rw.getView();
		rw.setView(HUD);
		onHUD = true;
	}
}
