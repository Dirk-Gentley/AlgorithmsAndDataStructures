//
//  game.cpp
//  SFML_test
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

MainLoop::ProgramState MainLoop::programState = Uninitialized;
sf::RenderWindow MainLoop::MainWindow;

void MainLoop::Start(void){
    // Should never happen
    if(programState != Uninitialized)
        return;
    // This main window will remain throughout the application
    MainWindow.create(sf::VideoMode(1024,768,32),"Window");
    // The initial program state, should only happen once
    programState = MainLoop::ShowingSplash;
    
    // Enter the main program loop
    while(!IsExiting()){
        RunLoop();
    }
    MainWindow.close();
}

bool MainLoop::IsExiting(){
    if(programState == MainLoop::Exiting)
        return true;
    else
        return false;
}

/*
 
 THIS IS THE MAIN PROGRAM LOOP
 
 This switch() statement will grow as the application grows.
 The program states will appear here as enumerated types, or "states",
 hence state driven design.
 
 PLEASE KEEP THE SWITCH STATEMENT NEAT AND TIDY
 
 Everything that happens goes here
 
 */

void MainLoop::RunLoop(){
    sf::Event currentEvent;
    while(MainWindow.pollEvent(currentEvent)){

        switch(programState){
                
            case MainLoop::Uninitialized:{
                break;
            }

            case MainLoop::ShowingSplash:{
                ShowSplashScreen();
                break;
            }
                
            case MainLoop::ShowingMenu:{
                ShowMenu();
                break;
            }
                
            // Trees and Data Structures
                
            case MainLoop::ShowingTreesAndStructuresMenu:{
                std::cout << "Trees" << std::endl;
                ShowTreesAndStructuresMenu();
                break;
            }

            case MainLoop::RunningTreesAndStructures:{
                MainWindow.clear(sf::Color(255,127,0));
                MainWindow.display();
                if(currentEvent.type == sf::Event::Closed){
                    programState = MainLoop::Exiting;
                }
                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowTreesAndStructuresMenu();
                }
                break;
            }
                
            // Sorting and Searching
                
            case MainLoop::ShowingSortingAndSearchingMenu:{
                std::cout << "Sorting" << std::endl;
                ShowSortingAndSearchingMenu();
                break;
            }
                
            case MainLoop::RunningSortingAndSearching:{
                MainWindow.clear(sf::Color(127,127,0));
                MainWindow.display();
                if(currentEvent.type == sf::Event::Closed){
                    programState = MainLoop::Exiting;
                }
                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowSortingAndSearchingMenu();
                }
                break;
            }
                
            // Puzzles and Games
                
            case MainLoop::ShowingPuzzlesAndGamesMenu:{
                ShowPuzzlesAndGamesMenu();
                break;
            }
                
            case MainLoop::RunningPuzzlesAndGames:{
                MainWindow.clear(sf::Color(255,127,0));
                MainWindow.display();
                if(currentEvent.type == sf::Event::Closed){
                    programState = MainLoop::Exiting;
                }
                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowPuzzlesAndGamesMenu();
                }
                break;
            }
                
            // School of Implementations
                
            case MainLoop::ShowingSchoolOfImplementationsMenu:{
                ShowSchoolOfImplementationsMenu();
                break;
            }
                
            case MainLoop::RunningSchoolOfImplementations:{
                MainWindow.clear(sf::Color(255,127,0));
                MainWindow.display();
                if(currentEvent.type == sf::Event::Closed){
                    programState = MainLoop::Exiting;
                }
                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowSchoolOfImplementationsMenu();
                }
                break;
            }
                
            case MainLoop::Paused:{
                break;
            }

            case MainLoop::Exiting:{
                // Exit safely.  Free resources here
                exit(0);
                break;
            }
        }
    }
}

void MainLoop::ShowSplashScreen(){
	SplashScreen splashScreen;
	splashScreen.Show(MainWindow);
	programState = MainLoop::ShowingMenu;
}

/*
 
 THE MENUS AND SUB MENUS APPEAR HERE
 
 Each has their own .cpp and .h file in order that they can be dynamic
 and themed.
 
 NO GENERIC BUILD MENU CLASS
 
 It is important that the project remain as collaborative and modular as possible,
 this way it is far easier to combine other, smaller applications into this one
 
*/

void MainLoop::ShowMenu(){
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(MainWindow);
	switch(result){
        case MainMenu::Exit:
			programState = MainLoop::Exiting;
			break;
        case MainMenu::SortingAndSearchingMenu:
            programState = MainLoop::ShowingSortingAndSearchingMenu;
            break;
        case MainMenu::TreesAndStructuresMenu:
            programState = MainLoop::ShowingTreesAndStructuresMenu;
            break;
        case MainMenu::PuzzlesAndGamesMenu:
            programState = MainLoop::ShowingPuzzlesAndGamesMenu;
            break;
        case MainMenu::SchoolOfImplementationsMenu:
            programState = MainLoop::ShowingSchoolOfImplementationsMenu;
            break;
        case MainMenu::Nothing:
            // Vitally important
            ShowMenu();
            break;
	}
}

void MainLoop::ShowSortingAndSearchingMenu(){
    SortingAndSearchingMenu sortingAndSearchingMenu;
    SortingAndSearchingMenu::SortingAndSearchingMenuResult result = sortingAndSearchingMenu.Show(MainWindow);
    switch(result){
        case SortingAndSearchingMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case SortingAndSearchingMenu::Begin:
            programState = MainLoop::RunningSortingAndSearching;
            break;
        case SortingAndSearchingMenu::Nothing:
            // Vitally important
            ShowSortingAndSearchingMenu();
            break;
    }
}

void MainLoop::ShowTreesAndStructuresMenu(){
    TreesAndStructuresMenu treesAndStructuresMenu;
    TreesAndStructuresMenu::TreesAndStructuresMenuResult result = treesAndStructuresMenu.Show(MainWindow);
    switch(result){
        case TreesAndStructuresMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case TreesAndStructuresMenu::Begin:
            programState = MainLoop::RunningTreesAndStructures;
            break;
        case TreesAndStructuresMenu::Nothing:
            // Vitally important
            ShowTreesAndStructuresMenu();
            break;
    }
}

void MainLoop::ShowPuzzlesAndGamesMenu(){
    PuzzlesAndGamesMenu puzzlesAndGamesMenu;
    PuzzlesAndGamesMenu::PuzzlesAndGamesMenuResult result = puzzlesAndGamesMenu.Show(MainWindow);
    switch(result){
        case PuzzlesAndGamesMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case PuzzlesAndGamesMenu::Begin:
            programState = MainLoop::RunningPuzzlesAndGames;
            break;
        case PuzzlesAndGamesMenu::Nothing:
            // Vitally important
            ShowPuzzlesAndGamesMenu();
            break;
    }
}

void MainLoop::ShowSchoolOfImplementationsMenu(){
    SchoolOfImplementationsMenu schoolOfImplementationsMenu;
    SchoolOfImplementationsMenu::SchoolOfImplementationsMenuResult result = schoolOfImplementationsMenu.Show(MainWindow);
    switch(result){
        case SchoolOfImplementationsMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case SchoolOfImplementationsMenu::Begin:
            programState = MainLoop::RunningSchoolOfImplementations;
            break;
        case SchoolOfImplementationsMenu::Nothing:
            // Vitally important
            SchoolOfImplementationsMenu();
            break;
    }
}

