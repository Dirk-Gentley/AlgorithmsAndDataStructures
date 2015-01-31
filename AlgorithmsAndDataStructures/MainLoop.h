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
    // The applications themselves.  Start() will eventually become
    // StartLinkedList, StartBinaryTree() and so on
    static void Start();
    // Each of the menus/sub menus will appear here
    static void ShowMenu();
    static void ShowSubMenu();
    
private:
    // Safely shut down
    static bool IsExiting();
    // The main loop will itterate though the enumerated states hence
    // being a state driven system
    static void RunLoop();
    // More a demonstration than anything else, but will most likely be kept
    static void ShowSplashScreen();

    // This list will grow as the program grows.  Running may change to
    // RunningLinkedList or RunningBinaryTree etc
    enum ProgramState { Uninitialized,
                        ShowingSplash,
                        Paused,
                        ShowingMenu,
                        ShowingSubMenu,
                        Running,
                        Exiting };
    
    static ProgramState programState;
    // The render window will be passed to any class that needs it
    static sf::RenderWindow mainWindow;
};

#endif
