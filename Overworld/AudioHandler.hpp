//
//  AudioHandler.hpp
//  Overworld
//
//  Created by Noah Kittleson on 9/12/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "AudioIDs.hpp"

class AudioHandler
{
public:
	AudioHandler();
	
	void playSound(SoundID id);
	void pauseSound();
	void playMusic(MusicID id);
	void pauseMusic();
	void resumeMusic();
	
private:
	std::map<MusicID, std::string> musicMap;
	std::map<SoundID, sf::SoundBuffer> soundMap;
	static bool instantiated;
	
	sf::Sound soundChannels[10];			//this is a guess, 10 may be too few, or it could be more than enough
	int currentChannel = 0;
	
	sf::Music currentSong;

};
