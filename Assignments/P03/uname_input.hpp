#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class UnameInput
{
    sf::Text prompt;
    sf::Text credit;
    sf::Text uName;
    sf::Text title;
    sf::Font font;

    sf::RectangleShape outline;

    bool nameEntered;

public:

    UnameInput()
    {
        // Load font
        if (!font.loadFromFile("./media/fonts/arial.ttf")) 
        {
            // Handle error
            std::cerr << "Error loading font!" << std::endl;
        }

        // Initialize Title
        title.setString("Knucklebones");
        title.setFont(font);
        title.setCharacterSize(70);
        title.setPosition(275, 300);
        title.setFillColor(sf::Color::Cyan);

        // Initialize Credit
        credit.setString("By Rykir Evans");
        credit.setFont(font);
        credit.setCharacterSize(60);
        credit.setPosition(275, 500);
        credit.setFillColor(sf::Color::Magenta);

        // Initialize Prompt
        prompt.setString("Please enter your username below:");
        prompt.setFont(font);
        prompt.setCharacterSize(24);
        prompt.setPosition(300, 100);
        prompt.setFillColor(sf::Color::Black);

        // Initalize uName
        uName.setString("");
        uName.setFont(font);
        uName.setCharacterSize(24);
        uName.setFillColor(sf::Color::Green);
        uName.setPosition(300, 150);

        // Outline for aesthetics
        outline.setSize(sf::Vector2f(350.f, 50.f));
        outline.setPosition(295.f, 145.f);
        outline.setFillColor(sf::Color::Black);

        nameEntered = false;
    }

    void setTitle()
    {
        title.setCharacterSize(48);
        title.setPosition(350, 475);
    }
    void drawTitle(sf::RenderWindow& window)
    {
        window.draw(title);
    }

    // Establish username input game state
    sf::Text getInput(sf::RenderWindow& window, std::string& userInput)
    {
        while(!nameEntered)
        {
            // Start with blank window
            window.clear(sf::Color::White);

            // Draw uname input items
            window.draw(title);
            window.draw(credit);
            window.draw(prompt);
            window.draw(outline);
            window.draw(uName);
            
            // Listen for events
            sf::Event event;
            while (window.pollEvent(event))
            {
                // Handle window closing
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    nameEntered = true;
                }

                // Capture input
                if (event.type == sf::Event::TextEntered)
                {
                     // Handle backspace
                    if (event.text.unicode == '\b') 
                    {
                        if (!userInput.empty()) 
                        {userInput.pop_back();}
                    }
                    // Handle enter
                    else if (event.text.unicode == '\r') 
                    {
                        nameEntered = true;
                    } 
                    // Handle valid characters
                    else if (event.text.unicode < 128) 
                    {
                        userInput += static_cast<char>(event.text.unicode);
                    }

                    // Convert user input to sf::Text string
                    uName.setString(userInput); 
                }// End text event listening

            }// End listening for events

        // Update window
        window.display();
        } // End user input game state

    return uName;
    }
};