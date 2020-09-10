#include "../include/gameClasses.hpp"
#include<cstdlib>

// functions used for the Cell class
bool Cell::isAlive(){ return Alive; };
void Cell::setAlive(bool live){ Alive = live; };

int Cell::getNearbyAliveCell() {return nearbyAliveCells; };
void Cell::setNearbyAliveCell(int numberOfNearbyAliveCells) { if(numberOfNearbyAliveCells >= 0) nearbyAliveCells = numberOfNearbyAliveCells; };

// function used for the Plane class
Plane::Plane(int win_height, int win_width, int cell_numb){
    cellside = squareSide(squareArea(windowArea(win_height, win_width), cell_numb)); 
    // set the "dimension variable" to correct values
    widthInCell = win_width / cellside;
    heightInCell = win_height/(int) cellside;
    // create all the cells
    for(int x = 0; x < widthInCell; x++){
        std::vector<Cell> temp;
        Cell tempCell; tempCell.setAlive(false);
        // add every cell to the vertical columns
        for(int y = 0; y < heightInCell; y++){
            temp.push_back(tempCell);
        }
        // add the vertical column to the vector.
        cellMatrix.push_back(temp);
    }
}

void Plane::generate(int seed){
    srand(seed);

    for(int x = 0; x < widthInCell; x++){
        for(int y = 0; y < heightInCell; y++){
            if(rand() % 5 + 1 == 1) setCellAlive(x, y, true);
        }
    }
}

int Plane::getCellside()    {   return cellside;    };
void Plane::setCellside(int cellside) { if(cellside>0) this->cellside = cellside;   };

Cell * Plane::getCellAt(int x, int y) {
    if((x < getWidthInCell()  && x>=0) && (y < getHeightInCell() && y >= 0)) 
        return &Plane::cellMatrix.at(x).at(y); 
    else 
        return nullptr; 
}

void Plane::setCellAlive(int x, int y, bool value) { 
    if(x < widthInCell && y < widthInCell && x >= 0 && y >= 0)
        cellMatrix.at(x).at(y).setAlive(value); 
}
bool Plane::cellIsAlive(int x, int y) { return getCellAt(x,y)->isAlive(); }

int Plane::getHeightInCell(){ return heightInCell; };
int Plane::getWidthInCell() { return widthInCell; };
