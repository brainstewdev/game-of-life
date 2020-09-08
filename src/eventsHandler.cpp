#include "../include//eventsHandler.hpp"
#include "../include//BaseMathFunctions.hpp"

int handleEvent(sf::Event event, Plane &gamePlane, bool &onPause){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            int selectedy, selectedx;
            selectedx = getSquareCoordinateByMouseCoordinate(event.mouseButton.x, gamePlane.getCellside());
            selectedy = getSquareCoordinateByMouseCoordinate(event.mouseButton.y, gamePlane.getCellside());
            
            gamePlane.setCellAlive(selectedx, selectedy, true);

            return 0;
        } 
        if(event.mouseButton.button == sf::Mouse::Right){
            int selectedy, selectedx;
            selectedx = getSquareCoordinateByMouseCoordinate(event.mouseButton.x, gamePlane.getCellside());
            selectedy = getSquareCoordinateByMouseCoordinate(event.mouseButton.y, gamePlane.getCellside());
            
            gamePlane.setCellAlive(selectedx, selectedy, false);

            return 0;
        } 
    }
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Space){
            onPause = !(onPause);
            return 0;
        }
    }

    return 0;
};
