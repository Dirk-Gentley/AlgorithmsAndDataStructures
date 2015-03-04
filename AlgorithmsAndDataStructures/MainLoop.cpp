//
//  game.cpp
//  SFML_test
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

MainLoop::ProgramState MainLoop::programState = Uninitialized;
sf::RenderWindow MainLoop::mainWindow;

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
                
            case MainLoop::ShowingDrawingSubMenu:{
                ShowDrawingSubMenu();
                break;
            }

            case MainLoop::RunningDrawing:{
                mainWindow.clear(sf::Color(255,127,0));
                mainWindow.display();
                if(currentEvent.type == sf::Event::Closed){
                    programState = MainLoop::Exiting;
                }
                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowDrawingSubMenu();
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
        case MainMenu::DrawingSubMenu:
            programState = MainLoop::ShowingDrawingSubMenu;
            break;
        case MainMenu::Nothing:
            // Vitally important
            ShowMenu();
            break;
	}
}

// ShowLinkedListSubMent etc
void MainLoop::ShowDrawingSubMenu(){
    DrawingSubMenu drawingSubMenu;
    DrawingSubMenu::DrawingSubMenuResult result = drawingSubMenu.Show(mainWindow);
    switch(result){
        case DrawingSubMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case DrawingSubMenu::Begin:
            programState = MainLoop::RunningDrawing;
            break;
        case DrawingSubMenu::Nothing:
            // Vitally important
            ShowDrawingSubMenu();
            break;
    }
}

