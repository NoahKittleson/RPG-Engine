//
//  Trigger.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "Trigger.h"


Trigger::Trigger(sf::FloatRect box, std::vector<Character> enemies)
: area(box), type(DataType::Fight), data(enemies)
{
    data.enemyVec = enemies;
}

Trigger::Trigger(sf::FloatRect box, DNode* text)
: area(box), type(DataType::Talk), data(text)
{
    
}

bool Trigger::intersects(sf::FloatRect box) const
{
    return area.intersects(box);
}

//State* Trigger::procTrigger(sf::RenderWindow &rw) const
//{
//    switch (type) {
//        case DataType::Talk:
//            return new DialogueMode(data.conversation, rw);
//            
//        case DataType::Fight:
//            return new BattleMode(data.enemyVec);
//        
//        default:
//            return nullptr;
//    }
//}

