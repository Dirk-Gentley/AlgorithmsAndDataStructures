//
//  MainMenu.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& renderWindow){
    
    renderWindow.clear(sf::Color(sf::Color::Black));
    
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "MMBackground.png");
    sf::Sprite sprite(texture);
    
	//Begin sorting and searching menu item coordinates
	MenuItem beginSortingAndSearchingButton;
	beginSortingAndSearchingButton.rect.top= 200;
	beginSortingAndSearchingButton.rect.height = 200;
	beginSortingAndSearchingButton.rect.left = 212;
	beginSortingAndSearchingButton.rect.width = 300;
    beginSortingAndSearchingButton.action = SortingAndSearchingMenu;
    
    //Sorting and Searching clickable button
    sf::RectangleShape beginSortingAndSearchingBox;
    beginSortingAndSearchingBox.setSize(sf::Vector2f(296, 200));
    beginSortingAndSearchingBox.setOutlineColor(sf::Color::Blue);
    beginSortingAndSearchingBox.setFillColor(sf::Color::Blue);
    beginSortingAndSearchingBox.setOutlineThickness(5);
    beginSortingAndSearchingBox.setPosition(212, 200);
    renderWindow.draw(beginSortingAndSearchingBox);
    
    //Begin trees and structures menu item coordinates
    MenuItem beginTreesAndStructuresButton;
    beginTreesAndStructuresButton.rect.top= 200;
    beginTreesAndStructuresButton.rect.height = 200;
    beginTreesAndStructuresButton.rect.left = 522;
    beginTreesAndStructuresButton.rect.width = 300;
    beginTreesAndStructuresButton.action = TreesAndStructuresMenu;
    
    //Trees and Structures clickable button
    sf::RectangleShape beginTreesAndStructuresBox;
    beginTreesAndStructuresBox.setSize(sf::Vector2f(296, 200));
    beginTreesAndStructuresBox.setOutlineColor(sf::Color::Blue);
    beginTreesAndStructuresBox.setFillColor(sf::Color::Blue);
    beginTreesAndStructuresBox.setOutlineThickness(5);
    beginTreesAndStructuresBox.setPosition(528, 200);
    renderWindow.draw(beginTreesAndStructuresBox);
    
    //Begin puzzles and games menu item coordinates
    MenuItem beginPuzzlesAndGamesButton;
    beginPuzzlesAndGamesButton.rect.top= 420;
    beginPuzzlesAndGamesButton.rect.height = 200;
    beginPuzzlesAndGamesButton.rect.left = 212;
    beginPuzzlesAndGamesButton.rect.width = 300;
    beginPuzzlesAndGamesButton.action = PuzzlesAndGamesMenu;
    
    //Puzzles and games clickable button
    sf::RectangleShape beginPuzzlesAndGamesBox;
    beginPuzzlesAndGamesBox.setSize(sf::Vector2f(296, 200));
    beginPuzzlesAndGamesBox.setOutlineColor(sf::Color::Blue);
    beginPuzzlesAndGamesBox.setFillColor(sf::Color::Blue);
    beginPuzzlesAndGamesBox.setOutlineThickness(5);
    beginPuzzlesAndGamesBox.setPosition(212, 420);
    renderWindow.draw(beginPuzzlesAndGamesBox);
    
    //Begin school of implementations menu item coordinates
    MenuItem beginSchoolOfImplementationsButton;
    beginSchoolOfImplementationsButton.rect.top = 420;
    beginSchoolOfImplementationsButton.rect.height = 200;
    beginSchoolOfImplementationsButton.rect.left = 524;
    beginSchoolOfImplementationsButton.rect.width = 300;
    beginSchoolOfImplementationsButton.action = SchoolOfImplementationsMenu;
    
    //School of implementations clickable button
    sf::RectangleShape beginSchoolOfImplementationsBox;
    beginSchoolOfImplementationsBox.setSize(sf::Vector2f(296, 200));
    beginSchoolOfImplementationsBox.setOutlineColor(sf::Color::Blue);
    beginSchoolOfImplementationsBox.setFillColor(sf::Color::Blue);
    beginSchoolOfImplementationsBox.setOutlineThickness(5);
    beginSchoolOfImplementationsBox.setPosition(528, 420);
    renderWindow.draw(beginSchoolOfImplementationsBox);
    /*
	//Exit menu item coordinates
	MenuItem exitButton;
    exitButton.rect.top = 650;
    exitButton.rect.height = 80;
	exitButton.rect.left = 312;
	exitButton.rect.width = 400;
	exitButton.action = Exit;
    
    //Exit clickable button
    sf::RectangleShape exitBox;
    exitBox.setSize(sf::Vector2f(400, 80));
    exitBox.setOutlineColor(sf::Color::Red);
    exitBox.setOutlineThickness(5);
    exitBox.setPosition(312, 650);
    renderWindow.draw(exitBox);
    */
	menuItems.push_back(beginSortingAndSearchingButton);
    menuItems.push_back(beginTreesAndStructuresButton);
    menuItems.push_back(beginPuzzlesAndGamesButton);
    menuItems.push_back(beginSchoolOfImplementationsButton);
	//menuItems.push_back(exitButton);
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text menuText("Menu", font, 80);
    menuText.setPosition(400, 50);
    menuText.setColor(sf::Color::White);
    
    sf::Text beginSortingAndSearchingText("Sorting", font, 40);
    beginSortingAndSearchingText.setPosition(300, 200);
    
    sf::Text beginTreesAndStructuresText("Structures", font, 40);
    beginTreesAndStructuresText.setPosition(580, 200);
    
    sf::Text beginPuzzlesAndGamesText("Puzzles", font, 40);
    beginPuzzlesAndGamesText.setPosition(300, 420);
    
    sf::Text beginSchoolOfImplementationsText("School", font, 40);
    beginSchoolOfImplementationsText.setPosition(620, 420);
    
    renderWindow.draw(sprite);

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
                sf::Vector2i click = handleMouseClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y, window);
                return HandleClick(click.x, click.y);
			}
			if(menuEvent.type == sf::Event::Closed){
				return Exit;
			}
            if(menuEvent.type == sf::Event::KeyPressed){
                return Exit;
            }
            if(menuEvent.type == sf::Event::Resized){
                sf::FloatRect visibleArea(0, 0, menuEvent.size.width, menuEvent.size.height);
                window.setView(sf::View(visibleArea));
            }
		}
	}
}
