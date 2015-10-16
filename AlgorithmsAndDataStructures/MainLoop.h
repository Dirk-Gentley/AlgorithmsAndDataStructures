//
//  game.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

#ifndef SFML_Algorithms_And_Data_Structures_h
#define SFML_Algorithms_And_Data_Structures_h

sf::Vector2i handleMouseClick(unsigned int, unsigned int, sf::RenderWindow &);

class MainLoop{
    
public:
    static void Start();
    static void ShowMenu();
    static void ShowTreesAndStructuresMenu();
    static void ShowSortingAndSearchingMenu();
    static void ShowPuzzlesAndGamesMenu();
    static void ShowSchoolOfImplementationsMenu();
    static void RunSortingDemonstration();
    static void RunSortingComparisson();
    static void RunBinaryTreeDungeon();
    static void RunStackAttack();
    static void RunConwaysGameOfLife();
    
private:
    static bool IsExiting();
    static void RunLoop();
    static void ShowSplashScreen();

    enum ProgramState { Uninitialized,
                        ShowingSplash,
                        Paused,
                        ShowingMenu,
                        ShowingTreesAndStructuresMenu,
                        ShowingSortingAndSearchingMenu,
                        ShowingPuzzlesAndGamesMenu,
                        ShowingSchoolOfImplementationsMenu,
                        RunningStacksLesson,
                        RunningStackAttack,
                        RunningSortingAndSearchingLesson,
                        RunningSortingAndSearchingDemo,
                        RunningSortingComparisson,
                        RunningSchoolOfImplementations,
                        RunningBinaryTreeDungeon,
                        RunningConwaysGameOfLife,
                        Exiting };

    static ProgramState programState;
    static sf::RenderWindow MainWindow;
    static sf::View MainView;
};

#endif
