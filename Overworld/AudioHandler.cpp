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
	musicMap.insert(std::make_pair(MusicID::NiceMusic, "nice_music.ogg"));

	std::map<SoundID, std::string> soundIDs;
	soundIDs.insert(std::make_pair(SoundID::fox, "Shout8.wav"));
	soundIDs.insert(std::make_pair(SoundID::shine, "foxshine.wav"));
	soundIDs.insert(std::make_pair(SoundID::airdodge, "foxairdodge.wav"));
	
	for (auto & it : soundIDs) {
		try {
			soundMap[it.first].loadFromFile(resourcePath() + it.second);
		} catch (const std::exception& e) {
			std::cout << "Error Loading: " << e.what() <<  " for " << it.second << "\n";
		}
	}
}

void AudioHandler::playSound(SoundID soundID) {
	try {
		soundMap.at(soundID);							//see if the file even exists. If not, out_of_range exception thrown.
	} catch (const std::exception& e) {
		std::cout << "Requested sound ID not mapped to file.\n";
		return;
	}
	
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
	if (id == None) {
		currentSong.stop();
		return;
	}
	try {
		musicMap.at(id);							//see if the file even exists. If not, out_of_range exception thrown.
	} catch (const std::exception& e) {
		std::cout << "Requested music ID not mapped to file.\n";
		return;
	}
	currentSong.pause();
	currentSong.openFromFile(resourcePath() + musicMap[id]);
	currentSong.play();
}

void AudioHandler::pauseMusic() {
	currentSong.pause();
}

void AudioHandler::resumeMusic() {
	currentSong.play();
}

void AudioHandler::pauseSound() {
	//
	//stop all soundChannels....
}


bool AudioHandler::instantiated = false;
