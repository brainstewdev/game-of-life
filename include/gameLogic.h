#pragma once
#include "./gameClasses.h"
#include <iostream>
// the function used to update the plane
void updatePlane(Plane *);

// a function that counts the number of live cells nearby the cell
// that is in the x, y position. 
int numberOfAliveCellsNearby(Plane * gamePlane, int x, int y);
// function that checks if a targeted cell is inside the plane or it has to be searched in the nearby borders
// of the cell.
bool targetCellInBorder(int widthInCells, int heightInCells, int x, int y);