//
//  Game.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/20/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}


void Game::run()
{
	//load everything...
	mainWindow.create (sf::VideoMode (1024, 768, 32), "ViewMaker");
	mainWindow.setFramerateLimit(60);
	mainWindow.setVerticalSyncEnabled(true);

	//add a state to the stack so I have something to run
	auto loadMode = new LoadState(gameStack);
	auto startMode = new OverworldMode();
	gameStack.addState(startMode);
	delete loadMode;

	while (mainWindow.isOpen()) {
		//float elapsed = gameTimer.restart().asSeconds();
		while (gameStack.getCurrentState()->checkDeletion()) {		//could run out stack?
			gameStack.popTop();
		}
		resolveTrigger(gameStack.getCurrentState()->handleEvent());
		gameStack.getCurrentState()->update(mainWindow, gameTimer);
		gameStack.getCurrentState()->draw(mainWindow);
	}
}

void Game::resolveTrigger(ActionID action) {
	switch (action) {
		case ActionID::Fight:
			//addToStack(new BattleMode (action));
			break;
			
		case ActionID::Talk:
			//addToStack(new DialogueMode (action));
			break;
			
		default:
			break;
	}
}


sf::RenderWindow Game::mainWindow;
sf::Clock Game::gameTimer;
StateStack Game::gameStack;


//Saving this mostly for the pre-written abilities and such that I will add back in later
/*
void Game::Start()
{
	//eventually add something to prevent multiple instances of this occuring.
	mainWindow.create (sf::VideoMode (1024, 768, 32), "ViewMaker");
	mainWindow.setFramerateLimit(60);
	mainWindow.setVerticalSyncEnabled(true);
	
	sf::Texture texture;
	texture.loadFromFile("icon.png");
	
	sf::Texture characterTexture;
//	characterTexture.loadFromFile("Stickmaniac.png");
//	Player playerCharacter (characterTexture, sf::Vector2f(50,50));
	
	std::list<InteractableObject> ObjList;
	{
		sf::FloatRect Rectangle (texture.getSize().x/2,texture.getSize().y/2,10,10);
		std::list<sf::FloatRect> boxlist;
		boxlist.push_back(Rectangle);
		InteractableObject Object1 (texture, sf::Vector2f (0,500), boxlist);
		ObjList.push_back(Object1);
		
		boxlist.clear();
		boxlist.push_back(sf::FloatRect(texture.getSize().x/2,texture.getSize().y/2,10,50));
		boxlist.push_back(sf::FloatRect(texture.getSize().x/2,texture.getSize().y/2,50,10));
		InteractableObject Object2 (texture, sf::Vector2f (900,100), boxlist);
		ObjList.push_back(Object2);
		
		//testing shit out.....
		boxlist.clear();
		boxlist.push_back(sf::FloatRect(texture.getSize().x/4,
										texture.getSize().y/4,
										texture.getSize().x/2,
										texture.getSize().y/2));
		ObjList.emplace_front(texture, sf::Vector2f (200,200), boxlist);
	}
	
	
	//lets try making a MapSection item or two.
	sf::Texture Wheat;
	Wheat.loadFromFile("RollingWheat.png");
	std::list<sf::FloatRect> emptyList;
	InteractableObject WheatField (Wheat, sf::Vector2f(0,0), emptyList);
	WheatField.setScale(3.0f);
	
	for (int iii = 0; iii < 6; iii++) {
		ObjList.push_back(WheatField);
		WheatField.move(20, 0);
		ObjList.push_back(WheatField);
		WheatField.move(0, 20);
	}
	
	
	
	MapSection* ToNextPtr = nullptr;
	MapSection* ToStartPtr = nullptr;
	
	std::list<ZoneExit> StartingZoneExits;			//1920 by 1200 mountain jpg
	{
		ZoneExit top(sf::FloatRect(0,-100,1920,100), sf::Vector2f(0,550), ToNextPtr);
		ZoneExit left(sf::FloatRect(-100,0,100,1200), sf::Vector2f(750,0), ToNextPtr);
		ZoneExit right(sf::FloatRect(1920,0,100,1200), sf::Vector2f(-1870,0), ToNextPtr);
		ZoneExit bottom(sf::FloatRect(0,1200,1920,100), sf::Vector2f(0,-1150), ToNextPtr);
		StartingZoneExits.push_front(top);
		StartingZoneExits.push_front(left);
		StartingZoneExits.push_front(right);
		StartingZoneExits.push_front(bottom);
	}
	std::list<ZoneExit> NextZoneExits;				//800 by 600 cute image
	{
		ZoneExit top (sf::FloatRect(0, -100, 800, 100), sf::Vector2f(0, 1150), ToStartPtr);
		ZoneExit bottom (sf::FloatRect(0, 600, 800, 100), sf::Vector2f(0,-500), ToStartPtr);
		ZoneExit left (sf::FloatRect(-100, 0, 100, 600), sf::Vector2f(1870, 0), ToStartPtr);
		ZoneExit right (sf::FloatRect(800,0,100,600), sf::Vector2f(-750, 0), ToStartPtr);
		NextZoneExits.push_front(top);
		NextZoneExits.push_front(bottom);
		NextZoneExits.push_front(left);
		NextZoneExits.push_front(right);
	}
	
	//making an ActionZone
	std::list<InteractableObject> EmptyList;
	
	std::list<Character> EnemyList;
	std::list<ActionZone*> TriggerList;
	FightZone killzone (EnemyList, sf::FloatRect(400,0,500,500));
	ActionZone* fuckptr = &killzone;
	
	TriggerList.push_back(fuckptr);

	Character GrainMan (300, 100,  30, Wheat, "GrainMan", ".", true, Wheat);
	EnemyList.push_back(GrainMan);
	
	MapSection StartZone ("Mountains.jpg", StartingZoneExits, ObjList, TriggerList);
	MapSection NextZone ("cute_image.jpg", NextZoneExits, EmptyList, TriggerList);
	
	ToNextPtr = &NextZone;
	ToStartPtr = &StartZone;
	
	//All things Battlemode-
	//load everything here
	sf::Texture texture1;
	texture1.loadFromFile("BasicIdle.png");
	sf::Texture placeholder;
	placeholder.loadFromFile("BadAttackAnimation.png");
	sf::Texture getHit;
	getHit.loadFromFile("GetHitAnimation.png");
	
	
	Ability ability1 ("BigPunch", "Makes a big punch", 100, false, false, placeholder);
	ability1.setReq(Ability::ManaCost, 50);
	
	Ability ability2 ("SmallPunch", "Makes a smaller punch" , 50, false, false, placeholder);
	ability2.setReq(Ability::ManaCost, 50);
	
	Ability ability3 ("HealingPunch", "Heals for 200HP", 0, false, true, placeholder);
	ability3.setProperties(Ability::Heal, 200);
	ability3.setReq(Ability::ManaCost, 100);
	
	Ability ability4 ("ToxicPunch", "25 damage, \n50 poison", 25, false, false, placeholder);
	ability4.setProperties(Ability::Poison, 50);
	ability4.setReq(Ability::ManaCost, 100);
	
	Ability ability5 ("StunPunch", "Stuns, costs 50 health and mana", 0, false, false, placeholder);
	ability5.setProperties(Ability::Stun, 0);
	ability5.setReq(Ability::HealthCost, 50);
	ability5.setReq(Ability::ManaCost, 50);
	
	Ability ability6 ("ToxicityCheck", "2X damage on poisoned\ntargets", 80, false, false, placeholder);
	ability6.setMultiplier(Ability::WhilePoisoned, 1.0);
	ability6.setReq(Ability::ManaCost, 60);
	
	Ability ability7 ("DeathPunch", "adds a deathmark", 0, false, false, placeholder);
	ability7.setProperties(Ability::DeathMark, 0);
	ability7.setReq(Ability::ManaCost, 50);
	
	Ability ability8 ("VampPunch", "does dmg, steals life", 100, false, false, placeholder);
	ability8.setAfterEffects(Ability::LifeDrain, 0.2f);
	ability8.setReq(Ability::ManaCost, 50);
	
	Ability ability9 ("ManaPunch", "Fucks the big dog", 50, false, false, placeholder);
	ability9.setAfterEffects(Ability::ManaDrain, 1.0f);
	ability9.setReq(Ability::ManaCost, 50);
	
	Ability ability10 ("ShieldPunch", "Do 50 Dmg, gain 75%\ndamage reduction", 50, false, false, placeholder);
	ability10.setReq(Ability::ManaCost, 50);
	ability10.setProperties(Ability::SelfShieldPercent, 0.75);
	
	Ability ability11 ("BleedPunch", "Do 70 dmg,\n apply 10 bleed,\nget 50% DR", 70, false, false, placeholder);
	ability11.setReq(Ability::ManaCost, 50);
	ability11.setProperties(Ability::SelfShieldPercent, 0.50);
	ability11.setProperties(Ability::Bleed, 10);
	
	Ability ability12 ("BloodForBlood", "50 health cost,\n30 bleed\n80% DR", 0, false, false, placeholder);
	ability12.setReq(Ability::HealthCost, 50);
	ability12.setProperties(Ability::SelfShieldPercent, 0.80);
	ability12.setProperties(Ability::Bleed, 30);
	
	Ability ability13 ("HellBuff", "apply 30 bleed,\n+30 dmg\n50% DR", 0, false, true, placeholder);
	ability13.setReq(Ability::ManaCost, 30);
	ability13.setProperties(Ability::Bleed, 30);
	ability13.setProperties(Ability::SelfShieldPercent, 0.50);
	ability13.setProperties(Ability::FlatDmgBuff, 30);
	
	Ability ability14 ("PoisonHeal", "Heals 100 HP if target\nis poisoned\ncures all poison", 50, 0, 0, placeholder);
	ability14.setReq(Ability::ManaCost, 50);
	ability14.setProperties(Ability::PoisonHeal, 100);
	ability14.setProperties(Ability::AntidotePercent, 1.0f);
	
	Ability ability15 ("Expunge", "Does 30 dmg\n6X dmg against poisoned\nthen removes poison", 30, 0, 0, placeholder);
	ability15.setReq(Ability::ManaCost, 100);
	ability15.setProperties(Ability::AntidotePercent, 1.0f);
	ability15.setMultiplier(Ability::WhilePoisoned, 5.0f);
	
	Ability ability16 ("Execute", "Does 50 damage,\n%4X dmg on undamaged targets", 50, 0, 0, placeholder);
	ability16.setReq(Ability::ManaCost, 40);
	ability16.setMultiplier(Ability::VSFullHealth, 3.0f);
	
	Ability ability17 ("SpiritGraft", "Transfers 100 mana\nto another character.\nBut it hurts!", 0, false, true, placeholder);
	ability17.setReq(Ability::ManaCost, 100);
	ability17.setReq(Ability::HealthCost, 75);
	ability17.setProperties(Ability::GiveMana, 100);
	
	Ability ability18 ("Enervate", "Heals 50,\nbut stuns self", 0, false, true, placeholder);
	ability18.setReq(Ability::Requirements::ManaCost, 50);
	ability18.setProperties(Ability::Properties::Heal, 50);
	ability18.setProperties(Ability::Properties::SelfStun, 1);
	
	Ability ability19 ("Nullify", "Removes all status conditions,\ngood or bad", 0, false, true, placeholder);
	ability19.setReq(Ability::Requirements::ManaCost, 30);
	ability19.setProperties(Ability::Properties::Clear, 0);
	
	
	Character CHINGUS (400, 250, 50, texture1, "Chingus", "SMASH", false, getHit);
	CHINGUS.addAbility(ability10);
	CHINGUS.addAbility(ability11);
	CHINGUS.addAbility(ability12);
	CHINGUS.addAbility(ability13);
	
	Character DINGUS (300, 350, 50, texture1, "Dingus", "BASH", false, getHit);
	DINGUS.addAbility(ability14);
	DINGUS.addAbility(ability4);
	DINGUS.addAbility(ability6);
	DINGUS.addAbility(ability15);
	
	Character PRINGUS (500, 450, 75, texture1, "Pringus", "CLASH", false, getHit);
	PRINGUS._recoveryAbility.setProperties(Ability::Heal, 100);
	PRINGUS.addAbility(ability16);
	PRINGUS.addAbility(ability17);
	PRINGUS.addAbility(ability18);
	PRINGUS.addAbility(ability19);
	
	//create the list of characters
	std::list<Character*> _characterlist;
	
	_characterlist.push_back(&CHINGUS);				//used to be emplace
	_characterlist.push_back(&DINGUS);				//used to be emplace
	_characterlist.push_back(&PRINGUS);				//used to be emplace
	
	sf::Texture dummyTexture;
	dummyTexture.loadFromFile("BasicIdle.png");
	Character EnemyDummy (3000, 100,  30, dummyTexture, "Big one", ".", true, getHit);
	EnemyDummy.addAbility(ability1);
	EnemyDummy.addAbility(ability2);
	//_characterlist.push_back(&EnemyDummy);				//used to be emplace
	//EnemyDummy._name.setString("Enemy 2");
	//_characterlist.push_back(&EnemyDummy);				//used to be emplace
	//EnemyDummy._name.setString("Enemy 3");
	//EnemyDummy._currentMana = 0;
	//_characterlist.push_back(&EnemyDummy);				//used to be emplace
	
	
	OverworldMode overworld (&StartZone);
	while (mainWindow.isOpen())
	{
		overworld.update(gameTimer, mainWindow);
	}
}*/




















































