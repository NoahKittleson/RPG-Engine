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
	virtual void update(float elapsed, State* context) override;
	virtual void draw(sf::RenderWindow &rw) override;
	virtual void handleInput(sf::RenderWindow &rw) override;
	
private:
	BattleInfo& info;
	std::map<std::shared_ptr<Character>, sf::Vector2f> originalPosMap;
	std::map<std::shared_ptr<Character>, sf::Vector2f> destinationMap;
	
	enum phase {moveTo, applyDamage, animate, moveBack};
	phase currentPhase = moveTo;
	
	void moveToUpdate(float elapsed);
	void animateUpdate(float elapsed);
	void moveBackUpdate(float elapsed);

};
