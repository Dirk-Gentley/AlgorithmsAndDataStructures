//
//  game.cpp
//  SFML_test
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

void MainLoop::Start(void){
    if(programState != Uninitialized)
        return;
    
    mainWindow.create(sf::VideoMode(1024,768,32),"Window");
    programState = MainLoop::ShowingSplash;
    
    while(!IsExiting()){
        GameLoop();
    }
    
    mainWindow.close();
}

bool MainLoop::IsExiting(){
    if(programState == MainLoop::Exiting)
        return true;
    else
        return false;
}

void MainLoop::GameLoop(){
    sf::Event currentEvent;
    while(mainWindow.pollEvent(currentEvent)){

        switch(programState){
            case MainLoop::Running:{
                mainWindow.clear(sf::Color(255,127,0));
                mainWindow.display();

                if(currentEvent.type == sf::Event::Closed){
                    programState = MainLoop::Exiting;
                }
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
            ShowMenu();
            break;
	}
}

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
        case MainMenu::Nothing:
            ShowMenu();
            break;
    }
}

