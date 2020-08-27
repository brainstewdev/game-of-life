cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

# add the executable
add_executable(GOL ./src/Main.cpp)
target_link_libraries(GOL sfml-graphics sfml-window sfml-system)