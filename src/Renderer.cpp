#include "../include/Renderer.hpp"

Renderer::Renderer(Plane& plane, sf::RenderWindow& _window): gamePlane(plane),window(_window) {
    // creates the square that will be used to draw every alive cell.
    // this allows to use this square and not creating one over and over
    // to improve performance 
    AliveCell = sf::RectangleShape(sf::Vector2f(plane.getCellside(), plane.getCellside()));
    AliveCell.setOutlineColor(sf::Color(255, 0, 0)); 
    AliveCell.setFillColor(sf::Color::Black);
    AliveCell.setOutlineThickness(1.f);
}
// function that clear the window
void Renderer::clearWindow(){
    // clear the window, uses the white color 
    window.clear(sf::Color::White);
}
// function that draws the grid
void Renderer::drawGrid(){
    // creates a vertex array, which will contain the two vertexes of the 
    // horizontal and vertical lines.
    sf::VertexArray vertArray(sf::Lines, 2);
    // proceed to draw the grid
    // draw the vertical lines
    for(int i = 0; i < gamePlane.getWidthInCell(); i++){
        // draw the line going from y = 0 x = gamePlane.getCellside() to the bottom
        vertArray[0] = sf::Vertex(sf::Vector2f(i*gamePlane.getCellside(), 0.0f), sf::Color::Black);
        vertArray[1] = sf::Vertex(sf::Vector2f(i*gamePlane.getCellside(), gamePlane.getCellside()*gamePlane.getHeightInCell()), sf::Color::Black);
        window.draw(vertArray);
    }
    // draw the horizontal lines
    for(int i = 0; i < gamePlane.getHeightInCell(); i++){
        // draw the line going from y = 0 x = gamePlane.getCellside() to the bottom
        vertArray[0] = sf::Vertex(sf::Vector2f(0.0f, i*gamePlane.getCellside()), sf::Color::Black);
        vertArray[1] = sf::Vertex(sf::Vector2f(gamePlane.getCellside()*gamePlane.getWidthInCell(), i*gamePlane.getCellside()), sf::Color::Black);
        window.draw(vertArray);
    }
    // finished drawing the grid
}
void Renderer::renderCells(){
    for(int y = 0; y < gamePlane.getHeightInCell(); y++){
        for(int x = 0; x < gamePlane.getWidthInCell(); x++){
            if(gamePlane.cellIsAlive(x,y)){
                AliveCell.setPosition(x*gamePlane.getCellside(), y*gamePlane.getCellside());
                    // finally, draw the shape!
                window.draw(AliveCell);
            }
        }
    }
}
// function needed to display the drawing made to the window.
// i'm using a function so that if i will need in the future to call
// more functions just before the current frame is displayed i can just
// call them here
void Renderer::displayIt(){
    window.display();
}
void Renderer::render(){
    clearWindow();
    drawGrid();
    renderCells();
    displayIt();
}