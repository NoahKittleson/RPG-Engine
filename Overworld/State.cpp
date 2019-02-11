//
//  StateStack.cpp
//  Overworld
//
//  Created by Noah Kittleson on 11/20/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "State.h"


State::~State()
{
}

void State::requestStackAdd(std::unique_ptr<State>&& add)
{
	stack->requestAdd(std::move(add));
}

void State::requestStackPop()
{
	stack->requestPop();
}

void State::requestStateClear()
{
	stack->requestClear();
}


void State::loadFromDisc(std::string filename) {
	std::ifstream inputFile;
	inputFile.open(filename, std::ios::in | std::ios::binary);
	
	if (!inputFile) {
		std::cout << "file could not be read.\n";
		return;
	}
	
	sf::Vector2f position (0,0);
	inputFile.read((char*)&position.x, sizeof(float));
	inputFile.read((char*)&position.y, sizeof(float));
	player->setPosition(position.x, position.y);

	
	Condition conditionType;
	while (inputFile.read((char*)&conditionType, sizeof(int))) {
		//maybe won't work but worth a try.
		conditions.push_back(conditionType);
	}
	inputFile.close();
	std::cout << "Load completed successfully.\n";
}


//this is not where save should be, but I'm putting it here for now, so that I can refer to it
void State::save(const std::string& filename) {
	//open file and deal with errors if cannot
	std::ofstream outputFile;
	outputFile.open(filename, std::ios::out | std::ios::binary);
	if (!outputFile) {
		std::cout << "file could not be opened.\n";
		return;
	}
	
	//write current position and which map you're on
	sf::Vector2f position = player->getPosition();
	outputFile.write((char*)&position.x, sizeof(float));
	outputFile.write((char*)&position.y, sizeof(float));
	//	outputFile.write((char*)currentMap->ID, sizeof(int));
	
	//write all current conditions
	for(auto condition : this->conditions) {
		outputFile.write((char*)condition, sizeof(int));
	}
	
	outputFile.close();
	std::cout << "Save completed successfully.\n";
}



const ResourceHolder State::resources;
StateStack* State::stack;
std::unique_ptr<MapSection> State::currentMap;
std::vector<std::shared_ptr<Character>> State::party;
std::unique_ptr<PlayerObject> State::player;
std::vector<Condition> State::conditions;
AudioHandler State::audioPlayer;

