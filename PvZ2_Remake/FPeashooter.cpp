#include "FPeashooter.hpp"
#include "Global.hpp"

FPeashooter::FPeashooter(int row, int col) {
	hp = 300;
	this->row = row;
	this->col = col;
	hitbox.x = LAWN_START_X + col * LAWN_GRID_WIDTH + LAWN_GRID_WIDTH / 4;
	hitbox.y = LAWN_START_Y + row * LAWN_GRID_HEIGHT + LAWN_GRID_HEIGHT / 4;
	hitbox.w = LAWN_GRID_WIDTH / 2;
	hitbox.h = LAWN_GRID_HEIGHT / 2;
	animFrame = 0;
	animID = convertToAnimID(PEASHOOTER, PLANT_IDLE_0);
	// Lay vi tri cua grid
	rX = LAWN_START_X + LAWN_GRID_WIDTH * col;
	rY = LAWN_START_Y + LAWN_GRID_HEIGHT * row;
	// Chinh toa do x
	rX += LAWN_GRID_WIDTH / 2;
	rX -= plantSprite[animID][0].w / 2 / SPRITE_DOWNSCALE;
	// Chinh toa do y;
	rY += LAWN_GRID_HEIGHT;
	rY -= 8;
	id = ++PLANT_ID;
	range = ONE_ROW_AHEAD;
	myLevel->myLawn.updateGrid(row, col, GRID_PEASHOOTER);
}

FPeashooter::~FPeashooter() { 
	//printf("DESTRUCTOR CALLED\n");
	myLevel->myLawn.updateGrid(row, col, GRID_EMPTY);
}

void FPeashooter::shoot() {
	myLevel->vecPea.push_back(new FGreenPea(row, col));
}

bool FPeashooter::update() {
	++animFrame;
	if (hp <= 0) return 1;
	action();
	return 0;
}

void FPeashooter::action() {
	std::vector<FZombie*> damagedZom;
	if (checkZombieInRange(this, myLevel->vecZombie, damagedZom)) {
		updateAnimID(convertToAnimID(PEASHOOTER, PLANT_ATTACK));
		if (animFrame == plantAnimMaxFrame[animID] - 1) shoot(); // ban o frame giua
	}
	else {
		updateAnimID(convertToAnimID(PEASHOOTER, PLANT_IDLE_0));
	}
}