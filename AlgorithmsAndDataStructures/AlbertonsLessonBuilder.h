//
//  AlbertonsLessonBuilder.h
//  AlbertonsLessonBuilder
//
//  Created by Benjamin Waters on 11/09/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __AlbertonsLessonBuilder__AlbertonsLessonBuilder__
#define __AlbertonsLessonBuilder__AlbertonsLessonBuilder__

#include "ResourcePath.hpp"

void runLessonBuilder(std::string, sf::RenderWindow &);

void buildLesson(std::string, sf::RenderWindow &);

struct LessonDialogue{
    std::vector<std::string> professorString;
    std::vector<std::string> companionString;
    
    int professorChatCounter;
    int companionChatCounter;
    
    std::string getProfessorString()                                        { return professorString.front(); };
    std::string getCompanionSTring()                                        { return companionString.front(); };
    LessonDialogue();
};

class LessonDialogueGraphics{
private:
    sf::Sprite DialogueBackground;
    sf::Sprite ProfessorSprite;
    sf::Sprite CompanionSprite;
    
    sf::Text ProfessorChat;
    sf::Text CompanionChat;
public:
    sf::Sprite getDialogueBackround()                                       { return DialogueBackground; };
    sf::Sprite getProfessorSprite()                                         { return ProfessorSprite; };
    sf::Sprite getCompanionSprite()                                         { return CompanionSprite; };
    
    const LessonDialogueGraphics initBGSprite(sf::Texture &);
    const LessonDialogueGraphics initCharacterSprites(sf::Texture &);
    static const sf::Texture initBackground();
    static const sf::Texture initCharacters();
};

int updateGraphics(sf::RenderWindow &, class LessonDialogueGraphics &, std::list<std::pair<int, std::string> > &, sf::Clock &, bool &);

void albertonInput(sf::RenderWindow &, bool &);

static LessonDialogueGraphics MappedLessonDialogueGraphics;

class LessonMainLoop{
public:
    //static void start(std::string);
};

class Commands{
public:
    std::pair<int, std::string> Dialogue;
};

std::list<std::pair<int, std::string> > read(std::string);

#endif /* defined(__AlbertonsLessonBuilder__AlbertonsLessonBuilder__) */
