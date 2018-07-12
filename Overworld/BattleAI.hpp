//
//  BattleAI.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/11/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "BattleInfo.hpp"

class BattleAI {
public:
	virtual void FillAction(BattleInfo& info) = 0;
};

class OpportunisticAI : BattleAI {
	void FillAction(BattleInfo& info) override;
};

class RandomAI : BattleAI {
	void FillAction(BattleInfo& info) override;
};



