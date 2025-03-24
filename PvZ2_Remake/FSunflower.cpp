#include "FSunflower.hpp"
#include "Global.hpp"

FSunflower::FSunflower(int row, int col) {
	hp = 300;
	this->row = row;
	this->col = col;
	hitbox.x = LAWN_START_X + col * LAWN_GRID_WIDTH + LAWN_GRID_WIDTH / 4;
	hitbox.y = LAWN_START_Y + row * LAWN_GRID_HEIGHT + LAWN_GRID_HEIGHT / 4;
	hitbox.w = LAWN_GRID_WIDTH / 2;
	hitbox.h = LAWN_GRID_HEIGHT / 2;
	rX = LAWN_START_X + LAWN_GRID_WIDTH * col + 5;
	rY = LAWN_START_Y + LAWN_GRID_HEIGHT * row + 8;
	animFrame = 0;
	animID = convertToAnimID(SUNFLOWER, PLANT_IDLE_0);
	id = ++PLANT_ID;
	range = DEFENSIVE;
	timer = 0;
	myLevel->myLawn.updateGrid(row, col, GRID_SUNFLOWER);
}

FSunflower::~FSunflower() {
	//printf("DESTRUCTOR CALLED\n");
	myLevel->myLawn.updateGrid(row, col, GRID_EMPTY);
}

void FSunflower::giveSun() {
	myLevel->mySun.vecSun.push_back(new FSun(hitbox.x, hitbox.y));
}

bool FSunflower::update() {
	if (hp <= 0) return 1;
	action();
	return 0;
}

void FSunflower::action() {
	++timer;
	if (timer >= SUN_SUNFLOWER_DELAY) {
		updateAnimID(convertToAnimID(SUNFLOWER, PLANT_SPECIAL));
		if (animFrame == plantAnimMaxFrame[animID] - 1) {
			giveSun(); // ra sun o frame giua
		}
		else if ((animFrame + 1) / FRAME_PACING >= plantAnimMaxFrame[animID]) {
			timer = 0;
			updateAnimID(convertToAnimID(SUNFLOWER, PLANT_IDLE_0));
		}
	}
}