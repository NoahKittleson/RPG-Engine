//
//  AudioHandler.cpp
//  Overworld
//
//  Created by Noah Kittleson on 9/12/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "AudioHandler.hpp"

AudioHandler::AudioHandler() {
	soundFiles.add(MusicID::one, "FileName.ogg");
}

void AudioHandler::playSound(SoundID soundID) {
	sf::Sound channel;
	channel.setBuffer(soundMap[soundID]);
	channel.play();
	//how do I make these sound channels don't expire before finishing, but do expire when done?
}

void AudioHandler::playMusic(MusicID id) {
	//this might not be necessary because music is soo simple anyway, and I'm already kinda having State handle it anyway.
	
	//play(resourcePath() + musicFiles[id])
}
