//
//  character.cpp
//  Trevors_Traversal
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

Character::Character(){
    playerXPosition = 256;
    playerYPosition = 160;
    playerMove = false;
    treasureCollected = 0;
    onTreasure = false;
    goal = 1;
    treasureInventory = "";
}
