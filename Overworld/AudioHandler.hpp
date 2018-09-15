//
//  AudioHandler.hpp
//  Overworld
//
//  Created by Noah Kittleson on 9/12/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

enum SoundID {one, two, three, etc};
enum MusicID {four, five, six, whatever};

class AudioHandler
{
public:
	AudioHandler();
	
	void playSound(SoundID);
	void playMusic(MusicID id);
	
private:
	std::map<MusicID, std::string> musicFiles;
	std::map<SoundID, sf::SoundBuffer> soundMap;
	
	sf::Music currentSong;
};
