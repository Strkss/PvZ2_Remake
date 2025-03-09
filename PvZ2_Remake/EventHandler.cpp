#include <stdio.h>
#include <SDL.h>

#include "EventHandler.hpp"
#include "Constants.hpp"
#include "FPeashooter.hpp"
#include "FLawn.hpp"

static enum PLANTS chosen = NONE;
static bool shovelChosen = false;

bool findGrid(int& x, int& y, int& row, int& col) {
	x -= LAWN_START_X;
	y -= LAWN_START_Y;
	if (x < 0 || y < 0 || x > LAWN_END_X || y > LAWN_END_Y) return 0;
	col = x / LAWN_GRID_WIDTH;
	row = y / LAWN_GRID_HEIGHT;
	if (col >= LAWN_COLUMN_NUM || row >= LAWN_ROW_NUM) return 0;
	return 1;
}

void handleEvent(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_1:
			if (chosen == PEASHOOTER) chosen = NONE;
			else chosen = PEASHOOTER;
			shovelChosen = false;
			break;
		case SDLK_q:
			if (shovelChosen) shovelChosen = false;
			else shovelChosen = true;
			chosen = NONE;
			break;
		}
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.key.repeat == 0) {
		int row = 0, col = 0;
		int x = 0, y = 0;
		SDL_GetMouseState(&x, &y);
		if (findGrid(x, y, row, col)) {
			switch (chosen) {
			case NONE:
				break;
			case PEASHOOTER:
				if (FLawn::getGridState(row, col) == GRID_EMPTY) {
					FPeashooter* myPea = new FPeashooter(row, col);
				}
				break;
			}
			if (shovelChosen) {
				switch (FLawn::getGridState(row, col)) {
				case GRID_EMPTY:
					break;
				case GRID_PEASHOOTER:
					FPeashooter::removePlant(row, col);
					break;
				}
			}
		}
		chosen = NONE;
		shovelChosen = false;
	}
}
