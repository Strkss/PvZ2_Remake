#pragma once

#include <stdio.h>
#include <SDL.h>

#include "Constants.hpp"
#include "FGrid.hpp"

class FLawn {
private:
	const int numRow = 5, numCol = 9;
	FGrid grid[5][9];

public:
	FLawn();
	bool updateGrid(int row, int col, enum GRID_STATE state);
	

	// Debug functions
	void drawGridHitbox(SDL_Renderer* mRenderer);
};
