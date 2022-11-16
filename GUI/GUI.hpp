#pragma once

#include <SFML/Graphics.hpp>

class GUI{

    public:

    // Initializes the graphical user interface with the width and height of the window passed
    // as parameters.
    void drawGui(uint16_t windowWidth, uint16_t windowHeight){
        sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tic-tac-toe");

        // Setting text up
        sf::Text text;
        sf::Font font;
        font.loadFromFile("fonts\\comic.ttf");
        text.setFont(font);
        text.setString("Tic-tac-toe");
        text.setPosition(window.getSize().x*0.02, window.getSize().y - text.getGlobalBounds().height);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Magenta);
        text.setStyle(sf::Text::Bold);

        // Line drawings
        sf::Vertex line1[] = {sf::Vertex(sf::Vector2f(60.f, 10.f)), sf::Vertex(sf::Vector2f(60.f, 160.f))};
        sf::Vertex line2[] = {sf::Vertex(sf::Vector2f(110.f, 10.f)), sf::Vertex(sf::Vector2f(110.f, 160.f))};
        sf::Vertex line3[] = {sf::Vertex(sf::Vector2f(10.f, 60.f)), sf::Vertex(sf::Vector2f(160.f, 60.f))};
        sf::Vertex line4[] = {sf::Vertex(sf::Vector2f(10.f, 110.f)), sf::Vertex(sf::Vector2f(160.f, 110.f))};

        // Run the program as long as the window is open
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // Clears the window
            window.clear();

            // Draws the grid using line primitives
            window.draw(line1, 2, sf::Lines);
            window.draw(line2, 2, sf::Lines);
            window.draw(line3, 2, sf::Lines);
            window.draw(line4, 2, sf::Lines);

            window.draw(text);

            window.display();
        }
    }
};