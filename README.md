# Game Of Life
## the target
i want to create a version of convey's game of life in its simplest form.
the implementation will be done in c++, with the sfml library for the graphic.
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
to use the program you need to compile it.
if you're on a linux machine (Ubuntu, arch etc.) you need to install [SFML](https://www.sfml-dev.org/index.php).
you should be available with a package manager but if it's not then you will have to compile it by yourself, following the step in their guide.
then you'll need cmake, to generate the project or the makefile.
cmake can be installed through a package manager.
then, after you installed SFML and cmake you just need to clone the code of this repository, create a directory (which i usually call build) in the "game-of-life" folder
and then you need to cd into that directory and type these commands in the terminal:
    `cmake ..`, then
    `make`
and to run the program you need to type
    `./GOL`
