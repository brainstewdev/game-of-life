#include "./gameLogic.h"

// the main function used to update the plane, which update all of
// the nearbyAliveCells in each cell, and then use the rules to update the board,
// putting the cells in either the alive or dead status
void updatePlane(Plane * gamePlane){
    // scan to count and update the "nearby alive cells" count in each cell
    for(int x = 0; x <= gamePlane->getWidthInCell(); x++){
        for(int y = 0; y <= gamePlane->getHeightInCell(); y++){
            // try to get a pointer to the wanted cell object
            Cell * temp = gamePlane->getCellAt(x,y);
            // check if the cell that the function returned is a valid cell
            if(temp != nullptr){
                // set the variable to the number of alive cell nearby a specific cell
                int nearbyCells = numberOfAliveCellsNearby(gamePlane, x,y);
                // if it is a valid cell then set the number of nerby cell to its cell object
                gamePlane->getCellAt(x,y)->setNearbyAliveCell(nearbyCells);
            }
        }
    }
    // update the live state of each cell based on their nearby cell count
    for(int x = 0; x <= gamePlane->getWidthInCell(); x++){
        for(int y = 0; y <= gamePlane->getHeightInCell(); y++){
            // try to get a pointer the wanted cell object
            Cell * temp = gamePlane->getCellAt(x,y);
            // if the cell object pointer returned buy the getter function is a valid one then:
            if(temp != nullptr){
                // if the cell is currently alive:
                if(temp->isAlive()){
                    // if the cell has fewer than 2 or grater than 3 nearby alive cell then
                    // the cell has to die in the next generation so it's set to dead 
                    // (Cell::Alive = false is equal to dead in my implementation)
                    if(temp->getNearbyAliveCell() < 2 || temp->getNearbyAliveCell() >= 4){
                        temp->setAlive(false);
                    }
                }
                // if the cell is dead :
                else{
                    // if the cell has EXACTLY 3 nearby alive cells then set it to be born
                    // the next generation, giving it life. 
                    if(temp->getNearbyAliveCell() == 3) temp->setAlive(true);
                }
            }
        }
    }
}
// the function used to count how many nearby cells there are in the 3x3 area
// around the cell.
int numberOfAliveCellsNearby(Plane * gamePlane, int x, int y){
    // the counter to keep track of the number of alive cells there are nearby the targeted one
    int count = 0;
    // check the 3x3 area nearby the square to know how many alive square there are
    for(int xOff = -1; xOff < 2; xOff++){
        for(int yOff = -1; yOff < 2; yOff++){
            // if the targeted cell is the current cell then skip it
            if(xOff == 0 && yOff == 0) continue;
            // check that the coordinates to check is within limits
            if(xOff+x < 0 || x + xOff > gamePlane->getWidthInCell()) continue;
            if(yOff+y < 0 || y + yOff > gamePlane->getHeightInCell()) continue;
            // if the targeted cell is alive then add one to the counter
            if(gamePlane->cellIsAlive(x+xOff, y+yOff)){
                count++;
            }
        }
    }
    // return the number of alive cells nearby the selected one
    return count;
}