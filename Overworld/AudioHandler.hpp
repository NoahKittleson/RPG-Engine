//
//  AudioHandler.hpp
//  Overworld
//
//  Created by Noah Kittleson on 9/12/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

//these IDs may need to be in a separate folder down the line
enum SoundID {one, two, three, etc};
enum MusicID {four, five, six, whatever};

class AudioHandler
{
public:
	AudioHandler();
	
	void playSound(SoundID id);
	void playMusic(MusicID id);
	
private:
	std::map<MusicID, std::string> musicFiles;
	std::map<SoundID, sf::SoundBuffer> soundMap;
	
	sf::Sound soundChannels[10];			//this is a guess, 10 may be too few, or it could be more than enough
	int currentChannel = 0;
	
	sf::Music currentSong;
};
