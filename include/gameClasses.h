#pragma once
#include "./BaseMathFunctions.h"

// the Cell object is the rapresentation of the single cell inside the game of
// life. it also can be thought of as one of the square in the grid.
// it can be either dead or alive
class Cell{
private:
    bool Alive = true;
public:
    // isAlive getter and setter
    bool isAlive();
    void setAlive(bool);
};

// the Plane class contains a rapresentation of a 
// grid which contains all of the Cells object.
// it also handles the logic of the game.
class Plane{
private:
    Cell **cellMatrix;
public:
    // constructor function
    Plane(int win_height, int win_width, int cell_numb);
    // destructor function
    ~Plane();
    // basic setter and getter functions for accessing the single squares
    void setCellAlive(int, int);
    bool cellIsAlive(int , int );
};
