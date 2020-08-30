#pragma once
#include<math.h>

// function to calculate the area of the whole window
int windowArea(int height, int width);
// functions to calculate the area of a single square
int squareArea(int windowArea, int numberOfSquare);
int squareArea(int height, int width, int numberOfSquare);
// function that returns the size of the size of the square
float squareSide(int squareArea);
// function that returns either the y or the x cell coordinate of the square 
// which the mouse pointer is in
int getSquareCoordinateByMouseCoordinate(int mouseCoordinate, int cellside);