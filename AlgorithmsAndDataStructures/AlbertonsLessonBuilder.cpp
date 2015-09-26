//
//  AlbertonsLessonBuilder.cpp
//  AlbertonsLessonBuilder
//
//  Created by Benjamin Waters on 11/09/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "AlbertonsLessonBuilder.h"

void buildLesson(std::string fileName, sf::RenderWindow &window){
    sf::Clock clock;
    
    std::list<std::pair<int, std::string> > DialogueCommands = read(fileName);
    
    sf::Texture LessonDialogueBackground = MappedLessonDialogueGraphics.initBackground();
    sf::Texture LessonDialogueCharacters = MappedLessonDialogueGraphics.initCharacters();
    MappedLessonDialogueGraphics.initBGSprite(LessonDialogueBackground);
    MappedLessonDialogueGraphics.initCharacterSprites(LessonDialogueCharacters);
    
    bool skip = false;
    
    while (window.isOpen()) {
        albertonInput(window, skip);
        if(updateGraphics(window, MappedLessonDialogueGraphics, DialogueCommands, clock, skip) == 0){
            return;
        };
    }
    return;
}

sf::Texture const LessonDialogueGraphics::initBackground(){
    sf::Texture Texture;
    if (!Texture.loadFromFile(resourcePath() + "AlbertonLessonBackground.gif")) {
        std::cerr << "ERROR with background " << std::endl;
    }
    return Texture;
}

sf::Texture const LessonDialogueGraphics::initCharacters(){
    sf::Texture Texture;
    if (!Texture.loadFromFile(resourcePath() + "LessonCharacters.png")) {
        std::cerr << "ERROR with characters " << std::endl;
    }
    return Texture;
}

LessonDialogueGraphics const LessonDialogueGraphics::initBGSprite(sf::Texture &Texture){
    sf::Sprite Background(Texture);
    DialogueBackground = Background;
    return *this;
}

LessonDialogueGraphics const LessonDialogueGraphics::initCharacterSprites(sf::Texture &Texture){
    sf::Sprite Alberton(Texture);
    Alberton.setTextureRect(sf::IntRect(0,0,300,300));
    ProfessorSprite = Alberton;
    sf::Sprite Companion(Texture);
    Companion.setTextureRect(sf::IntRect(300,0,300,300));
    CompanionSprite = Companion;
    return *this;
}

void albertonInput(sf::RenderWindow &window, bool &skip){
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            return;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            skip = true;
        }
    }
}

int updateGraphics(sf::RenderWindow &window, LessonDialogueGraphics &MappedLessonDialogueGraphics, std::list<std::pair<int, std::string> > &Dialogue, sf::Clock &clock, bool &skip){
    sf::Event event;
    if (sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        return 0;
    }
    
    window.clear();
    
    sf::Font DialogueFont;
    if (!DialogueFont.loadFromFile(resourcePath() + "sansation.ttf")) {
        std::cerr << "Font not found" << std::endl;
    }
    sf::Text DialogueText;
    DialogueText.setFont(DialogueFont);
    DialogueText.setColor(sf::Color::White);
    
    sf::Sprite Background, Alberton, Companion;
    Background = MappedLessonDialogueGraphics.getDialogueBackround();
    Background.setPosition(0,0);
    window.draw(Background);
    
    Alberton = MappedLessonDialogueGraphics.getProfessorSprite();
    Alberton.setPosition(64, 460);
    window.draw(Alberton);
    
    Companion = MappedLessonDialogueGraphics.getCompanionSprite();
    Companion.setPosition(676, 460);
    window.draw(Companion);
    
    std::list<std::pair<int, std::string> >::iterator it = Dialogue.begin();

    int speaker = it->first;
    std::string nextDialogue = it->second;
    DialogueText.setString(nextDialogue);
    
    if(speaker == 0){
        DialogueText.setPosition(280, 460);
    }
    else{
        DialogueText.setPosition(600, 500);
    }
    
    sf::Time elapsed1 = clock.getElapsedTime();
    
    if (elapsed1.asSeconds() > 3){
        if(it != Dialogue.end()){
            Dialogue.pop_front();
        }
        clock.restart();
    }
    
    if (skip == true){
        if(it != Dialogue.end()){
            Dialogue.pop_front();
        }
        it++;
        clock.restart();
        skip = false;
    }
    
    window.draw(DialogueText);
    window.display();
    it = Dialogue.begin();
    if(it != Dialogue.end()){
        return 1;
    }else{
        return 0;
    }
}

std::list<std::pair<int, std::string> > read(std::string filename){
    std::list<std::pair<int, std::string> > DialogueCommands;
    std::ifstream infile;
    infile.open(resourcePath() + filename.c_str(), std::ifstream::in);
    if (!infile.good()){
        std::cout << "Problem opening file" << std::endl;
        exit(0);
    }
    std::string command;
    while (std::getline(infile, command)){
        std::string token = command.substr(0, command.find(":"));
        if (token.compare("Professor") == 0){
            int speaking = 0;
            std::pair<int, std::string> speaker_dialogue;
            std::string::size_type i = command.find("Professor: ");
            if (i != std::string::npos){
                command.erase(i, token.length() + 2);
            }
            speaker_dialogue.first = speaking;
            speaker_dialogue.second = command;
            DialogueCommands.push_back(speaker_dialogue);
        }
        if (token.compare("Companion") == 0){
            int speaking = 1;
            std::string::size_type i = command.find("Companion: ");
            if (i != std::string::npos){
                command.erase(i, token.length() + 2);
            }
            std::pair<int, std::string> speaker_dialogue;
            speaker_dialogue.first = speaking;
            speaker_dialogue.second = command;
            DialogueCommands.push_back(speaker_dialogue);
        }
    }
    return DialogueCommands;
}
