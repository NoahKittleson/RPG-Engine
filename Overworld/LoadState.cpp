//
//  LoadState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/12/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "LoadState.hpp"

LoadState::LoadState(StateStack& States) {
	stack = &States;
	//load stuff for loading bar, loading text, etc...
}

void LoadState::handleInput(sf::RenderWindow& rw) {
    return;
}

void LoadState::update(sf::Clock&) {
    //nothing yet... eventually loading bar?
}

void LoadState::draw(sf::RenderWindow& rw) {
    rw.clear(sf::Color::Black);
	rw.display();
    //nothing yet... eventually loading bar?
}

void LoadState::load() {
	//load conditions into ConditionList
	//(not yet)
	currentMap = MapFactory::create(MapID::TownSouth, resources, conditions);
	
	//set up party
	party.push_back(CharacterGenerator::create(resources, Combatant::Pringus));
	party.push_back(CharacterGenerator::create(resources, Combatant::Dingus));
	
	//set up player sprite
	player = make_unique<PlayerObject>(graphicsPtr(new WalkingAnimation(resources.getTexture(Textures::PlayerWalkingUp2),
																		resources.getTexture(Textures::PlayerWalkingDown2),
																		resources.getTexture(Textures::PlayerWalkingLeft2),
																		resources.getTexture(Textures::PlayerWalkingRight2),
																		sf::Vector2f(50,50), 0.1f, sf::Vector2i(24,24))));
	player->addCollisionBox(-10,30,20,6);
	player->attachAudio(audioPlayer);
	
	//	player = make_unique<PlayerObject>(graphicsPtr(new WalkingAnimation(resources.getTexture(Textures::PlayerWalkingUp),
	//												resources.getTexture(Textures::PlayerWalkingDown),
	//												resources.getTexture(Textures::PlayerWalkingLeft),
	//												resources.getTexture(Textures::PlayerWalkingRight),
	//												sf::Vector2f(50,50), 0.1f, sf::Vector2i(16,16))), collisionList);
	//	player->addCollisionBox(-10,20,20,5);
	

}

void LoadState::loadFromDisc(std::string filename, std::map<std::string, Condition>& conditionAtlas) {
	std::ifstream inputFile;
	inputFile.open(filename, std::ios::in | std::ios::binary);
	
	if (!inputFile) {
		// get length of file:
		std::cout << "file could not be read.\n";
		return;
//		inputFile.seekg(0, inputFile.end);
//		int length = inputFile.tellg();
//		inputFile.seekg(0, inputFile.beg);
	}
	
	Condition conditionType;
	while (inputFile.read((char*)&conditionType, sizeof(int))) {
		//prolly won't work but worth a try.
		//inputFile.read((char*)&conditionType, sizeof(int));
		conditions.push_back(conditionType);
	}
	inputFile.close();
}


//this is not where save should be, but I'm putting it here for now, so that I can refer to it
void LoadState::save(const std::string& filename) {
	//open file and deal with errors if cannot
	std::ofstream outputFile;
	outputFile.open(filename, std::ios::out | std::ios::binary);
	if (!outputFile) {
		std::cout << "file could not be opened.\n";
		return;
	}
	
	//write current position and which map you're on
//	sf::Vector2f position = player->getPosition();
//	outputFile.write((char*)&position.x, sizeof(float));
//	outputFile.write((char*)&position.y, sizeof(float));
//	outputFile.write((char*)currentMap->ID, sizeof(int));
	
	//write all current conditions
	for(auto condition : this->conditions) {
		outputFile.write((char*)condition, sizeof(int));
	}
	
	outputFile.close();
}

