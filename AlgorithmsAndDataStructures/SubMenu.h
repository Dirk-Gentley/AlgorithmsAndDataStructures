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

class DrawingSubMenu{
public:
    enum DrawingSubMenuResult { Nothing, Back, Begin };
    
    struct DrawingSubMenuItem{
    public:
        sf::Rect<int> rect;
        DrawingSubMenuResult action;
    };
    
    DrawingSubMenuResult Show(sf::RenderWindow& window);
    
private:
    DrawingSubMenuResult GetDrawingSubMenuResponse(sf::RenderWindow& window);
    DrawingSubMenuResult HandleClick(int x, int y);
    std::list<DrawingSubMenuItem> menuItems;
};

#endif /* defined(__AlgorithmsAndDataStructures__SubMenu__) */
