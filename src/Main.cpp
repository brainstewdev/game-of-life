#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include <string>
#include "../include/BaseMathFunctions.hpp"
#include "../include/gameClasses.hpp"
#include "../include/gameLogic.hpp"
#include "../include/eventsHandler.hpp"
#include "../include/Renderer.hpp"

// the desired height and width of the window
constexpr int WINDOW_HEIGHT = 600;
constexpr int WINDOW_WIDTH  = 800;
// the number of cell to operate
constexpr int CELL_NUMBER  =  7500;

// the main function
int main(int argc, char *argv[]){
    // if the game is on pause then don't update the board
    bool onPause = true;
    bool generate = true;
    // create the window to render on
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game of Life", sf::Style::Close);
    // calculate the cellside, to know how long to make it and to calculate the position
    // of the square in the plane
    float cellSide = squareSide(squareArea(windowArea(WINDOW_HEIGHT, WINDOW_WIDTH), CELL_NUMBER));
    // creates the plane that is going to handle the true game of life, 
    // the rest of it is just to display what is going on
    Plane gamePlane(WINDOW_HEIGHT, WINDOW_WIDTH, CELL_NUMBER);
    // the renderer object basically manages all the graphics
    Renderer renderer(gamePlane, window);
    // the seed used to generate the plane
    int seed = 0;
    // check the flags passed to the program 
    for(int i = 1; i < argc; i++){
        // if the arguments contain the flag -b it means that the user doesn't want to 
        // have the plane generated. if a -s flag is passed it is simply ignored if the 
        // -b flag is passed.
        if(std::string(argv[i]).compare("-b") == 0) generate = false;
        if(std::string(argv[i]).compare("-s") == 0) {
            if(i+1 < argc){
                std::stringstream ss;
                ss << std::string(argv[i+1]);
                // set the seed to the value passed after the -s flag.
                // if the string after the -s flag is an invalid int
                // then set the seed to 0
                ss >> seed; 
            }
        }
    }

    // you can use this to generate a random plane
    if(generate)
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
        renderer.render();
        
        // update the plane using the various logic functions (they can be found in ../include/gameLogic.h)
        if(!(onPause))
            updatePlane(gamePlane);
    }

    return 0;
}
