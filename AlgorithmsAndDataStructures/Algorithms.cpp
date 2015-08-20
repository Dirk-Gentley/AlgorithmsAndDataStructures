//
//  Algorithms.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 4/03/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

void bresenhams(int x1, int y1, int x2, int y2){
    
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    int x = x1;
    int y = y1;
    int n = 1 + dx + dy;
    int x_inc = (x1 > x2) ? 1 : -1;
    int y_inc = (y1 > y2) ? 1 : -1;
    int error = dx - dy;
    
    dx *= 2;
    dy *= 2;
    
    for (; n > 0; n--){
        if (error > 0){
            x += x_inc;
            error -= dy;
        }
        else{
            y += y_inc;
            error += dx;
        }
    }
}
