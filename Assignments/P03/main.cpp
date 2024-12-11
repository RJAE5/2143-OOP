#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>

#include "grid.hpp"
#include "uname_input.hpp"
#include "player.hpp"
#include "dice.hpp"
#include "game.hpp"


int main()
{
    // Starter flags
    bool rolling = false;
    bool turn = false;
    bool gameOver = false;

    // Create Game window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Knucklebones");
    window.setFramerateLimit(60);
    sf::Vector2i pos(800.f,250.f);
    window.setPosition(pos);

    // Username input screen
    UnameInput uWin;
    std::string uName = "";
    uWin.getInput(window, uName);

    // Change title for display on main game
    uWin.setTitle();

    // Player, grid, and dice instances
    Player player(uName);
    Grid grid;
    Dice die;
    Game game(grid);

    // Initalize the game elements
    grid.createGrid();
    game.setRollPrompt();

    srand(time(NULL));


    // Main game loop
    while(window.isOpen())
    {
     // Handle events
        sf::Event event;
        while(window.pollEvent(event))
        {
            // Close window handling
            if(event.type == sf::Event::Closed ||
               (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                    window.close();
            // Check for other events if game is still going
            if(!gameOver)
            {
                // Roll operation handling
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !rolling && !turn )
                {
                    die.startRollAnimation();
                    rolling = true;

                }

                // Detect mouse clicks
                else if (event.type == sf::Event::MouseButtonPressed) 
                {
                    if (event.mouseButton.button == sf::Mouse::Left && turn) 
                    {
                        // Get mouse position relative to the window
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        
                        // Flag to ensure a hitbox column is clicked
                        bool colClicked = false;

                        // Check if col's hitboxes was clicked
                        grid.inputGrid(die.getRollValue(), mousePos, colClicked);
                        if(colClicked)
                        {
                            turn = false;
                            game.setRollPrompt();
                            grid.calcScore();
                        }
                    }
                }// End moust button
            }// End if(!gameOver)
        }// End polling event

        // Animate dice roll if currently rolling
        if(rolling)
        {
            die.rollDiceAnimate(window);

            // If the animation has finished
            if (!die.isRolling())
            {
                // Stop the rolling flag
                rolling = false;  
                die.rollForValue();
                die.setSpriteTexture(die.getRollValue() - 1);

                // Enable turn flag
                turn = true;

                // Show prompt to place value
                game.setPlacePrompt();
            }
        }

        // Enter final game state
        if(grid.isFull() && !gameOver)
        {
            gameOver = true;
            game.setGameOverPrompt(grid.getScore());
            game.drawFinalPrompt(window);
        }

    // Draw elements

        // Clear Window off
        window.clear(sf::Color::White);

        // Draw game items
        game.drawPrompt(window);
        game.drawFinalPrompt(window);
        game.drawScore(window, grid.getScore());
        grid.drawGrid(window);
        grid.drawGridText(window);
        die.display(window);
        window.draw(player.getName());
        uWin.drawTitle(window);
        
        // Show window
        window.display();
    }
}