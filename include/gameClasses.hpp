#pragma once
#include "./BaseMathFunctions.hpp"

// the Cell object is the rapresentation of the single cell inside the game of
// life. it also can be thought of as one of the square in the grid.
// it can be either dead or alive
class Cell{
private:
    bool Alive = false;
    int nearbyAliveCells = 0;
public:
    // isAlive getter and setter
    bool isAlive();
    void setAlive(bool);
    // getter and setter for the nearbyAliveCells variable
    void setNearbyAliveCell(int num);
    int getNearbyAliveCell();
};

// the Plane class contains a rapresentation of a 
// grid which contains all of the Cells object.
// it also handles the logic of the game.
class Plane{
private:
    int widthInCell, heightInCell;
    Cell **cellMatrix;
    int cellside;
public:
    // constructor function
    Plane(int win_height, int win_width, int cell_numb);
    // destructor function
    ~Plane();
    // generate the Plane
    void generate(int);
    // basic setter and getter functions for accessing the single squares
    void setCellAlive(int x, int y, bool);
    bool cellIsAlive(int , int );
    // getter to get a pointer to a spacific cell
    Cell * getCellAt(int x, int y);
    // getters for the dimension variable
    int getWidthInCell();
    int getHeightInCell();
    int getCellside();
    void setCellside(int cellside);
};
