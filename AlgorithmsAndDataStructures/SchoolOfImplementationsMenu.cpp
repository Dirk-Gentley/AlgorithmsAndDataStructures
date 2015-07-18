//
//  SchoolOfImplementations.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

/*****************************************************
 
 SCHOOL OF IMPLEMENTATIONS MENU AND ACTION HANDLERS / LISTENERS
 
 *****************************************************/

SchoolOfImplementationsMenu::SchoolOfImplementationsMenuResult SchoolOfImplementationsMenu::Show(sf::RenderWindow& renderWindow){
    renderWindow.clear(sf::Color(200,200,100));
    
    //Begin menu item coordinates
    SchoolOfImplementationsMenuItem beginButton;
    beginButton.rect.top= 200;
    beginButton.rect.height = 80;
    beginButton.rect.left = 312;
    beginButton.rect.width = 400;
    beginButton.action = Begin;
    
    //Begin clickable button
    sf::RectangleShape beginBox;
    beginBox.setSize(sf::Vector2f(400, 80));
    beginBox.setOutlineColor(sf::Color::Red);
    beginBox.setOutlineThickness(5);
    beginBox.setPosition(312, 200);
    renderWindow.draw(beginBox);
    
    //Exit menu item coordinates
    SchoolOfImplementationsMenuItem backButton;
    backButton.rect.top = 600;
    backButton.rect.height = 80;
    backButton.rect.left = 312;
    backButton.rect.width = 400;
    backButton.action = Back;
    
    //Exit clickable button
    sf::RectangleShape exitBox;
    exitBox.setSize(sf::Vector2f(400, 80));
    exitBox.setOutlineColor(sf::Color::Red);
    exitBox.setOutlineThickness(5);
    exitBox.setPosition(312, 600);
    renderWindow.draw(exitBox);
    
    menuItems.push_back(beginButton);
    menuItems.push_back(backButton);
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text menuText("School of Implementations Menu", font, 80);
    menuText.setPosition(400, 50);
    menuText.setColor(sf::Color::White);
    
    sf::Text beginText("But where would I use that?", font, 40);
    beginText.setPosition(400, 200);
    beginText.setColor(sf::Color::Red);
    
    sf::Text backText("Back", font, 40);
    backText.setPosition(400, 600);
    backText.setColor(sf::Color::Red);
    
    renderWindow.draw(menuText);
    renderWindow.draw(beginText);
    renderWindow.draw(backText);
    
    renderWindow.display();
    return GetSchoolOfImplementationsMenuResponse(renderWindow);
}

SchoolOfImplementationsMenu::SchoolOfImplementationsMenuResult SchoolOfImplementationsMenu::HandleClick(int x, int y){
    std::list<SchoolOfImplementationsMenuItem>::iterator it;
    
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

SchoolOfImplementationsMenu::SchoolOfImplementationsMenuResult SchoolOfImplementationsMenu::GetSchoolOfImplementationsMenuResponse(sf::RenderWindow& window){
    sf::Event menuEvent;
    
    for(;;){
        while(window.pollEvent(menuEvent)){
            if(menuEvent.type == sf::Event::MouseButtonPressed){
                return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
            }
            if(menuEvent.type == sf::Event::Closed){
                return Back;
            }
            if(menuEvent.type == sf::Event::KeyPressed){
                return Back;
            }
        }
    }
}
