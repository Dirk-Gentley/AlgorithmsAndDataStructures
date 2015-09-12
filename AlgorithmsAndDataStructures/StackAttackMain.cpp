#include "ResourcePath.hpp"

void beginStackAttack(sf::RenderWindow &window){
    
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "stackAttackBack1024.png")) {
        return;
    }
    sf::Sprite sprite(texture);
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return;
    }
    
    std::vector<sf::Text> myText(4);
    myText[0].setString("Input:"); myText[0].setPosition(float(672), float(51.2));
    myText[1].setString("Output:"); myText[1].setPosition(float(672), float(563.2));
    
    for (int i = 0; i < myText.size(); i++) {
        myText[i].setFont(font);
        myText[i].setCharacterSize(32);
        myText[i].setColor(sf::Color::White);
    }
    
    const int MAXSTACK = 6;
    std::deque<char> inputQ;
    std::deque<char> stack1;
    std::deque<char> stack2;
    std::deque<char> outputQ;
    std::deque<char> solution;
    std::deque<char> undo;
    
    std::srand((unsigned int)time(0));
    // Initialise
    init(inputQ, stack1, stack2, outputQ, solution, undo);
    
    // Start the game loop
    while (window.isOpen()){
        // Process events
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                return;
            }
            
            // Pop from input to S1 (i)
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
                // popInput
                if (inputQ.size() > 0 && stack1.size() < MAXSTACK) {
                    char temp = inputQ.front();
                    stack1.push_back(temp);
                    inputQ.pop_front();
                    undo.push_back('i');
                }
            }
            
            // Pop from S1 to S2 (o)
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O) {
                // popS1->S2
                if (stack1.size() > 0 && stack2.size() < MAXSTACK) {
                    char temp = stack1.back();
                    stack2.push_back(temp);
                    stack1.pop_back();
                    undo.push_back('o');
                }
            }
            
            // Pop from S2 to Output (p)
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                // popS2->Output
                if (stack2.size() > 0 && outputQ.size() < solution.size()) {
                    char temp = stack2.back();
                    outputQ.push_back(temp);
                    stack2.pop_back();
                    undo.push_back('p');
                }
            }
            
            // Undo last move (z)
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z) {
                if (undo.size() > 0) {
                    char lastMove = undo.back();
                    char temp;
                    switch (lastMove) {
                        case 'i':
                            temp = stack1.back();
                            inputQ.push_front(temp);
                            stack1.pop_back();
                            break;
                        case 'o':
                            temp = stack2.back();
                            stack1.push_back(temp);
                            stack2.pop_back();
                            break;
                        case 'p':
                            temp = outputQ.back();
                            stack2.push_back(temp);
                            outputQ.pop_back();
                            break;
                        default:
                            break;
                    }
                    undo.pop_back();
                }
            }
            
            // Restart Stack Attack (r)
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                init(inputQ, stack1, stack2, outputQ, solution, undo);
            }
        }
        
        // Clear screen
        window.clear();
        
        // Draw the sprite
        window.draw(sprite);
        
        drawQueue(window, font, inputQ, 704, 115.2);
        drawOutput(window, font, outputQ, solution, 704, 627.2);
        drawQueue(window, font, solution, 704, 691.2);
        
        drawStack(window, font, stack1, 128, 480);
        drawStack(window, font, stack2, 419.2, 480);
        
        // Draw the strings
        for (int i = 0; i < myText.size(); i++) {
            window.draw(myText[i]);
        }

        // Update the window
        window.display();
    }
    return;
}

void drawQueue(sf::RenderWindow &window, sf::Font &font, std::deque<char> q, int x, int y) {
    for (int i = 0;  i < q.size(); i++) {
        sf::RectangleShape box(sf::Vector2f(32, 32));
        box.setFillColor(sf::Color::Transparent);
        box.setOutlineThickness(3);
        box.setOutlineColor(sf::Color::White);
        box.setPosition(x+(i*45), y);
        window.draw(box);
        
        sf::Text text(q[i], font, 32);
        text.setColor(sf::Color::White);
        text.setPosition(x+(i*45)+4, y-4);
        window.draw(text);
    }
}

void drawStack(sf::RenderWindow &window, sf::Font &font, std::deque<char> q, int x, int y) {
    for (int i = 0;  i < q.size(); i++) {
        sf::RectangleShape box(sf::Vector2f(32, 32));
        box.setFillColor(sf::Color::Transparent);
        box.setOutlineThickness(3);
        box.setOutlineColor(sf::Color::White);
        box.setPosition(x, y-(i*45));
        window.draw(box);
        
        sf::Text text(q[i], font, 32);
        text.setColor(sf::Color::White);
        text.setPosition(x+4, y-4-(i*45));
        window.draw(text);
    }
}

void drawOutput(sf::RenderWindow &window, sf::Font &font, std::deque<char> q, std::deque<char> solution, int x, int y) {
    for (int i = 0;  i < q.size(); i++) {
        sf::RectangleShape box(sf::Vector2f(32, 32));
        box.setFillColor(sf::Color::Transparent);
        box.setOutlineThickness(3);
        if (q[i] == solution[i]) {
            box.setOutlineColor(sf::Color::Green);
        } else {
            box.setOutlineColor(sf::Color::Red);
        }
        box.setPosition(x+(i*45), y);
        window.draw(box);
        
        sf::Text text(q[i], font, 32);
        text.setColor(sf::Color::White);
        text.setPosition(x+(i*45)+4, y-4);
        window.draw(text);
    }
}

void shuffle(std::deque<char> &seq) {
    int rnd1; int rnd2; char swap;
    for (int i = 0; i < seq.size()*2; i++) {
        rnd1 = rand() % seq.size();
        rnd2 = rand() % seq.size();
        swap = seq[rnd1];
        seq[rnd1] = seq[rnd2];
        seq[rnd2] = swap;
    }
}

void init(std::deque<char> &inputQ, std::deque<char> &stack1,
          std::deque<char> &stack2,std::deque<char> &outputQ,
          std::deque<char> &solution, std::deque<char> &undo) {
    inputQ.clear(); // Clear all deques
    stack1.clear();
    stack2.clear();
    outputQ.clear();
    solution.clear();
    undo.clear();
    
    inputQ.push_back('A'); // Push elements to inputQ
    inputQ.push_back('B'); // in the order desired for
    inputQ.push_back('C'); // the solution
    inputQ.push_back('D');
    inputQ.push_back('E');
    inputQ.push_back('F');
    solution = inputQ;
    shuffle(inputQ);
}
