#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Player
{
    std::string uName;
    sf::Font font;
    sf::Text uNameText;
    
public:
    Player(std::string un)
    {
        // Save username
        uName = un;
        
         // Load font
        if (!font.loadFromFile("./media/fonts/arial.ttf")) 
        {
            // Handle error
            std::cerr << "Error loading font!" << std::endl;
        }

        // Convert username to sf::Text
        uNameText.setString(uName);
        uNameText.setFont(font);
        uNameText.setCharacterSize(24);
        uNameText.setPosition(0,0);
        uNameText.setFillColor(sf::Color::Blue);
    }

    sf::Text getName()
    {
        //return name in sf::Text format
        return uNameText;
    }
};