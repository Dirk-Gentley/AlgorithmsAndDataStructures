//
//  SpalshScreen.cpp
//  SFML_test
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

void SplashScreen::Show(sf::RenderWindow &renderWindow){

    renderWindow.clear(sf::Color(0,0,0));
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text text("This is the Splash Screen", font, 50);
    text.setPosition(220, 50);
    text.setColor(sf::Color::White);
    
    renderWindow.draw(text);

    renderWindow.display();
    sf::Event event;
    while(true){
        while(renderWindow.pollEvent(event)){
            if( event.type == sf::Event::EventType::KeyPressed ||
                event.type == sf::Event::EventType::MouseButtonPressed ||
                event.type == sf::Event::EventType::Closed ){
                return;
            }
        }
    }
}
