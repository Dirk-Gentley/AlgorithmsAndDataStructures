//
//  input.h
//  Trevors_Traversal
//
//  Created by Benjamin Waters on 9/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __Trevors_Traversal__input__
#define __Trevors_Traversal__input__

#include "ResourcePath.hpp"

//Node *input(sf::RenderWindow&, class Character&, class Maps&, Node *, class BTree &, class TreeDungeonGraphics &);
int input(sf::RenderWindow&, class Character&, class Maps&, Node* &, class BTree &, class TreeDungeonGraphics &);
bool collisions(class Character& Character, Maps& Map);
void treasure(class Character& Character, Maps& Map);

#endif /* defined(__Trevors_Traversal__input__) */
