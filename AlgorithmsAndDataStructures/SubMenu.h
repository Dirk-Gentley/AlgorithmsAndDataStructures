//
//  SubMenu.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 31/01/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructures__SubMenu__
#define __AlgorithmsAndDataStructures__SubMenu__

#include "ResourcePath.hpp"

class SubMenu{
public:
    enum SubMenuResult { Nothing, Back, Begin };
    
    struct SubMenuItem{
    public:
        sf::Rect<int> rect;
        SubMenuResult action;
    };
    
    SubMenuResult Show(sf::RenderWindow& window);
    
private:
    SubMenuResult GetSubMenuResponse(sf::RenderWindow& window);
    SubMenuResult HandleClick(int x, int y);
    std::list<SubMenuItem> menuItems;
};

#endif /* defined(__AlgorithmsAndDataStructures__SubMenu__) */
