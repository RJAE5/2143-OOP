#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Player
{
    std::string uName;
    sf::Font font;
    
public:
    Player(std::string un)
    {
        uName = un;
        // Load font
        if (!font.loadFromFile("./media/fonts/arial.ttf")) 
        {
            // Handle error
            std::cout << "Error loading font!" << std::endl;
        }

        else 
            std::cout << "Successfully loaded font" << std::endl;
    }

    sf::Text getName()
    {
        static sf::Text uNameText(uName, font, 24);
        uNameText.setPosition(0,0);
        uNameText.setFillColor(sf::Color::Blue);

        return uNameText;
    }


};