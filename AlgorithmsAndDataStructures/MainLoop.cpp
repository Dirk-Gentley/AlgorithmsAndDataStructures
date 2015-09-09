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
sf::View MainLoop::MainView;
sf::Music MainLoop::MainMusic;//openFromFile(resourcePath() + "MenuMusic.ogg");

void MainLoop::Start(void){
    MainMusic.openFromFile(resourcePath() + "MenuMusic.ogg");
    MainMusic.setLoop(true);
    MainMusic.play();
    // Should never happen
    if(programState != Uninitialized)
        return;
    // This main window will remain throughout the application
    //MainWindow.create(sf::VideoMode(1024,768,32),"Window", sf::Style::Fullscreen);
    MainWindow.create(sf::VideoMode(1024,768,32),"Professor Albertons Algorithmic Adventures", sf::Style::Titlebar);
    //MainWindow.create(sf::VideoMode(1024,768,32),"Window");
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
                ShowTreesAndStructuresMenu();
                break;
            }

            case MainLoop::RunningStacksLesson:{
                
                /*
                 
                 THIS IS WHERE TREES AND STRUCTRES HAPPENS
                 
                 */
                MainWindow.clear(sf::Color::Black);
                sf::Font font;
                if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
                    exit(1);
                }
                sf::Text LessonText("Placeholder text.  ESC to go back", font, 30);
                MainWindow.draw(LessonText);
                
                MainWindow.display();
                if(currentEvent.type == sf::Event::Closed){
                    programState = MainLoop::Exiting;
                }
                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowTreesAndStructuresMenu();
                }
                break;
            }
                
            case MainLoop::RunningStackAttack:{
                
                MainMusic.openFromFile(resourcePath() + "StackAttack.ogg");
                MainMusic.play();
                
                MainWindow.clear(sf::Color::Black);
                stackAttack(MainWindow);
                if(currentEvent.type == sf::Event::Closed){
                    programState = MainLoop::Exiting;
                }
                if(currentEvent.type == sf::Event::KeyPressed){
                    MainMusic.openFromFile(resourcePath() + "MenuMusic.ogg");
                    MainMusic.play();
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowTreesAndStructuresMenu();
                }
                break;
            }
                
            case MainLoop::RunningBinaryTreeDungeon:{
                RunBinaryTreeDungeon();
                break;
            }
                
            // Sorting and Searching
                
            case MainLoop::ShowingSortingAndSearchingMenu:{
                ShowSortingAndSearchingMenu();
                break;
            }
            case MainLoop::RunningSortingAndSearchingLesson:{
                MainWindow.clear(sf::Color(sf::Color::Black));
                
                sf::Font font;
                if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
                    exit(1);
                }
                sf::Text LessonText("Placeholder text.  ESC to go back", font, 30);
                MainWindow.draw(LessonText);
                
                MainWindow.display();

                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowSortingAndSearchingMenu();
                }
                break;
            }
                
            case MainLoop::RunningSortingAndSearchingDemo:{
                RunSortingDemonstration();
                break;
            }
                
            case MainLoop::ShowingPuzzlesAndGamesMenu:{
                ShowPuzzlesAndGamesMenu();
                break;
            }
                
            case MainLoop::RunningPuzzlesAndGames:{
                /*
                 
                 THIS IS PUZZLES AND GAMES
                 
                 */
                
                MainWindow.clear(sf::Color::Black);
                
                sf::Font font;
                if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
                    exit(1);
                }
                sf::Text LessonText("Placeholder text.  ESC to go back", font, 30);
                MainWindow.draw(LessonText);
                
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
                /*
                 
                 THIS IS WHERE SCHOOL OF IMPLEMENTATIONS
                 
                 */
    
                
                MainWindow.clear(sf::Color::Black);
                
                sf::Font font;
                if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
                    exit(1);
                }
                sf::Text LessonText("Placeholder text.  ESC to go back", font, 30);
                MainWindow.draw(LessonText);
                
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
        case SortingAndSearchingMenu::BeginLesson:
            programState = MainLoop::RunningSortingAndSearchingLesson;
            break;
        case SortingAndSearchingMenu::BeginDemo:
            programState = MainLoop::RunningSortingAndSearchingDemo;
            break;
        case SortingAndSearchingMenu::Nothing:
            // Vitally important
            ShowSortingAndSearchingMenu();
            break;
    }
}

void MainLoop::RunSortingDemonstration(){
    programState = MainLoop::RunningSortingAndSearchingLesson;
    sortingModule sort;
    sort.startModule(MainWindow, sort);
    programState = MainLoop::ShowingSortingAndSearchingMenu;
}

void MainLoop::ShowTreesAndStructuresMenu(){
    TreesAndStructuresMenu treesAndStructuresMenu;
    TreesAndStructuresMenu::TreesAndStructuresMenuResult result = treesAndStructuresMenu.Show(MainWindow);
    switch(result){
        case TreesAndStructuresMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case TreesAndStructuresMenu::BeginStacksLesson:
            programState = MainLoop::RunningStacksLesson;
            break;
        case TreesAndStructuresMenu::BeginStackAttack:
            programState = MainLoop::RunningStackAttack;
            break;
        case TreesAndStructuresMenu::BeginTreeDungeon:
            programState = MainLoop::RunningBinaryTreeDungeon;
            break;
        case TreesAndStructuresMenu::Nothing:
            // Vitally important
            ShowTreesAndStructuresMenu();
            break;
    }
}

void MainLoop::RunBinaryTreeDungeon(){
    programState = MainLoop::RunningBinaryTreeDungeon;
    beginBinaryTreeDungeon(MainWindow);
    programState = MainLoop::ShowingTreesAndStructuresMenu;
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
