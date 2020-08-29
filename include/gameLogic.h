#pragma once
#include "./gameClasses.h"

// the function used to update the plane
void updatePlane(Plane *);

// a function that counts the number of live cells nearby the cell
// that is in the x, y position. 
int numberOfAliveCellsNearby(Plane * gamePlane, int x, int y);