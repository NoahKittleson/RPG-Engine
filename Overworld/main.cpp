
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include "Game.h"

class item {
public:
	item(int x) {
		fuck = x;
	}
	virtual void say() {
		std::cout << fuck;
	}
private:
	int fuck;
};

class test : public item {
public:
	test(int x, int y) : item(x) {
		shit = y;
	}
	void say() override {
		std::cout << shit;
		}
	private:
		int shit;
		};

int main(int, char const**)
{
    Game::run();
	item x (1);
	test y (1, 2);
	item* itemPtr = &x;
	item* testPtr = &y;
	itemPtr->say();
	itemPtr->say();
	
    return EXIT_SUCCESS;
}




//things to fix:
//  -BattleMode disabled
//  -ResourceHolder needs to be loaded and used (especially in game.cpp)
//  -Make a loadState
//  -Recoveries don't work
//  -BattleAnimation suspended
//  -AI suspended
//  -CONSIDER a stateStack approach for battleMode
//  -BattleMode doens't load player party

//  -add sound



//Done:
//  -DialogueMode SkipText works
//  -ZoneExit pointers done as well as they can be for now...
//  -MapSections no longer copy unnecessarily
//  -ZoneExits fixed
//  -DialogueMode implemented, broken, and fixed
//  -implement drawing of characters with playerSprite included.
//  -classic dialogue boxes and scrolling


//what if Menus were template objects that I instantiated each time and the set of options...?
//Would I then be able to template okay?





