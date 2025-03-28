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

	bool updateGrid(int row, int col, enum GRID_STATES state);
	enum GRID_STATES getGridState(int row, int col) const;
	void render(SDL_Renderer* mRenderer);
	
	// Debug function
	void drawGridHitbox(SDL_Renderer* mRenderer);
};