#include "FWallnut.hpp"
#include "Global.hpp"

FWallnut::FWallnut(int row, int col) {
	hp = 4000;
	this->row = row;
	this->col = col;
	hitbox.x = LAWN_START_X + col * LAWN_GRID_WIDTH + LAWN_GRID_WIDTH / 4;
	hitbox.y = LAWN_START_Y + row * LAWN_GRID_HEIGHT + LAWN_GRID_HEIGHT / 4;
	hitbox.w = LAWN_GRID_WIDTH / 2;
	hitbox.h = LAWN_GRID_HEIGHT / 2;
	rX = LAWN_START_X + LAWN_GRID_WIDTH * col + 5;
	rY = LAWN_START_Y + LAWN_GRID_HEIGHT * row + 8;
	animFrame = 0;
	animID = convertToAnimID(WALLNUT, PLANT_IDLE_0);
	id = ++PLANT_ID;
	range = DEFENSIVE;
	myLevel->myLawn.updateGrid(row, col, GRID_WALLNUT);
}

FWallnut::~FWallnut() {
	//printf("DESTRUCTOR CALLED\n");
	myLevel->myLawn.updateGrid(row, col, GRID_EMPTY);
}

bool FWallnut::update() {
	if (hp <= 0) return 1;
	if (hp <= 1000) {
		updateAnimID(convertToAnimID(WALLNUT, PLANT_IDLE_3));
	}
	else if (hp <= 2000) {
		updateAnimID(convertToAnimID(WALLNUT, PLANT_IDLE_2));
	}
	else if (hp <= 3000) {
		updateAnimID(convertToAnimID(WALLNUT, PLANT_IDLE_1));
	}
	return 0;
}