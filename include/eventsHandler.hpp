#pragma once
#include "./gameClasses.hpp"
#include<SFML/Window.hpp>
// function used to handle events like a mouse button press
int handleEvent(sf::Event, Plane&, bool &onPause);
