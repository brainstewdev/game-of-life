#include "../include/BaseMathFunctions.hpp"
#include<math.h>

// function to calculate the area of the whole window
int windowArea(int height, int width){
    return height*width;
}
// functions to calculate the area of a single square
int squareArea(int windowArea, int numberOfSquare){
    return windowArea / numberOfSquare;
}
int squareArea(int height, int width, int numberOfSquare){
    return windowArea(height, width) / numberOfSquare;
}
// function that returns the size of the size of the square
float squareSide(int squareArea){
    return sqrt(squareArea);
}
int getSquareCoordinateByMouseCoordinate(int mouseCoordinate, int cellside){
    return ((mouseCoordinate-(mouseCoordinate%cellside))/cellside);
};
