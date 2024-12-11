#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Game
{
    sf::Text playerDisplayScore;
    sf::Text prompt;
    sf::Text finalPrompt;
    sf::Font font;
    int score;

    Grid gameGrid;

public:

    Game(Grid& grid)
    {
         // Load font
        if (!font.loadFromFile("./media/fonts/arial.ttf")) 
        {
            // Handle error
            std::cerr << "Error loading font!" << std::endl;
        }

        score = 0;

        // Initialize score to be displayed
        playerDisplayScore.setString("Current Score: " + std::to_string(score));
        playerDisplayScore.setFont(font);
        playerDisplayScore.setCharacterSize(24);
        playerDisplayScore.setPosition(775.f, 0.f);
        playerDisplayScore.setFillColor(sf::Color::Blue);

        // Initialize variable prompt
        prompt.setFont(font);
        prompt.setCharacterSize(48);
        prompt.setFillColor(sf::Color::Red);

        // Initialize game ending prompt
        finalPrompt.setFont(font);
        finalPrompt.setCharacterSize(36);
        finalPrompt.setFillColor(sf::Color::White);
        finalPrompt.setPosition(375.f, 675.f);

        // Link grid instance to game
        gameGrid = grid;
    }

    void drawPrompt(sf::RenderWindow& window)
    {window.draw(prompt);}

    void drawFinalPrompt(sf::RenderWindow& window)
    {window.draw(finalPrompt);}

    void setRollPrompt()
    {
        // Roll instance of variable prompt
        prompt.setString("Press Spacebar to roll!");
        prompt.setPosition(250.f, 600.f);
    }

    void setPlacePrompt()
    {
        // Place instance of variable prompt
        prompt.setString("Place value in grid.");
        prompt.setPosition(275.f,600.f);
    }

    void setGameOverPrompt(int s)
    {
        // Initialize variable prompt for game over state
        prompt.setString("GAME OVER");
        prompt.setPosition(350.f,600.f);
        finalPrompt.setString("Final score: " + std::to_string(s));
        finalPrompt.setFillColor(sf::Color::Red);
    }


    void drawScore(sf::RenderWindow& window, int s)
    {
        // Draw sf::Text score
        playerDisplayScore.setString("Current Score: " + std::to_string(s));
        window.draw(playerDisplayScore);
    }
};