#include "FPotatomine.hpp"
#include "Global.hpp"

FPotatomine::FPotatomine(int row, int col) {
	hp = 300;
	this->row = row;
	this->col = col;
	hitbox.x = LAWN_START_X + col * LAWN_GRID_WIDTH + LAWN_GRID_WIDTH / 4;
	hitbox.y = LAWN_START_Y + row * LAWN_GRID_HEIGHT + LAWN_GRID_HEIGHT / 4;
	hitbox.w = LAWN_GRID_WIDTH / 2;
	hitbox.h = LAWN_GRID_HEIGHT / 2;
	animFrame = 0;
	animID = convertToAnimID(POTATOMINE, PLANT_IDLE_0);
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
	timer = 0;
	range = ONE_TILE;
	myLevel->myLawn.updateGrid(row, col, GRID_POTATOMINE);
}

FPotatomine::~FPotatomine() {
	//printf("DESTRUCTOR CALLED\n");
	// do some explosion effect here
	myLevel->myLawn.updateGrid(row, col, GRID_EMPTY);
}

void FPotatomine::explode(std::vector<FZombie*> damagedZom) {
	for (auto& it : damagedZom) {
		it->takeDamage(1800);
	}
	hp = 0;
}

bool FPotatomine::update() {
	if (hp <= 0) return 1;
	action();
	return 0;
}

void FPotatomine::action() {
	std::vector<FZombie*> damagedZom;
	if (checkZombieInRange(this, myLevel->vecZombie, damagedZom) && timer >= POTATOMINE_ARMING_TIME) {
		updateAnimID(convertToAnimID(POTATOMINE, PLANT_ATTACK));
		if ((animFrame + 1) / FRAME_PACING == plantAnimMaxFrame[animID]) {
			explode(damagedZom);
		}
	}
	else if (timer >= POTATOMINE_ARMING_TIME) {
		updateAnimID(convertToAnimID(POTATOMINE, PLANT_IDLE_1));
	}
	else ++timer;
}