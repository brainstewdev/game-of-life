#include "./gameClasses.h"

// functions used for the Cell class
bool Cell::isAlive(){ return Alive; };
void Cell::setAlive(bool live){ Alive = live; };
// function used for the Plane class
Plane::Plane(int win_height, int win_width, int cell_numb){
    float *temp = new float(squareSide(squareArea(windowArea(win_height, win_width), cell_numb)));
    // int * calc_dim = new int((win_width/ *temp)*(win_height/ *temp));
    
    cellMatrix = new Cell*[win_width / (int)*temp];

    for(int x = 0; x < win_width/ *temp; x++)
        cellMatrix[x] = new Cell[win_height / (int)*temp];
    // free the memory
    delete temp;
}
Plane::~Plane(){
    delete cellMatrix;
}
void Plane::setCellAlive(int x, int y) { cellMatrix[x][y].setAlive(true); }
bool Plane::cellIsAlive(int x, int y) { return cellMatrix[x][y].isAlive(); }
