//
//  MainMenu.h
//  SFML_test
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#ifndef SFML_test_MainMenu_h
#define SFML_test_MainMenu_h

#pragma once

#include "ResourcePath.hpp"

class MainMenu{
    
public:
    // Results are returned by the action handler
	enum MenuResult {   Nothing,
                        Exit,
                        SortingAndSearchingMenu,
                        PuzzlesAndGamesMenu,
                        TreesAndStructuresMenu,
                        SchoolOfImplementationsMenu };
    
	// All menu items are public members, hence struct
	struct MenuItem{
    public:
        sf::Rect<int> rect;
        MenuResult action;
    };
	// Show the menu itself
	MenuResult Show(sf::RenderWindow& window);
    
private:
    // Action listener
	MenuResult GetMenuResponse(sf::RenderWindow& window);
    // Action handler
    MenuResult HandleClick(int x, int y);
	std::list<MenuItem> menuItems;
};

#endif
