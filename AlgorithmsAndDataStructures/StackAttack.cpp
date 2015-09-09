//
//  StackAttack.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 4/08/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

void stackAttack(sf::RenderWindow& window){
    window.clear();
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "StackAttackBackground.png");
    sf::Sprite sprite(texture);
    window.draw(sprite);
    window.display();
}