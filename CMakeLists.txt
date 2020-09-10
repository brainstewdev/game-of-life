cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

# set the debug flag, to be removed with final releases
set(CMAKE_BUILD_TYPE Debug)
# set the release flag, to be removed with debug 
# set(CMAKE_BUILD_TYPE Release)

# take all the files that are inside the src dir and with extension
# .cpp and then put them into the source variable
file(GLOB SOURCE ./src/*.cpp)

# add the executable
add_executable(GOL ${SOURCE})

target_include_directories(GOL PUBLIC "../SFML/include" "./include")

target_link_libraries(GOL sfml-graphics sfml-window sfml-system)