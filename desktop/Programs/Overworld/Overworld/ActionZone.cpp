//
//  ActionZone.cpp
//  Overworld
//
//  Created by Noah Kittleson on 9/16/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "ActionZone.h"


sf::FloatRect ActionZone::getPosition()
{
	return position;
}

FightZone::FightZone(std::list<Character>& list, sf::FloatRect pos)
: ActionZone(pos), enemylist(&list)
{
}

DialogueZone::DialogueZone(std::list<sf::Text>& texts, sf::FloatRect& pos)
:ActionZone (pos), list (&texts)
{
}


ActionType ActionZone::getType()
{
	return ActionType::None;
}

ActionType DialogueZone::getType()
{
	return ActionType::Dialogue;
}

ActionType FightZone::getType()
{
	return ActionType::Fight;
}




//Saving this code to move into OveworldMode. Or elsewhere?

/*void ActionZone::fadeOut(sf::RenderWindow &rw, sf::Clock& timer)
{
	sf::Texture ScreenCapTexture;
	ScreenCapTexture.loadFromImage(rw.capture());
	sf::Sprite ScreenCapSprite;
	ScreenCapSprite.setTexture(ScreenCapTexture);
	
	float opacity = 255;
	sf::Event event;
	
	while (opacity > 0) {
		rw.setView(rw.getDefaultView());
		rw.pollEvent(event);
		
		rw.clear();
		opacity -= timer.restart().asSeconds() * 100;
		ScreenCapSprite.setColor(sf::Color(opacity, opacity, opacity));
		
		rw.draw(ScreenCapSprite);
		rw.display();
	}
}*/










