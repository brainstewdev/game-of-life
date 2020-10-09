# Game Of Life
## the objective
i want to create a version of convey's game of life in its simplest form.
the implementation will be done in c++, with the sfml library for the graphic.
## state of the project
the project is in a very primitive state, but it works as a basic implementation of the game of life.
you can generate a random starting grid or start with a blank one and then fill it by yourself with
mouse click. you can also stop the simulation and restart it by pressing the space key.
with the latest update the plane has been updated and now every border cell communicates with the other opposite border!
## to do:
the project will be maintained and updated so if you have request just open a issue and i'll try to see what i can do to help you.
## the Rules

as from wikipedia:

The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
1. Any live cell with two or three live neighbours lives on to the next generation.
1. Any live cell with more than three live neighbours dies, as if by overpopulation.
1. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.


These rules, which compare the behavior of the automaton to real life, can be condensed into the following:

1. Any live cell with two or three live neighbours survives.
1. Any dead cell with three live neighbours becomes a live cell.
1. All other live cells die in the next generation. Similarly, all other dead cells stay dead.

The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed; births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick. Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations.

## how to use it
if you're on windows then you can download the latest Precompiled binary or you can build it. the choice is yours :)
to compile the program on windows you can use different methods, i usually compile it with the mingw32 gcc compilers
generating the Make file with cmake but you could also use cmake to create a visual studio project.
### linux
if you're on a linux machine (Ubuntu, arch etc.) you need to install [SFML](https://www.sfml-dev.org/index.php) through you packet manager.
if it's not available then you will have to build it by yourself, following the step in their guide.
then you'll need cmake, to generate the project or the makefile.
cmake can be installed through a package manager as well.
then, after you installed SFML and cmake you just need to clone the code of this repository, create a directory (which i usually call build) in the "game-of-life" folder
and then you need to cd into that directory and type these commands in the terminal:
    `cmake ..`, then
    `make`
and to run the program you need to type
    `./GOL`
    and it should work! if it doesn't then you can open a issue on this github page and i'll try to help you.
## windows
on windows i use Visual Studio 2019 to build this project. 
the first step is to check if SFML has prebuilt SDK for your SPECIFIC version of visual studio. 
if it doesn't then you need to build yourself the SDK.
there is a guide on their site to do that, it's pretty straight forward and fast to do ([link to the guide](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php))
after installing the SFML SDK you can clone this repo, and create a folder named build.
you then need to create a CMake project for visual studio. i use the CMake GUI for this but you can also use the CLI.
then you need to open the solution with visual studio, set the additional Include directory and the additional library directory under your project properties page.
you need to set those only if you had built the SFML SDK in a directory and then didn't move the files to the compiler one, for example if you built the SDK in a subdirectory of you user directory.
the last thing you need to do is to try to build the project. if it doesn't work let me know in the issue page and i'll try to help you.
to run the program you need to copy the DLLs of SFML to the folder of your .exe file!
