//
//  AttackMode.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "Mode.hpp"
#include "BattleInfo.hpp"

class AttackMode : public Mode
{
public:
	AttackMode(BattleInfo& info);
	virtual void update(float elapsed) override;
	virtual void draw(sf::RenderWindow &rw) override;
	virtual void handleInput(sf::RenderWindow &rw) override;
	
private:
	BattleInfo& info;
	std::map<std::shared_ptr<Character>, sf::Vector2f> originalPosMap;
	std::map<std::shared_ptr<Character>, sf::Vector2f> destinationMap;
};
