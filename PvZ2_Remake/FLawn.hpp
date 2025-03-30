#pragma once

#include <stdio.h>
#include <SDL.h>

#include "Constants.hpp"
#include "FGrid.hpp"

extern FTexture lawnTexture;

class FLawn {
private:
	FGrid grid[LAWN_ROW_NUM][LAWN_COLUMN_NUM];
public:
	FLawn();
	~FLawn();

	bool updateGrid(int row, int col, enum GRID_STATES state); // cap nhat trang thai grid (row, col)
	enum GRID_STATES getGridState(int row, int col) const; // lay trang thai grid (row, col)
	void render(SDL_Renderer* mRenderer);
	
	// Debug function
	void drawGridHitbox(SDL_Renderer* mRenderer); // ve hitbox
};