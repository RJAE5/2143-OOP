#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Dice
{
    // Dice Variables
    std::vector<sf::Texture> textures;
    sf::Sprite sprite;

    // Animation variables
    std::vector<sf::Texture> aniTextures;
    sf::Sprite aniSprite;
    sf::Clock clock;
    sf::Time frameDuration;
    int currentFrame;
    int rollValue;


    void update() 
    {
        // Check for frame time
        if (clock.getElapsedTime() >= frameDuration) 
        {
            // Reset clock
            clock.restart();

            // Advance to the next frame
            currentFrame = (currentFrame + 1) % aniTextures.size();
            sprite.setTexture(aniTextures[currentFrame]);
        }
    }

    void loadAnimation()  
    {
        // Initialize animation variables
        frameDuration = sf::milliseconds(25);
        currentFrame = 0;

        // Load textures
        for (int i = 1; i <= 24; ++i) 
        {
            sf::Texture texture;
            std::string prefix = (i < 10) ? "00" : "0";
            std::string filename = "frame_" + prefix + std::to_string(i) + ".png";

            if (!texture.loadFromFile("./media/animations/dice_roll/" + filename)) 
                std::cerr << "Error loading " << filename << std::endl;

            // Store in vector for easy playback
            aniTextures.push_back(texture);
        }

        // Set beginning frame
        if (!aniTextures.empty()) 
            sprite.setTexture(aniTextures[currentFrame]);
    
        // Location of bottom middle
        sprite.setPosition(400.f, 700.f);
    }

public:

    Dice()
    {
        // Load dice frames onto textures
        for(int i = 1; i <= 6; ++i) 
        { 
            // Assume dice frames are named frame1.png to frame6.png
            sf::Texture texture;
            if (!texture.loadFromFile("./media/images/frame" + std::to_string(i) + ".png")) 
                std::cerr << "Error loading frame" << i << ".png" << std::endl;

            textures.push_back(texture);
        }

        sprite.setPosition(400.f, 700.f);

        // Load animation frames
        loadAnimation();
    }
    
    void rollDiceAnimate(sf::RenderWindow& window)
    {
        // Update animation and display to window
        update();
        display(window);    
    }

    void startRollAnimation()
    {
        // Initialize animation preconditions
        clock.restart();
        currentFrame = 0;
        sprite.setTexture(aniTextures[currentFrame]);
    }

    bool isRolling() const
    {return currentFrame < aniTextures.size() - 1;}

    void display(sf::RenderWindow& window)
    {window.draw(sprite);}

    void rollForValue()
    {
        // Get actual dice value
        rollValue = (rand() % 6) + 1;
    }

    int getRollValue()
    {return rollValue;}

    void setSpriteTexture(int i)
    {sprite.setTexture(textures[i]);}

};