#include "./gameClasses.h"
#include<stdlib.h>

// functions used for the Cell class
bool Cell::isAlive(){ return Alive; };
void Cell::setAlive(bool live){ Alive = live; };

int Cell::getNearbyAliveCell() {return nearbyAliveCells; };
void Cell::setNearbyAliveCell(int numberOfNearbyAliveCells) { if(numberOfNearbyAliveCells >= 0) nearbyAliveCells = numberOfNearbyAliveCells; };

// function used for the Plane class
Plane::Plane(int win_height, int win_width, int cell_numb){
    float *temp = new float(squareSide(squareArea(windowArea(win_height, win_width), cell_numb)));
    // set the "dimension variable" to correct values
    widthInCell = win_width/(int) *temp;
    heightInCell = win_height/(int) *temp;
    // this means that cellMatrix has a lenght of 99!
    cellMatrix = new Cell*[widthInCell];
    for(int x = 0; x < widthInCell; x++){
        // this means that every element in cellMatrix[] has a lenght of heightInCell
        cellMatrix[x] = new Cell[heightInCell];
    }
    // free the memory
    delete temp;
}
Plane::~Plane(){
    delete cellMatrix;
}
void Plane::generate(int seed){
    srand(seed);

    for(int x = 0; x < widthInCell; x++){
        for(int y = 0; y < heightInCell; y++){
            if(rand() % 5 + 1 == 1) setCellAlive(x, y, true);
        }
    }
}

Cell * Plane::getCellAt(int x, int y) {if((x < getWidthInCell()  && x>=0) && (y < getHeightInCell() && y >= 0)) return &Plane::cellMatrix[x][y]; else return nullptr; }

void Plane::setCellAlive(int x, int y, bool value) { cellMatrix[x][y].setAlive(value); }
bool Plane::cellIsAlive(int x, int y) { return getCellAt(x,y)->isAlive(); }

int Plane::getHeightInCell(){ return heightInCell; };
int Plane::getWidthInCell() { return widthInCell; };
