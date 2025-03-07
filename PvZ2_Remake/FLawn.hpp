#pragma once

#include <stdio.h>
#include <SDL.h>

#include "Constants.hpp"
#include "FGrid.hpp"

class FLawn {
private:
	const static int numRow = 5, numCol = 9;
	static FGrid grid[5][9];

public:
	static void initGrid();
	static bool updateGrid(int row, int col, enum GRID_STATES state);
	

	// Debug functions
	static void drawGridHitbox(SDL_Renderer* mRenderer);
};
