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
	
	while (inputFile.read((char*)&tileType, sizeof(int)))
	{
		TileType tileType;
		inputFile.read((char*)&tileType, sizeof(int));
		//I'm going to have to do this way differently since there are so many conditions
		switch(tileType)
		{
			default:
			case TileType::VOID:
			case TileType::GRASS:
				this->tiles.push_back(tileAtlas.at("grass"));
				break;
			case TileType::FOREST:
				this->tiles.push_back(tileAtlas.at("forest"));
				break;
			case TileType::WATER:
				this->tiles.push_back(tileAtlas.at("water"));
				break;
			case TileType::RESIDENTIAL:
				this->tiles.push_back(tileAtlas.at("residential"));
				break;
			case TileType::COMMERCIAL:
				this->tiles.push_back(tileAtlas.at("commercial"));
				break;
			case TileType::INDUSTRIAL:
				this->tiles.push_back(tileAtlas.at("industrial"));
				break;
			case TileType::ROAD:
				this->tiles.push_back(tileAtlas.at("road"));
				break;
		}
		Tile& tile = this->tiles.back();
		inputFile.read((char*)&tile.tileVariant, sizeof(int));
		inputFile.read((char*)&tile.regions, sizeof(int)*1);
		inputFile.read((char*)&tile.population, sizeof(double));
		inputFile.read((char*)&tile.storedGoods, sizeof(float));
	}
	
	inputFile.close();
	
	return;
}


//this is not where save should be, but I'm putting it here for now, so that I can refer to it
void LoadState::save(const std::string& filename)
{
	std::ofstream outputFile;
	outputFile.open(filename, std::ios::out | std::ios::binary);
	
	for(auto condition : this->conditions)
	{
		outputFile.write((char*)&tile.tileType, sizeof(int));
		outputFile.write((char*)&tile.tileVariant, sizeof(int));
		outputFile.write((char*)&tile.regions, sizeof(int)*1);
		outputFile.write((char*)&tile.population, sizeof(double));
		outputFile.write((char*)&tile.storedGoods, sizeof(float));
	}
	
	outputFile.close();
	
	return;
}

