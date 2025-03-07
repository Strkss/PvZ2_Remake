#include <stdio.h>
#include <SDL.h>

#include "Constants.hpp"
#include "FLawn.hpp"

FGrid FLawn::grid[5][9];

void FLawn::initGrid() {
	for (int rowI = 0; rowI < numRow; rowI++) {
		for (int colJ = 0; colJ < numCol; colJ++) {
			grid[rowI][colJ].row = rowI;
			grid[rowI][colJ].col = colJ;
			grid[rowI][colJ].x = LAWN_START_X + colJ * LAWN_GRID_WIDTH;
			grid[rowI][colJ].y = LAWN_START_Y + rowI * LAWN_GRID_HEIGHT;
			grid[rowI][colJ].state = GRID_EMPTY;
		}
	}
}

bool FLawn::updateGrid(int row, int col, enum GRID_STATES state) {
	grid[row][col].state = state;
	
	switch (state) {
	case GRID_PEASHOOTER:
		break;
	case GRID_SUNFLOWER:
		break;
	case GRID_POTATOMINE:
		break;
	case GRID_WALLNUT:
		break;
	case GRID_EMPTY:
		break;
	}

	printf("DONE: updateGrid %d %d\n", row, col);
	return 1;
}

// Debug functions
void FLawn::drawGridHitbox(SDL_Renderer* mRenderer) {
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0);
	for (int rowI = 0; rowI < numRow; rowI++) {
		for (int colJ = 0; colJ < numCol; colJ++) {
			SDL_Rect renderRect = { grid[rowI][colJ].x, grid[rowI][colJ].y, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT };
			SDL_RenderDrawRect(mRenderer, &renderRect);
		}
	}
}