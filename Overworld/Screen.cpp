//
//  Screen.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/31/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "Screen.hpp"

Screen::Screen()
{
	HUD = getDefaultView();
	mapView = HUD;
	mapView.zoom(0.5);
	onHUD = true;
	setView(HUD);
}

void Screen::ViewToMap() {
	if (!onHUD) {
		return;
	} else {
		HUD = getView();
		setView(mapView);
		onHUD = false;
	}
}

void Screen::ViewToHUD() {
	if (onHUD) {
		return;
	} else {
		mapView = getView();
		setView(HUD);
		onHUD = true;
	}
}
