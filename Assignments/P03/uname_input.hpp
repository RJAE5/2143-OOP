#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class UnameInput
{
    sf::Font font;

public:

    UnameInput()
    {
        // Load font
        if (!font.loadFromFile("./media/fonts/arial.ttf")) 
        {
            // Handle error
            std::cout << "Error loading font!" << std::endl;
        }
    }

    sf::Text getInput(sf::RenderWindow& window, std::string& userInput)
    {
        bool nameEntered = false;
        
        sf::Text prompt("Please enter your username: ", font, 24);
        prompt.setPosition(300, 100);
        prompt.setFillColor(sf::Color::Red);

        sf::Text uName("", font, 24);
        uName.setFillColor(sf::Color::Green);
        uName.setPosition(300, 150);

        sf::RectangleShape outline(sf::Vector2f(350.f, 50.f));
        outline.setPosition(295.f, 145.f);
        outline.setFillColor(sf::Color::Black);

        while(!nameEntered)
        {
            window.clear(sf::Color::White);

            window.draw(prompt);
            window.draw(outline);
            window.draw(uName);
            

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    nameEntered = true;
                }

                if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == '\b') 
                    {
                        // Handle backspace
                        if (!userInput.empty()) 
                        {userInput.pop_back();}
                    }

                    else if (event.text.unicode == '\r') 
                    {
                        // Handle enter
                        nameEntered = true;
                    } 

                    else if (event.text.unicode < 128) 
                    {
                        // Handle valid characters
                        userInput += static_cast<char>(event.text.unicode);
                    }
                    uName.setString(userInput);
                    
                }

            }
        window.display();  // Update window
        }
    return uName;
    }

};