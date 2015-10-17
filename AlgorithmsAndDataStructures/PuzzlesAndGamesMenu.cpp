//
//  PuzzlesAndGamesMenu.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "PuzzlesAndGamesMenu.h"

/*****************************************************
 
 PUZZLES AND GAMES MENU AND ACTION HANDLERS / LISTENERS
 
 *****************************************************/

PuzzlesAndGamesMenu::PuzzlesAndGamesMenuResult PuzzlesAndGamesMenu::Show(sf::RenderWindow& renderWindow){
    renderWindow.clear(sf::Color(sf::Color::Black));
    
    //Begin menu item coordinates
    PuzzlesAndGamesMenuItem beginButton;
    beginButton.rect.top= 200;
    beginButton.rect.height = 80;
    beginButton.rect.left = 312;
    beginButton.rect.width = 400;
    beginButton.action = BeginConways;
    
    //Begin clickable button
    sf::RectangleShape beginBox;
    beginBox.setSize(sf::Vector2f(400, 80));
    beginBox.setOutlineColor(sf::Color::Blue);
    beginBox.setFillColor(sf::Color::Blue);
    beginBox.setOutlineThickness(0);
    beginBox.setPosition(312, 200);
    renderWindow.draw(beginBox);
    
    //Begin boat menu item coordinates
    PuzzlesAndGamesMenuItem beginBoatButton;
    beginBoatButton.rect.top= 300;
    beginBoatButton.rect.height = 80;
    beginBoatButton.rect.left = 312;
    beginBoatButton.rect.width = 400;
    beginBoatButton.action = BeginRiverCrossing;
    
    //Begin boat clickable button
    sf::RectangleShape beginBoatBox;
    beginBoatBox.setSize(sf::Vector2f(400, 80));
    beginBoatBox.setOutlineColor(sf::Color::Blue);
    beginBoatBox.setFillColor(sf::Color::Blue);
    beginBoatBox.setOutlineThickness(0);
    beginBoatBox.setPosition(312, 300);
    renderWindow.draw(beginBoatBox);
    
    //Exit menu item coordinates
    PuzzlesAndGamesMenuItem backButton;
    backButton.rect.top = 600;
    backButton.rect.height = 80;
    backButton.rect.left = 312;
    backButton.rect.width = 400;
    backButton.action = Back;
    
    //Exit clickable button
    sf::RectangleShape exitBox;
    exitBox.setSize(sf::Vector2f(400, 80));
    exitBox.setOutlineColor(sf::Color::Blue);
    exitBox.setFillColor(sf::Color::Blue);
    exitBox.setOutlineThickness(0);
    exitBox.setPosition(312, 600);
    renderWindow.draw(exitBox);
    
    menuItems.push_back(beginButton);
    menuItems.push_back(beginBoatButton);
    menuItems.push_back(backButton);
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text menuText("Puzzles and Games", font, 80);
    menuText.setPosition(160, 50);
    menuText.setColor(sf::Color::White);
    
    sf::Text beginText("Conways Game of Life", font, 40);
    beginText.setPosition(310, 200);
    beginText.setColor(sf::Color::White);
    
    sf::Text beginBoatText("River Crossing", font, 40);
    beginBoatText.setPosition(390, 300);
    beginBoatText.setColor(sf::Color::White);
    
    sf::Text backText("Back", font, 40);
    backText.setPosition(460, 600);
    backText.setColor(sf::Color::White);
    
    renderWindow.draw(menuText);
    renderWindow.draw(beginText);
    renderWindow.draw(beginBoatText);
    renderWindow.draw(backText);
    
    renderWindow.display();
    return GetPuzzlesAndGamesMenuResponse(renderWindow);
}

PuzzlesAndGamesMenu::PuzzlesAndGamesMenuResult PuzzlesAndGamesMenu::HandleClick(int x, int y){
    std::list<PuzzlesAndGamesMenuItem>::iterator it;
    
    for ( it = menuItems.begin(); it != menuItems.end(); it++){
        sf::Rect<int> menuItemRect = (*it).rect;
        if( x > menuItemRect.left
           && x < menuItemRect.left + menuItemRect.width
           && y > menuItemRect.top
           && y < menuItemRect.height + menuItemRect.top){
            return (*it).action;
        }
    }
    return Nothing;
}

PuzzlesAndGamesMenu::PuzzlesAndGamesMenuResult PuzzlesAndGamesMenu::GetPuzzlesAndGamesMenuResponse(sf::RenderWindow& window){
    sf::Event menuEvent;
    
    for(;;){
        while(window.pollEvent(menuEvent)){
            if(menuEvent.type == sf::Event::MouseButtonPressed){
                sf::Vector2i click = handleMouseClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y, window);
                return HandleClick(click.x, click.y);
            }
            if(menuEvent.type == sf::Event::KeyPressed){
                if(menuEvent.key.code == sf::Keyboard::Q){
                    return Back;
                }
            }
        }
    }
}

