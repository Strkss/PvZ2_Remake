#include <stdio.h>

#include <SDL.h>
#include "Constants.hpp"
#include "FGrid.hpp"

FGrid::FGrid() {
	row = 0;
	col = 0;
	x = 0;
	y = 0;
	state = GRID_EMPTY;
}

FGrid::FGrid(int r, int c) {
	row = r;
	col = c;
	x = LAWN_START_X + c * LAWN_GRID_WIDTH;
	y = LAWN_START_Y + r * LAWN_GRID_HEIGHT;
	state = GRID_EMPTY;
}