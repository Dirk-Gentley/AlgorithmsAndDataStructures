//
//  game.h
//  SFML_test
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

#ifndef SFML_test_game_h
#define SFML_test_game_h

class MainLoop{
    
public:
    static void Start();
    static void ShowMenu();
    static void ShowSubMenu();
    
private:
    static bool IsExiting();
    static void GameLoop();
    static void ShowSplashScreen();

    
    enum ProgramState { Uninitialized,
                        ShowingSplash,
                        Paused,
                        ShowingMenu,
                        ShowingSubMenu,
                        Running,
                        Exiting };
    
    static ProgramState programState;
    static sf::RenderWindow mainWindow;
};

#endif
