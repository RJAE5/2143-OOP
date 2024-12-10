#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Grid
{
    int rows;
    int cols;
    float cellSize;     // Width and height of each cell
    float gridStartX;   // Starting X position of the grid
    float gridStartY;   // Starting Y position of the grid
    float cellSpacing;  // Spacing between cells

    float hitColSizeX;  // Width of each column hitbox
    float hitColSizeY;  // Height of each column hitbox
    float hitColStartX; // StartX of first column hitbox
    float hitColStartY; // StartY of first column hitbox

    // Hitboxes
    sf::RectangleShape col1;
    sf::RectangleShape col2;
    sf::RectangleShape col3;

    // Grid structure and value columns
    std::vector<sf::RectangleShape> grid;
    sf::RectangleShape cell;
    std::vector<sf::Text> gridVals1;
    std::vector<sf::Text> gridVals2;
    std::vector<sf::Text> gridVals3;
    sf::Text value;
    sf::Font font;


    void initGridValsPos(std::vector<sf::Text>& colVals, int col)
    {
        int offset;
        switch(col)
        {
            case 1 :  offset = 0; break;  
            case 2 :  offset = 110; break;
            case 3 :  offset = 220; break;
        }

        for (int i = 0; i < colVals.size(); i++)
        {
            // Centering text horizontally within column
            float x = hitColStartX + offset + hitColSizeX / 2 - (colVals[i].getLocalBounds().width / 2);  

            // Calculate vertical position based on index i
            float y = hitColStartY + (2 - i) * (hitColSizeY / 3) + 50;  // Vertical adjustment

            // Apply position
            colVals[i].setPosition(x, y);
        } 
    }



public:
    Grid()
    {
        rows = 3;
        cols = 3;
        cellSize = 100.f;
        gridStartX = 325.f;
        gridStartY = 100.f;
        cellSpacing = 10.f;

        hitColSizeX = 100.f;
        hitColSizeY = 320.f;
        hitColStartX = 325.f;
        hitColStartY = 100.f;


        col1.setSize(sf::Vector2f(hitColSizeX, hitColSizeY));
        col1.setPosition(hitColStartX, hitColStartY);
        col1.setFillColor(sf::Color::Blue);

        col2.setSize(sf::Vector2f(hitColSizeX, hitColSizeY));
        col2.setPosition(hitColStartX + 110, hitColStartY);
        col2.setFillColor(sf::Color::Red);

        col3.setSize(sf::Vector2f(hitColSizeX, hitColSizeY));
        col3.setPosition(hitColStartX + 220, hitColStartY);
        col3.setFillColor(sf::Color::Green);

        value.setCharacterSize(24);

        // Load font
        if (!font.loadFromFile("./media/fonts/arial.ttf")) 
        {
            // Handle error
            std::cout << "Error loading font!" << std::endl;
        }

        value.setFont(font);
        value.setFillColor(sf::Color::Red);

    }

    void createGrid()
    {
        // Create the grid cells
        for (int row = 0; row < rows; ++row) 
        {
            for (int col = 0; col < cols; ++col) 
            {
                cell.setSize(sf::Vector2f(cellSize, cellSize));
                cell.setFillColor(sf::Color::White);
                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(6.f);

                // Calculate cell position
                float x = gridStartX + col * (cellSize + cellSpacing);
                float y = gridStartY + row * (cellSize + cellSpacing);
                cell.setPosition(x, y);

                // Add the cell to the grid
                grid.push_back(cell);
            }
        }
    }

    void drawGrid(sf::RenderWindow& window)
    {
        for (const auto& cell : grid) 
        {window.draw(cell);}
    }

    void drawBounds(sf::RenderWindow& window)
    {
        window.draw(col1);
        window.draw(col2);
        window.draw(col3);
    }

    void drawGridVals(sf::RenderWindow& window)
    {
        for (const auto& value : gridVals1) 
        {window.draw(value);}

        for (const auto& value : gridVals2) 
        {window.draw(value);}

        for (const auto& value : gridVals3) 
        {window.draw(value);}
    }

    void inputGrid(int val, sf::Vector2i mousePos, bool& colClicked)
    {
        value.setString(std::to_string(val));

        // Might reverse order of these conditionals to restrict access to non-full columns
        if (col1.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) 
        {
            if(gridVals1.size() < 3)
                gridVals1.push_back(value);

            initGridValsPos(gridVals1, 1);
            colClicked = true;
        } 

        if (col2.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            if(gridVals2.size() < 3)
                gridVals2.push_back(value);

             initGridValsPos(gridVals2, 2);
             colClicked = true;
        }

        
        if (col3.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            if(gridVals3.size() < 3)
                gridVals3.push_back(value);

            initGridValsPos(gridVals3, 3);
            colClicked = true;
        }
  
    }
};