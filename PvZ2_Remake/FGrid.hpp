#pragma once
#include <stdio.h>

#include <SDL.h>
#include "Constants.hpp"
#include "FTexture.hpp"

struct FGrid {
	enum GRID_STATES state;
	int row, col;
	int x, y;

	FGrid();
	FGrid(int r, int c);
};