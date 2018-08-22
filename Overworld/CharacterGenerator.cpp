//
//  CharacterGenerator.cpp
//  Overworld
//
//  Created by Noah Kittleson on 8/10/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "CharacterGenerator.hpp"


 CharPtr CharacterGenerator::create(const ResourceHolder& resources, Combatant::ID id)
{
	switch (id) {
		case Combatant::Logo: {
			AnimationSheet sheet (resources.getTexture(Textures::Icon));
			return CharPtr(new Character(100, 100, resources.getFont(Fonts::Bramble), "Evil Logo", true, sheet));
			break;
		}
			
		case Combatant::SittingSoldier: {
			AnimationSheet sheet (resources.getTexture(Textures::SittingSoldierBig));
			return CharPtr (new Character(100, 100, resources.getFont(Fonts::Bramble), "Sitting Soldier", true, sheet));
			break;
		}
			
		case Combatant::Wheat: {
			AnimationSheet sheet (resources.getTexture(Textures::BigWheat));
			return CharPtr(new Character(100, 100, resources.getFont(Fonts::Bramble), "Wheat Man", true, sheet));
			break;
		}

		case Combatant::Pringus: {
			AnimationSheet sheet;
			sheet.setIdle(resources.getTexture(Textures::BasicIdle));
			sheet.setDead(resources.getTexture(Textures::BasicDead));
			sheet.setGetHit(resources.getTexture(Textures::GetHitAnimation));
			sheet.setGetKilled(resources.getTexture(Textures::GetKilled));

			CharPtr Pringus = std::make_shared<Character> (500, 450, resources.getFont(Fonts::Bramble), "Pringus", false, sheet);
			Ability recovery("Recover", "Heals 100 HP", 0, false, true, resources.getTexture(Textures::BadAttackAnimation));
			recovery.addProperty(Ability::Heal, 100, false);
			Pringus->setRecoveryAbility(recovery);
			Ability ability1 ("BigPunch", "Makes a big punch", 100, false, false,
							  resources.getTexture(Textures::BadAttackAnimation));
			ability1.addReq(Ability::ManaCost, 100);
			Ability ability2 ("SmallPunch", "Makes a smaller punch" , 50, false, false,
							  resources.getTexture(Textures::BadAttackAnimation));
			ability2.addReq(Ability::ManaCost, 50);
			Pringus->addAbility(ability1);
			Pringus->addAbility(ability2);
			return Pringus;
			break;
		}
			
		case Combatant::Dingus: {
			AnimationSheet sheet;
			sheet.setIdle(resources.getTexture(Textures::BasicIdle));
			sheet.setDead(resources.getTexture(Textures::BasicDead));
			sheet.setGetHit(resources.getTexture(Textures::GetHitAnimation));
			sheet.setGetKilled(resources.getTexture(Textures::GetKilled));
			
			CharPtr Dingus = std::make_shared<Character> (300, 600, resources.getFont(Fonts::Bramble), "Dingus", false, sheet);
			Ability recovery("Recover", "Heals 200 HP", 0, false, true, resources.getTexture(Textures::BadAttackAnimation));
			recovery.addProperty(Ability::Heal, 200, false);
			Dingus->setRecoveryAbility(recovery);
			Ability ability1 ("One Punch", "OHKO", 1000, false, false,
							  resources.getTexture(Textures::BadAttackAnimation));
			ability1.addReq(Ability::ManaCost, 100);
			Ability ability2 ("Tap", "Makes a small punch" , 1, false, false,
							  resources.getTexture(Textures::BadAttackAnimation));
			ability2.addReq(Ability::ManaCost, 10);
			Dingus->addAbility(ability1);
			Dingus->addAbility(ability2);
			return Dingus;
			break;
		}
			
		default:
			std::cout << "Character ID not found.  Nothing created.\n";
			//this will not return anything, and thus cause a crash...
			break;
	}
}
