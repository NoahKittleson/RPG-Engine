//
//  TownSouth.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "TownSouth.hpp"

TownSouth::TownSouth(const ResourceHolder& resources, const std::vector<Condition>& activeConds)
: MapSection(MapID::TownSouth, NiceMusic, sf::Vector2f(475 * scale, 625 * scale)) {
	background.setTexture(resources.getTexture(Textures::TownSouth));
	background.setScale(scale, scale);
	
	//A store
	MapObject store (make_unique<GraphicsComponent>(resources.getTexture(Textures::Store1),
													sf::Vector2f (50 * scale, 183 * scale)));
	store.setScale(scale);
	store.addCollisionBox(-41 * scale, 12 * scale, 83 * scale, 13 * scale);
	addObject(store);
	
	//Buildings behind store
	MapObject backgroundBuildings (make_unique<GraphicsComponent>(resources.getTexture(Textures::BuildingOutline7),
													sf::Vector2f (49 * scale, 163 * scale)));
	backgroundBuildings.setScale(scale);
	backgroundBuildings.addCollisionBox(-50 * scale, 12 * scale, 100 * scale, 13 * scale);
	addObject(backgroundBuildings);
	
	//A Garden [formerly a smith, outline 6]
	MapObject garden (make_unique<GraphicsComponent>(resources.getTexture(Textures::Garden),
													sf::Vector2f (238 * scale, 113 * scale)));
	garden.setScale(scale);
	garden.addCollisionBox(-38 * scale, 2 * scale, 64 * scale, 14 * scale);
	addObject(garden);
	
	//A Shed
	MapObject shed (make_unique<GraphicsComponent>(resources.getTexture(Textures::Shed),
													sf::Vector2f (240 * scale, 85 * scale)));
	shed.setScale(scale);
	shed.addCollisionBox(-22 * scale, 9 * scale, 45 * scale, 12 * scale);
	addObject(shed);
	
	//A Chapel
	MapObject chapel (make_unique<GraphicsComponent>(resources.getTexture(Textures::BuildingOutline4),
													 sf::Vector2f (150 * scale, 233 * scale)));
	chapel.setScale(scale);
	chapel.addCollisionBox(-53 * scale, 20 * scale, 106 * scale, 30 * scale);
	addObject(chapel);
	
	//An Inn
	MapObject Inn (make_unique<GraphicsComponent>(resources.getTexture(Textures::BuildingOutline5),
												  sf::Vector2f (166 * scale, 83 * scale)));
	Inn.setScale(scale);
	Inn.addCollisionBox(-48 * scale, 15 * scale, 93 * scale, 30 * scale);
	Inn.addCollisionBox(-85 * scale, 35 * scale, 40 * scale, 10 * scale);
	Inn.addCollisionBox(-65 * scale, 30 * scale, 20 * scale, 5 * scale);
	addObject(Inn);
	
	//Couple outside bar (1)
	MapObject Couple1 (make_unique<GraphicsComponent>(resources.getTexture(Textures::Couple1),
													sf::Vector2f (232 * scale, 139 * scale)));
	Couple1.setScale(scale);
	Couple1.addCollisionBox(-10 * scale, 10 * scale, 20 * scale, 2 * scale);
	addObject(Couple1);
	
	//Couple outside bar (2)
	MapObject Couple2 (make_unique<AnimatedComponent>(resources.getTexture(Textures::Couple2),
													  sf::Vector2f (212 * scale, 128 * scale), 0.6, sf::Vector2i(24,25)));
	Couple2.setScale(scale);
	Couple2.addCollisionBox(-8 * scale, 11 * scale, 20 * scale, 2 * scale);
	addObject(Couple2);
	
	//Bystander by bar (1)
	auto Bystander1Sprite = make_unique<StaggeredAnimation> (resources.getTexture(Textures::Bystander1),
															 sf::Vector2f (213 * scale, 148 * scale), 0.1,
															 sf::Vector2i(24,24));
	Bystander1Sprite->changeTimePerFrameAt(3, 1);
	Bystander1Sprite->changeTimePerFrameAt(1, 6);
	
	MapObject Bystander1 (std::move(Bystander1Sprite));
	Bystander1.setScale(scale);
	Bystander1.addCollisionBox(-5 * scale, 10 * scale, 10 * scale, 2 * scale);
	addObject(Bystander1);
	
	//Bystander by bar (2)
	MapObject Bystander2 (make_unique<AnimatedComponent>(resources.getTexture(Textures::Bystander2),
														 sf::Vector2f (225 * scale, 152 * scale), 0.8, sf::Vector2i(24,24)));
	Bystander2.setScale(scale);
	Bystander2.addCollisionBox(-5 * scale, 10 * scale, 10 * scale, 2 * scale);
	addObject(Bystander2);
		
	//The Drunk
	MapObject drunk (make_unique<AnimatedComponent>(resources.getTexture(Textures::TheDrunk),
													sf::Vector2f (180 * scale, 170 * scale), 0.1, sf::Vector2i(31, 24)));
	drunk.setScale(scale);
	drunk.addCollisionBox(-4 * scale, 10 * scale, 8 * scale, 2 * scale);
	addObject(drunk);
	
//	//The Clocktower
//	MapObject clocktower (make_unique<GraphicsComponent>(resources.getTexture(Textures::Clocktower),
//														 sf::Vector2f (233 * scale, 166 * scale)));
//	clocktower.setScale(scale);
//	clocktower.addCollisionBox(-20 * scale, -50 * scale, 40 * scale, 110 * scale);
//	addObject(clocktower);
//
	//The building to the east replacing the Clocktower
	MapObject eastBuilding (make_unique<AnimatedComponent>(resources.getTexture(Textures::BuildingOutline9),
														   sf::Vector2f (240 * scale, 165 * scale), 0.1, sf::Vector2i(50,115)));
	eastBuilding.setScale(scale);
	eastBuilding.addCollisionBox(-23 * scale, 27 * scale, 40 * scale, 30 * scale);
	eastBuilding.addCollisionBox(-10 * scale, -37 * scale, 20 * scale, 65 * scale);
	addObject(eastBuilding);
	
	//The Fountain	[removed for now...]
//	MapObject fountain (make_unique<GraphicsComponent>(resources.getTexture(Textures::Fountain),
//													   sf::Vector2f (130 * scale, 160 * scale)));
//	fountain.setScale(scale);
//	fountain.addCollisionBox(-15 * scale, 10 * scale, 29 * scale, 6 * scale);
//	addObject(fountain);
	
	//The Booth
	MapObject booth (make_unique<AnimatedComponent>(resources.getTexture(Textures::BoothAnimation),
													sf::Vector2f (50 * scale, 233 * scale), 0.6, sf::Vector2i(54, 43)));
	booth.setScale(scale);
	booth.addCollisionBox(-25 * scale, 10 * scale, 54 * scale, 12 * scale);
	addObject(booth);
	
	//A Fisherman
	MapObject fisherman (make_unique<AnimatedComponent>(resources.getTexture(Textures::SittingFisherman),
														sf::Vector2f (61 * scale, 330 * scale), 0.6, sf::Vector2i(38,24)));
	fisherman.setScale(scale);
	fisherman.addCollisionBox(14 * scale, 5 * scale, 6 * scale, 4 * scale);
	fisherman.offsetBase(-10);
	addObject(fisherman);
	
	//Sitting Soldier
	auto sittingSoldierSprite = make_unique<StaggeredAnimation> (resources.getTexture(Textures::SittingSoldierAnim),
														   sf::Vector2f (120 * scale, 120 * scale), 0.1,
														   sf::Vector2i(24, 24));
	sittingSoldierSprite->changeTimePerFrameAt(0.6, 10);
	sittingSoldierSprite->changeTimePerFrameAt(2, 14);
	sittingSoldierSprite->changeTimePerFrameAt(2, 17);
	
	MapObject soldierSitting (std::move(sittingSoldierSprite));
	soldierSitting.setScale(scale);
	soldierSitting.addCollisionBox(-5 * scale, 10 * scale, 10 * scale, 2 * scale);
	addObject(soldierSitting);
	
	//Saluting Soldier
	MapObject soldierStanding (make_unique<GraphicsComponent>(resources.getTexture(Textures::SalutingSoldier),
															  sf::Vector2f (60 * scale, 270 * scale)));
	soldierStanding.setScale(scale);
	soldierStanding.addCollisionBox(-5 * scale, 10 * scale, 6 * scale, 2 * scale);
	addObject(soldierStanding);
	
	//The Colonel
	auto colonelSprite = make_unique<StaggeredAnimation> (resources.getTexture(Textures::TheColonel),
														   sf::Vector2f (224 * scale, 240 * scale), 0.15,
														   sf::Vector2i(24, 24));
	colonelSprite->changeTimePerFrameAt(0.45, 7);
	colonelSprite->changeTimePerFrameAt(0.45, 13);
	colonelSprite->changeTimePerFrameAt(0.45, 15);

	MapObject theColonel (std::move(colonelSprite));
	theColonel.setScale(scale);
	theColonel.addCollisionBox(-3 * scale, 10 * scale, 6 * scale, 2 * scale);
	addObject(theColonel);
	
	//ListeningMan
	auto listeningManSprite = make_unique<StaggeredAnimation>  (resources.getTexture(Textures::ListeningMan),
														   sf::Vector2f (208 * scale, 240 * scale), 0.1,
														   sf::Vector2i(24, 24));
	listeningManSprite->changeTimePerFrameAt(2, 1);
	listeningManSprite->changeTimePerFrameAt(1, 3);
	listeningManSprite->changeTimePerFrameAt(0.3, 7);
	listeningManSprite->changeTimePerFrameAt(0.3, 8);
	listeningManSprite->changeTimePerFrameAt(0.3, 9);
	listeningManSprite->changeTimePerFrameAt(0.3, 10);
	
	MapObject listeningMan (std::move(listeningManSprite));
	listeningMan.setScale(scale);
	listeningMan.addCollisionBox(-4 * scale, 10 * scale, 5 * scale, 2 * scale);
	addObject(listeningMan);
	
	//The Waves
	MapObject waves (make_unique<AnimatedComponent>(resources.getTexture(Textures::WavesSouth),
					sf::Vector2f (127 * scale, 288 * scale), 0.6, sf::Vector2i(85 * scale, 58 * scale)));
	waves.setScale(scale);
	//waves.addCollisionBox(-3 * scale, 10 * scale, 6 * scale, 2 * scale);
	waves.offsetBase(-300);
	addObject(waves);
	
	//The Docks
	MapObject docks (make_unique<GraphicsComponent>(resources.getTexture(Textures::Docks),
													sf::Vector2f (127 * scale, 287 * scale)));
	docks.setScale(scale);
	docks.offsetBase(-290);
	//left docks
	docks.addCollisionBox(-28 * scale, 33 * scale, 1 * scale, 51 * scale);
	docks.addCollisionBox(-53 * scale, 37 * scale, 1 * scale, 47 * scale);
	docks.addCollisionBox(-53 * scale, 84 * scale, 25 * scale, 1 * scale);
	//right docks
	docks.addCollisionBox(2 * scale, 32 * scale, 1 * scale, 51 * scale);
	docks.addCollisionBox(27 * scale, 29 * scale, 1 * scale, 53 * scale);
	docks.addCollisionBox(3 * scale, 82 * scale, 24 * scale, 1 * scale);
	addObject(docks);
	
	//water zones
	waterZones.emplace_back(sf::FloatRect(0,963,220,170));
	waterZones.emplace_back(sf::FloatRect(223,1117,77,15));
	waterZones.emplace_back(sf::FloatRect(300,960,88,170));
	waterZones.emplace_back(sf::FloatRect(386,1111,76,170));
	waterZones.emplace_back(sf::FloatRect(466,936,65,250));
	waterZones.emplace_back(sf::FloatRect(531,885,130,250));
	waterZones.emplace_back(sf::FloatRect(662,838,110,300));

	
	
	
	
	//Set up Trigger for Warning
	std::function<State*()> createDialogue = [&resources]() -> State*
	{
		auto dialogue = DialogueFactory::create(Dialogue::GuardStop1, resources);
		return new DialogueMode(dialogue);
	};
	
	ConditionMap prereqs;
	triggers.emplace_back(prereqs, createDialogue, sf::FloatRect(243,380,20,110));
	
	//Set up Trigger for Second Warning
	std::function<State*()> warning = [&resources]() -> State*
	{
		auto dialogue = DialogueFactory::create(Dialogue::GuardStop2, resources);
		return new DialogueMode(dialogue);
	};
	
	triggers.emplace_back(prereqs, warning, sf::FloatRect(263,380,20,110));
	
	//Set up Trigger for Intro text
	if (std::find(activeConds.begin(), activeConds.end(), Condition::ControlsExplained) == activeConds.end()) {
		std::function<State*()> intro = [&resources]() -> State*
		{
			auto dialogue = DialogueFactory::create(Dialogue::Intro01, resources);
			return new DialogueMode(dialogue);
		};
		
		triggers.emplace_back(prereqs, intro, sf::FloatRect(50,50,50,50));
		
		std::function<State*()> SecondIntro = [&resources]() -> State*
		{
			auto dialogue = DialogueFactory::create(Dialogue::Intro02, resources);
			return new DialogueMode(dialogue);
		};
		
		triggers.emplace_back(prereqs, SecondIntro, sf::FloatRect(100,100,50,100));
	}
	
	//Set up Trigger for Fighting
	std::function<State*()> createBattle = [&resources]() -> State*
	{
		std::vector<std::shared_ptr<Character>> enemyVec;
		enemyVec.emplace_back(CharacterGenerator::create(resources, Combatant::SittingSoldier));
		return new BattleState(enemyVec);
	};
	triggers.emplace_back(prereqs, createBattle, sf::FloatRect(283,380,20,110));
	triggers.back().setEffect(GroundTrigger::blink);
	
	
	//Set up Zone Exits
	sf::Vector2u totalArea = background.getTexture()->getSize();
	totalArea = sf::Vector2u(totalArea.x * scale, totalArea.y * scale);
	
	exits.emplace_back(sf::FloatRect(0, -100, totalArea.x, 100),
					   sf::Vector2f(0, -mapClearance), MapID::Forest);				//entire top
	exits.emplace_back(sf::FloatRect(-100, 0, 100, 125 * scale),
					   sf::Vector2f(-mapClearance, 0), MapID::SouthOfStart);		//top left
	exits.emplace_back(sf::FloatRect(-100, 125 * scale, 100, 250 * scale),
					   sf::Vector2f(-mapClearance, 0), MapID::BeachSouth);			//top left
	exits.emplace_back(sf::FloatRect(totalArea.x, 0, 100, 95 * scale),
					   sf::Vector2f(mapClearance, 0), MapID::Swamp);				//top right
	exits.emplace_back(sf::FloatRect(totalArea.x, 95 * scale, 100, 280 * scale),
					   sf::Vector2f(mapClearance, 0), MapID::LighthouseCoast);		//bottom right

	
	
	
}
