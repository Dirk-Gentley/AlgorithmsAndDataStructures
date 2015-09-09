//
//  SortingAndSearching.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "SortingAndSearchingMenu.h"

/*****************************************************
 
SORTING AND SEARCHING MENU AND ACTION HANDLERS / LISTENERS
 
 *****************************************************/

SortingAndSearchingMenu::SortingAndSearchingMenuResult SortingAndSearchingMenu::Show(sf::RenderWindow& renderWindow){
    renderWindow.clear(sf::Color(sf::Color::Black));
    
    //Begin lesson menu item coordinates
    SortingAndSearchingMenuItem beginLessonButton;
    beginLessonButton.rect.top = 200;
    beginLessonButton.rect.height = 80;
    beginLessonButton.rect.left = 312;
    beginLessonButton.rect.width = 400;
    beginLessonButton.action = BeginLesson;
    
    //Begin lesson clickable button
    sf::RectangleShape beginLessonBox;
    beginLessonBox.setSize(sf::Vector2f(400, 80));
    beginLessonBox.setOutlineColor(sf::Color::Blue);
    beginLessonBox.setFillColor(sf::Color::Blue);
    beginLessonBox.setOutlineThickness(5);
    beginLessonBox.setPosition(312, 200);
    renderWindow.draw(beginLessonBox);
    
    //Begin demo menu item coordinates
    SortingAndSearchingMenuItem beginDemoButton;
    beginDemoButton.rect.top = 300;
    beginDemoButton.rect.height = 80;
    beginDemoButton.rect.left = 312;
    beginDemoButton.rect.width = 400;
    beginDemoButton.action = BeginDemo;
    
    //Begin demo clickable button
    sf::RectangleShape beginDemoBox;
    beginDemoBox.setSize(sf::Vector2f(400, 80));
    beginDemoBox.setOutlineColor(sf::Color::Blue);
    beginDemoBox.setFillColor(sf::Color::Blue);
    beginDemoBox.setOutlineThickness(5);
    beginDemoBox.setPosition(312, 300);
    renderWindow.draw(beginDemoBox);
    
    //Exit menu item coordinates
    SortingAndSearchingMenuItem backButton;
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
    exitBox.setOutlineThickness(5);
    exitBox.setPosition(312, 600);
    renderWindow.draw(exitBox);
    
    menuItems.push_back(beginLessonButton);
    menuItems.push_back(beginDemoButton);
    menuItems.push_back(backButton);
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    
    sf::Text menuText("Sorting", font, 80);
    menuText.setPosition(380, 50);
    menuText.setColor(sf::Color::White);
    
    sf::Text beginLessonText("A Lesson on Sorting", font, 40);
    beginLessonText.setPosition(330, 200);
    beginLessonText.setColor(sf::Color::White);
    
    sf::Text beginDemoText("Demonstration", font, 40);
    beginDemoText.setPosition(380, 300);
    beginDemoText.setColor(sf::Color::White);
    
    sf::Text backText("Back", font, 40);
    backText.setPosition(460, 600);
    backText.setColor(sf::Color::White);
    
    renderWindow.draw(menuText);
    renderWindow.draw(beginLessonText);
    renderWindow.draw(beginDemoText);
    renderWindow.draw(backText);
    
    renderWindow.display();
    return GetSortingAndSearchingMenuResponse(renderWindow);
}

SortingAndSearchingMenu::SortingAndSearchingMenuResult SortingAndSearchingMenu::HandleClick(int x, int y){
    std::list<SortingAndSearchingMenuItem>::iterator it;
    
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

SortingAndSearchingMenu::SortingAndSearchingMenuResult SortingAndSearchingMenu::GetSortingAndSearchingMenuResponse(sf::RenderWindow& window){
    sf::Event menuEvent;
    for(;;){
        while(window.pollEvent(menuEvent)){
            if(menuEvent.type == sf::Event::MouseButtonPressed){
                return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
            }
            if(menuEvent.type == sf::Event::KeyPressed){
                return Back;
            }
        }
    }
}

