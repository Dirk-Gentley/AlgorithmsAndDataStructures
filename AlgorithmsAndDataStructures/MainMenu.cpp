//
//  MainMenu.cpp
//  SFML_test
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& renderWindow){
    
    renderWindow.clear(sf::Color(63,63,63));

	//Begin sorting and searching menu item coordinates
	MenuItem beginSortingAndSearchingButton;
	beginSortingAndSearchingButton.rect.top= 200;
	beginSortingAndSearchingButton.rect.height = 80;
	beginSortingAndSearchingButton.rect.left = 312;
	beginSortingAndSearchingButton.rect.width = 400;
    beginSortingAndSearchingButton.action = SortingAndSearchingMenu;
    
    //Sorting and Searching clickable button
    sf::RectangleShape beginSortingAndSearchingBox;
    beginSortingAndSearchingBox.setSize(sf::Vector2f(400, 80));
    beginSortingAndSearchingBox.setOutlineColor(sf::Color::Red);
    beginSortingAndSearchingBox.setOutlineThickness(5);
    beginSortingAndSearchingBox.setPosition(312, 200);
    renderWindow.draw(beginSortingAndSearchingBox);
    
    //Begin trees and structures menu item coordinates
    MenuItem beginTreesAndStructuresButton;
    beginTreesAndStructuresButton.rect.top= 300;
    beginTreesAndStructuresButton.rect.height = 80;
    beginTreesAndStructuresButton.rect.left = 312;
    beginTreesAndStructuresButton.rect.width = 400;
    beginTreesAndStructuresButton.action = TreesAndStructuresMenu;
    
    //Trees and Structures clickable button
    sf::RectangleShape beginTreesAndStructuresBox;
    beginTreesAndStructuresBox.setSize(sf::Vector2f(400, 80));
    beginTreesAndStructuresBox.setOutlineColor(sf::Color::Red);
    beginTreesAndStructuresBox.setOutlineThickness(5);
    beginTreesAndStructuresBox.setPosition(312, 300);
    renderWindow.draw(beginTreesAndStructuresBox);
    
    //Begin puzzles and games menu item coordinates
    MenuItem beginPuzzlesAndGamesButton;
    beginPuzzlesAndGamesButton.rect.top= 400;
    beginPuzzlesAndGamesButton.rect.height = 80;
    beginPuzzlesAndGamesButton.rect.left = 312;
    beginPuzzlesAndGamesButton.rect.width = 400;
    beginPuzzlesAndGamesButton.action = PuzzlesAndGamesMenu;
    
    //Puzzles and games clickable button
    sf::RectangleShape beginPuzzlesAndGamesBox;
    beginPuzzlesAndGamesBox.setSize(sf::Vector2f(400, 80));
    beginPuzzlesAndGamesBox.setOutlineColor(sf::Color::Red);
    beginPuzzlesAndGamesBox.setOutlineThickness(5);
    beginPuzzlesAndGamesBox.setPosition(312, 400);
    renderWindow.draw(beginPuzzlesAndGamesBox);
    
    //Begin school of implementations menu item coordinates
    MenuItem beginSchoolOfImplementationsButton;
    beginSchoolOfImplementationsButton.rect.top= 500;
    beginSchoolOfImplementationsButton.rect.height = 80;
    beginSchoolOfImplementationsButton.rect.left = 312;
    beginSchoolOfImplementationsButton.rect.width = 400;
    beginSchoolOfImplementationsButton.action = SchoolOfImplementationsMenu;
    
    //School of implementations clickable button
    sf::RectangleShape beginSchoolOfImplementationsBox;
    beginSchoolOfImplementationsBox.setSize(sf::Vector2f(400, 80));
    beginSchoolOfImplementationsBox.setOutlineColor(sf::Color::Red);
    beginSchoolOfImplementationsBox.setOutlineThickness(5);
    beginSchoolOfImplementationsBox.setPosition(312, 500);
    renderWindow.draw(beginSchoolOfImplementationsBox);
    
	//Exit menu item coordinates
	MenuItem exitButton;
    exitButton.rect.top = 600;
    exitButton.rect.height = 80;
	exitButton.rect.left = 312;
	exitButton.rect.width = 400;
	exitButton.action = Exit;
    
    //Exit clickable button
    sf::RectangleShape exitBox;
    exitBox.setSize(sf::Vector2f(400, 80));
    exitBox.setOutlineColor(sf::Color::Red);
    exitBox.setOutlineThickness(5);
    exitBox.setPosition(312, 600);
    renderWindow.draw(exitBox);
    
	menuItems.push_back(beginSortingAndSearchingButton);
    menuItems.push_back(beginTreesAndStructuresButton);
    menuItems.push_back(beginPuzzlesAndGamesButton);
    menuItems.push_back(beginSchoolOfImplementationsButton);
	menuItems.push_back(exitButton);
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text menuText("Menu", font, 80);
    menuText.setPosition(400, 50);
    menuText.setColor(sf::Color::White);
    
    sf::Text beginSortingAndSearchingText("Sorting and Searching", font, 40);
    beginSortingAndSearchingText.setPosition(400, 200);
    beginSortingAndSearchingText.setColor(sf::Color::Red);
    
    sf::Text beginTreesAndStructuresText("Trees and Structures", font, 40);
    beginTreesAndStructuresText.setPosition(400, 300);
    beginTreesAndStructuresText.setColor(sf::Color::Red);
    
    sf::Text beginPuzzlesAndGamesText("Puzzles and Games", font, 40);
    beginPuzzlesAndGamesText.setPosition(400, 400);
    beginPuzzlesAndGamesText.setColor(sf::Color::Red);
    
    sf::Text beginSchoolOfImplementationsText("School of Implementations", font, 40);
    beginSchoolOfImplementationsText.setPosition(400, 500);
    beginSchoolOfImplementationsText.setColor(sf::Color::Red);
    
    sf::Text exitText("Click to Exit", font, 40);
    exitText.setPosition(400, 600);
    exitText.setColor(sf::Color::Red);
    
    renderWindow.draw(menuText);
    renderWindow.draw(beginSortingAndSearchingText);
    renderWindow.draw(beginPuzzlesAndGamesText);
    renderWindow.draw(beginTreesAndStructuresText);
    renderWindow.draw(beginSchoolOfImplementationsText);
    renderWindow.draw(exitText);
	renderWindow.display();
    
	return GetMenuResponse(renderWindow);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y){
	std::list<MenuItem>::iterator it;
    
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

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window){
	sf::Event menuEvent;
    
    for(;;){
		while(window.pollEvent(menuEvent)){
			if(menuEvent.type == sf::Event::MouseButtonPressed){
				return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
			}
			if(menuEvent.type == sf::Event::Closed){
				return Exit;
			}
            if(menuEvent.type == sf::Event::KeyPressed){
                return Exit;
            }
		}
	}
}
