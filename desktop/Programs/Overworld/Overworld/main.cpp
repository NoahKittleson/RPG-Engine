
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

int main(int, char const**)
{
    Game::run();
    return EXIT_SUCCESS;
}







//things to fix:
//  -BattleMode disabled

//  -ResourceHolder needs to be loaded and used (especially in game.cpp)
//  -Make a loadState
//  -DialogueMode SkipText doesn't work
//  -Recoveries don't work
//  -BattleAnimation suspended
//  -AI suspended
//  -CONSIDER a stateStack approach for battleMode
//  -BattleMode doens't load player party

//  -add sound



//Done:
//  -ZoneExit pointers done as well as they can be for now...
//  -MapSections no longer copy unnecessarily
//  -ZoneExits fixed
//  -DialogueMode implemented, broken, and fixed
//  -implement drawing of characters with playerSprite included.
//  -classic dialogue boxes and scrolling


//what if Menus were template objects that I instantiated each time and the set of options...?
//Would I then be able to template okay?