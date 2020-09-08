#include <SFML/Graphics.hpp>
#include "../include/BaseMathFunctions.hpp"
#include "../include/gameClasses.hpp"
#include "../include/gameLogic.hpp"
#include "../include/eventsHandler.hpp"

// the desired height and width of the window
constexpr int WINDOW_HEIGHT = 600;
constexpr int WINDOW_WIDTH  = 800;
// the number of cell to operate
constexpr int CELL_NUMBER  =  7500;

// the main function
int main(){
    // if the game is on pause then don't update the board
    bool onPause = true;
    // create the window to render on
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game of Life");
    // calculate the cellside, to know how long to make it and to calculate the position
    // of the square in the plane
    float cellSide = squareSide(squareArea(windowArea(WINDOW_HEIGHT, WINDOW_WIDTH), CELL_NUMBER));
    // creates the plane that is going to handle the true game of life, 
    // the rest of it is just to display what is going on
    Plane gamePlane(WINDOW_HEIGHT, WINDOW_WIDTH, CELL_NUMBER);

    // the seed used to generate the plane
    int seed = 2024234;

    // you can use this to generate a random plane
    gamePlane.generate(seed);    

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
        // pre create a dead cell
        sf::RectangleShape DeadCell(sf::Vector2f(cellSide, cellSide));
        DeadCell.setFillColor(sf::Color::White);
        DeadCell.setOutlineColor(sf::Color(0, 0, 0));  
        DeadCell.setOutlineThickness(1.f);
        // pre create a live cell
        sf::RectangleShape AliveCell(sf::Vector2f(cellSide, cellSide));
        AliveCell.setOutlineColor(sf::Color(255, 0, 0)); 
        AliveCell.setFillColor(sf::Color::Black);
        AliveCell.setOutlineThickness(1.f);
        for(int y = 0; y < gamePlane.getHeightInCell(); y++){
            for(int x = 0; x < gamePlane.getWidthInCell(); x++){
                sf::RectangleShape * currentCell;
                if(gamePlane.cellIsAlive(x,y)){
                    currentCell = &AliveCell;
                }else{
                    currentCell = &DeadCell;
                }
                currentCell->setPosition(x*cellSide, y*cellSide);
                // finally, draw the shape!
                window.draw(*currentCell);
            }
        }
        // end the current frame, display what has been drawn
        window.display();
        // update the plane using the various logic functions (they can be found in ../include/gameLogic.h)
        if(!(onPause))
            updatePlane(gamePlane);
    }

    return 0;
}