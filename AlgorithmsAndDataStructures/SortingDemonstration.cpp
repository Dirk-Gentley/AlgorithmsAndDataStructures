//
//  SortingDemonstration.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Nicholas Judd on 3/08/2015.
//  Copyright (c) 2015 Nicholas. All rights reserved.
//

#include "ResourcePath.hpp"

void sortingModule::startModule(sf::RenderWindow& mainWindow, sortingModule sort){
    
    backgroundTexture = sort.loadTexture("SortingBackground.png");
    windowSize = mainWindow.getSize();
    buildBackground(mainWindow, sort);
    buildArray();

    while (mainWindow.isOpen()) {
        sf::Event menuEvent;
        drawScreen(mainWindow);
        while (mainWindow.pollEvent(menuEvent)){
            action = -1;
            if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Escape) {
                return;
            }
            if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::P && size < 100) {
                size++;
                buildArray();
            }
            if(menuEvent.type == sf::Event::MouseButtonPressed){
                sf::Vector2i click = handleMouseClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y, mainWindow);
                action = HandleClick(click.x, click.y);
            }
            
            switch (action) {
                    //0. Shuffle
                case 0:
                    swaps = 0;
                    comparisons = 0;
                    play = false;
                    shuffleArray();
                    highlightLine.move(10000, 10000);
                    if (bubble == true){
                        bubbleMenu(mainWindow, action);
                    }else if ( selection == true){
                        selectionMenu(mainWindow, action);
                    }else if (insertion == true){
                        insertionMenu(mainWindow, action);
                    }
                    drawScreen(mainWindow);
                    break;
                    //1. Bubble sort
                case 1:
                    bubbleMenu(mainWindow, action);
                    break;
                    
                    //2. Reverse Sort
                case 2:
                    play = false;
                    reverseSortArray();
                    drawScreen(mainWindow);
                    break;
                    
                    //3. Selection Sort
                case 3:
                    selectionMenu(mainWindow, action);
                    break;
                    //4. Sorted Array
                case 4:
                    play = false;
                    forwardSortArray();
                    drawScreen(mainWindow);
                    break;
                    
                    //5. Insertion Sort
                case 5:
                    insertionMenu(mainWindow, action);
                    break;
                    //6. minus elements
                case 6:
                    if (play == false){
                        if (size >= 6 && size <= 101){
                            animate.erase(animate.begin(), animate.end());
                            size--;
                            buildArray();
                        }
                    }
                    break;
                    //7. plus elements
                case 7:
                    std::cout << size << std::endl;
                    if (play == false){
                        if (size >= 5 && size <= 100){
                            animate.erase(animate.begin(), animate.end());
                            size++;
                            buildArray();
                        }
                    }
                    break;
                    //8. Back
                case 8:
                    return;
                    break;
                    //9. Step Through
                case 9:
                    step = true;
                    drawScreen(mainWindow);
                    break;
                    //10. Play
                case 10:
                    if (play == false){
                        play = true;
                    }else {
                        play = false;
                    }
                    drawScreen(mainWindow);
                    break;
                    
                default:
                    drawScreen(mainWindow);
                    break;
            }
            
        }
        
    }
    
}

void sortingModule::bubbleMenu(sf::RenderWindow& mainWindow, int action){
    buildPsuedo(1);
    swaps = 0;
    comparisons = 0;
    play = false;
    bubble = true;
    selection = false;
    insertion = false;
    animate.erase(animate.begin(), animate.end());
    bubbleSortFunction(mainWindow);
    drawScreen(mainWindow);
}

void sortingModule::selectionMenu(sf::RenderWindow& mainWindow, int action){
    buildPsuedo(3);
    swaps = 0;
    comparisons = 0;
    play = false;
    bubble = false;
    selection = true;
    insertion = false;
    animate.erase(animate.begin(), animate.end());
    selectionSortFunction(mainWindow);
    drawScreen(mainWindow);
}
void sortingModule::insertionMenu(sf::RenderWindow& mainWindow, int action){
    buildPsuedo(5);
    swaps = 0;
    comparisons = 0;
    play = false;
    bubble = false;
    selection = false;
    insertion = true;
    animate.erase(animate.begin(), animate.end());
    insertionSortFunction(mainWindow);
    drawScreen(mainWindow);
}