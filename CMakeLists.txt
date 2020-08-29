cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

# set the debug flag, to be removed with final releases
# set(CMAKE_BUILD_TYPE Debug)

# add the executable
add_executable(GOL ./src/Main.cpp ./include/BaseMathFunctions ./include/gameClasses ./include/gameLogic)
target_link_libraries(GOL sfml-graphics sfml-window sfml-system)

