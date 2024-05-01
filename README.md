# Conway's Game of Life

This is a very simple implementation of the cellular automaton devised by John Conway in 1970. The rules are simple:
- Any live cell with fewer than two live neighbours dies, as if by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

To execute the program, clone the repository and navigate to it, then run the following command:
```bash
make && ./game_of_life
```
This will run the simulation in a default sized grid (100x50). If you want to run it in a different sized grid, you can pass the width and height as arguments to the program:
```bash
./game_of_life 50 50
```
Finally, you can also pass a pattern file in a `.rle` format inside the `patterns` directory to the program. For example:
```bash
./game_of_life 50 50 patterns/glider.rle
```
The program will then run the simulation with the specified pattern.

## Note: currently, the patterns don't fully work.
## Also, the borders of the grid don't wrap around, meaning that cells on the edge consider "cells" outside of the grid as dead cells.