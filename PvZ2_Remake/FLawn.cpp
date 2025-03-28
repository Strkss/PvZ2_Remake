#include <stdio.h>
#include <SDL.h>

#include "Constants.hpp"
#include "FLawn.hpp"

FTexture lawnTexture;

FLawn::FLawn() {
	for (int rowI = 0; rowI < LAWN_ROW_NUM; rowI++) {
		for (int colJ = 0; colJ < LAWN_COLUMN_NUM; colJ++) {
			grid[rowI][colJ].row = rowI;
			grid[rowI][colJ].col = colJ;
			grid[rowI][colJ].x = LAWN_START_X + colJ * LAWN_GRID_WIDTH;
			grid[rowI][colJ].y = LAWN_START_Y + rowI * LAWN_GRID_HEIGHT;
			grid[rowI][colJ].state = GRID_EMPTY;
		}
	}
}

FLawn::~FLawn() { }

bool FLawn::updateGrid(int row, int col, enum GRID_STATES state) {
	grid[row][col].state = state;
	printf("DONE: updateGrid %d %d\n", row, col);
	return 1;
}

enum GRID_STATES FLawn::getGridState(int row, int col) const {
	return grid[row][col].state;
}

void FLawn::render(SDL_Renderer* mRenderer) {
	lawnTexture.renderAtPosition(mRenderer, -10, 0);
#ifdef DEBUG_HITBOX
	drawGridHitbox(mRenderer);
#endif	
}

//Debug function
void FLawn::drawGridHitbox(SDL_Renderer* mRenderer) {
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0);
	for (int rowI = 0; rowI < LAWN_ROW_NUM; rowI++) {
		for (int colJ = 0; colJ < LAWN_COLUMN_NUM; colJ++) {
			SDL_Rect renderRect = { grid[rowI][colJ].x, grid[rowI][colJ].y, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT };
			SDL_RenderDrawRect(mRenderer, &renderRect);
		}
	}
}