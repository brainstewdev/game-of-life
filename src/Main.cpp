#include <SFML/Graphics.hpp>
#include "../include/BaseMathFunctions.h"
#include<iostream>

using namespace std;


#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH  800

#define CELL_NUMBER 7500

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game of Life");
    
    float cellSide = squareSide(squareArea(windowArea(WINDOW_HEIGHT, WINDOW_WIDTH), CELL_NUMBER));
    cout << "lato quad: " << cellSide << endl;
    cout << "WINDOW_WIDTH/cellSide: " << WINDOW_WIDTH/cellSide << endl;
    cout << " WINDOW_HEIGHT/ cellSide: " <<  WINDOW_HEIGHT/ cellSide << endl;
   
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        
        int counter = 0;
        for(int y = 0; y < WINDOW_HEIGHT / cellSide; y++){
            for(int x = 0; x < WINDOW_WIDTH / cellSide; x++){
                sf::RectangleShape rs(sf::Vector2f(cellSide, cellSide));
                rs.setOutlineThickness(1.f);
                rs.setOutlineColor(sf::Color(0, 0, 0));

                rs.setPosition(x*cellSide, y*cellSide);
                window.draw(rs);

                counter++;
            }
        }

        // end the current frame
        window.display();
    }

    return 0;
}