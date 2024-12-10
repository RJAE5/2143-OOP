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
    sf::Time frameDuration;  // Frame duration (e.g., 100ms per frame)
    int currentFrame;
    int rollValue;


    void update() 
    {
        if (clock.getElapsedTime() >= frameDuration) 
        {
            clock.restart();

            // Advance to the next frame
            currentFrame = (currentFrame + 1) % aniTextures.size();
            sprite.setTexture(aniTextures[currentFrame]);
        }
    }

    void loadAnimation()  
    {
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

            aniTextures.push_back(texture);
        }

        if (!aniTextures.empty()) 
            sprite.setTexture(aniTextures[currentFrame]);
    
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
        loadAnimation();
    }
    

    void rollDiceAnimate(sf::RenderWindow& window)
    {
        update();
        display(window);    
    }

    void startRollAnimation()
    {
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
        rollValue = (rand() % 6) + 1;
    }

    int getRollValue()
    {return rollValue;}

    void setSpriteTexture(int i)
    {sprite.setTexture(textures[i]);}

};