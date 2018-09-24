//
//  AudioHandler.cpp
//  Overworld
//
//  Created by Noah Kittleson on 9/12/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "AudioHandler.hpp"
#include "ResourcePath.hpp"

AudioHandler::AudioHandler() {
	assert(!instantiated);
	instantiated = true;
	
	//this would be where I would initialize the lists of all the music and sounds like I do in ResourceHolder
	musicFiles.insert(std::make_pair(MusicID::four, "nice_music.ogg"));

	std::map<SoundID, std::string> soundIDs;
	soundIDs.insert(std::make_pair(SoundID::one, "Shout8.wav"));
	
	for (auto & it : soundIDs) {
		try {
			soundMap[it.first].loadFromFile(resourcePath() + it.second);
		} catch (const std::exception& e) {
			std::cout << "Error Loading: " << e.what() << "\n";
		}
	}
}

void AudioHandler::playSound(SoundID soundID) {
	//This system uses 10 sound channels that can play simultaneously, if an 11th is played, it will overwrite the first.
	sf::Sound* channel = &soundChannels[currentChannel];
	channel->setBuffer(soundMap[soundID]);
	channel->play();
	++currentChannel;
	if (currentChannel >= 10) {
		currentChannel = 0;
	}
}

void AudioHandler::playMusic(MusicID id) {
	//this might not be necessary because music is soo simple anyway, and I'm already kinda having State handle it anyway.
	currentSong.pause();
	currentSong.openFromFile(resourcePath() + musicFiles[id]);
	currentSong.play();
}
