#pragma once

#include <stdio.h>
#include <SDL.h>

#include "Constants.hpp"
#include "FGrid.hpp"

class FLawn {
private:
	static FGrid grid[LAWN_ROW_NUM][LAWN_COLUMN_NUM];

public:
	static void initGrid();
	static bool updateGrid(int row, int col, enum GRID_STATES state);
	static enum GRID_STATES getGridState(int row, int col);

	// Debug functions
	static void drawGridHitbox(SDL_Renderer* mRenderer);
};
