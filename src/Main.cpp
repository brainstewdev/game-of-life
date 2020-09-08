#include <SFML/Graphics.hpp>
#include "../include/BaseMathFunctions.h"
#include "../include/gameClasses.h"
#include "../include/gameLogic.h"
#include "../include/eventsHandler.h"

// the desired height and width of the window
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH  800
// the number of cell to operate
#define CELL_NUMBER 7500

// the main function
int main(){
    // if the game is on pause then don't update for every game cycle
    bool * onPause = new bool(true);
    // create the window to render on
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game of Life");
    // calculate the cellside, to know how long to make it and to calculate the position
    // of the square in the plane
    float cellSide = squareSide(squareArea(windowArea(WINDOW_HEIGHT, WINDOW_WIDTH), CELL_NUMBER));
    // creates the plane that is going to handle the true game of life, 
    // the rest of it is just to display what is going on
    Plane *gamePlane = new Plane(WINDOW_HEIGHT, WINDOW_WIDTH, CELL_NUMBER);

    gamePlane->cellside=cellSide;
    // the seed used to generate the plane
    int seed = 2024234;

    // you can use this to generate a random plane
    gamePlane->generate(seed);    

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
            else
            {
                handleEvent(event, gamePlane, onPause);
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw every single cell, if the cell is alive then draw it
        // black with a red outline, if the cell is dead draw it white with a black 
        // outline
        for(int y = 0; y < gamePlane->getHeightInCell(); y++){
            for(int x = 0; x < gamePlane->getWidthInCell(); x++){
                // draw the current square
                sf::RectangleShape rs(sf::Vector2f(cellSide, cellSide));
                // if the current square is alive in the gamePlan then
                // set its color accordingly
                if(gamePlane->cellIsAlive(x,y)){
                    rs.setFillColor(sf::Color(0,0,0));
                    rs.setOutlineColor(sf::Color(255, 0, 0));
                }else{
                    rs.setOutlineColor(sf::Color(0, 0, 0));
                }
                // set the outline to be of 1 of thickness
                rs.setOutlineThickness(1.f);
                // set the position of the square, to get a 
                // grid. without this command it would just appear to 
                // draw a single square in the position (0,0) 
                rs.setPosition(x*cellSide, y*cellSide);
                // finally, draw the shape!
                window.draw(rs);
            }
        }
        // end the current frame, display what has been drawn
        window.display();
        // update the plane using the various logic functions (they can be found in ../include/gameLogic.h)
        if(!(*onPause))
            updatePlane(gamePlane);
    }

    return 0;
}