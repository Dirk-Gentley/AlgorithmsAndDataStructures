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

	//Begin menu item coordinates
	MenuItem beginButton;
	beginButton.rect.top= 200;
	beginButton.rect.height = 80;
	beginButton.rect.left = 312;
	beginButton.rect.width = 400;
    beginButton.action = SubMenu;
    
    //Begin clickable button
    sf::RectangleShape beginBox;
    beginBox.setSize(sf::Vector2f(400, 80));
    beginBox.setOutlineColor(sf::Color::Red);
    beginBox.setOutlineThickness(5);
    beginBox.setPosition(312, 200);
    renderWindow.draw(beginBox);
    
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
    
	menuItems.push_back(beginButton);
	menuItems.push_back(exitButton);
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text menuText("Menu", font, 80);
    menuText.setPosition(400, 50);
    menuText.setColor(sf::Color::White);
    
    sf::Text beginText("Open Sub Menu", font, 40);
    beginText.setPosition(400, 200);
    beginText.setColor(sf::Color::Red);
    
    sf::Text exitText("Click to Exit", font, 40);
    exitText.setPosition(400, 600);
    exitText.setColor(sf::Color::Red);
    
    renderWindow.draw(menuText);
    renderWindow.draw(beginText);
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
		}
	}
}
