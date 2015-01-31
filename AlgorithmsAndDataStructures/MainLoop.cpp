//
//  game.cpp
//  SFML_test
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

void MainLoop::Start(void){
    // Should never happen
    if(programState != Uninitialized)
        return;
    // This main window will remain throughout the application
    mainWindow.create(sf::VideoMode(1024,768,32),"Window");
    // The initial program state, should only happen once
    programState = MainLoop::ShowingSplash;
    
    // Enter the main program loop
    while(!IsExiting()){
        RunLoop();
    }
    mainWindow.close();
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
    while(mainWindow.pollEvent(currentEvent)){

        switch(programState){
            // LinkedListRunning etc
            case MainLoop::Running:{
                mainWindow.clear(sf::Color(255,127,0));
                mainWindow.display();

                // Needs to stay in order to maintain regular window function i.e. close
                if(currentEvent.type == sf::Event::Closed){
                    programState = MainLoop::Exiting;
                }
                // Could potentially move to action handler.  Preferential
                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowMenu();
                }
                break;
            }

            case MainLoop::ShowingSplash:{
                ShowSplashScreen();
                break;
            }

            case MainLoop::Uninitialized:{
                break;
            }

            case MainLoop::Paused:{
                break;
            }

            case MainLoop::ShowingMenu:{
                ShowMenu();
                break;
            }
                
            case MainLoop::ShowingSubMenu:{
                ShowSubMenu();
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

MainLoop::ProgramState MainLoop::programState = Uninitialized;
sf::RenderWindow MainLoop::mainWindow;

void MainLoop::ShowSplashScreen(){
	SplashScreen splashScreen;
	splashScreen.Show(mainWindow);
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
	MainMenu::MenuResult result = mainMenu.Show(mainWindow);
	switch(result){
        case MainMenu::Exit:
			programState = MainLoop::Exiting;
			break;
        case MainMenu::SubMenu:
            programState = MainLoop::ShowingSubMenu;
            break;
        case MainMenu::Nothing:
            // Vitally important
            ShowMenu();
            break;
	}
}

// ShowLinkedListSubMent etc
void MainLoop::ShowSubMenu(){
    SubMenu subMenu;
    SubMenu::SubMenuResult result = subMenu.Show(mainWindow);
    switch(result){
        case SubMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case SubMenu::Begin:
            programState = MainLoop::Running;
            break;
        case SubMenu::Nothing:
            // Vitally important
            ShowSubMenu();
            break;
    }
}

