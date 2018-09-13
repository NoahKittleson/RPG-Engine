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
	void playSound(SoundID);
	void playMusic(MusicID);
	
private:
	std::vector<std::string> musicFiles;
	std::vector<sf::SoundBuffer> sounds;
};
