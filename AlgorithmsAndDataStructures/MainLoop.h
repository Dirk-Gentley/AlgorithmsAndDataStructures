//
//  game.h
//  SFML_test
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

#ifndef SFML_Algorithms_And_Data_Structures_h
#define SFML_Algorithms_And_Data_Structures_h

class MainLoop{
    
public:
    static void Start();
    // Each of the menus/sub menus will appear here
    static void ShowMenu();
    static void ShowTreesAndStructuresMenu();
    static void ShowSortingAndSearchingMenu();
    static void ShowPuzzlesAndGamesMenu();
    static void ShowSchoolOfImplementationsMenu();
    
private:
    // Safely shut down
    static bool IsExiting();
    // The main loop will itterate though the enumerated states
    static void RunLoop();
    // More a demonstration than anything else, but will most likely be kept
    static void ShowSplashScreen();

    // This list will grow as the program grows.  Running may change to
    // RunningLinkedList or RunningBinaryTree etc
    enum ProgramState { Uninitialized,
                        ShowingSplash,
                        Paused,
                        ShowingMenu,
                        ShowingTreesAndStructuresMenu,
                        ShowingSortingAndSearchingMenu,
                        ShowingPuzzlesAndGamesMenu,
                        ShowingSchoolOfImplementationsMenu,
                        RunningTreesAndStructures,
                        RunningSortingAndSearching,
                        RunningPuzzlesAndGames,
                        RunningSchoolOfImplementations,
                        Exiting };
    
    static ProgramState programState;
    // The render window will be passed to any class that needs it
    static sf::RenderWindow MainWindow;
};

#endif
