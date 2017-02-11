//
//  Trigger.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "Trigger.h"


Trigger::Trigger(sf::IntRect box, std::vector<Character> enemies)
: area(box), type(DataType::Fight), data(enemies)
{
    //don't think I need this because data is alrady initialzed with enemies above ^
    //data.enemyVec = enemies;
}

Trigger::Trigger(sf::IntRect box, DNode* text)
: area(box), type(DataType::Talk), data(text)
{
    
}

DataType Trigger::getDataType() const {
    return type;
}

//TriggerData Trigger::getData() const {
//    return data;
//}

bool Trigger::intersects(sf::IntRect box) const
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

