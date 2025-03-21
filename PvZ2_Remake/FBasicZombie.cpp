#include "FBasicZombie.hpp"
#include "Global.hpp"

FBasicZombie::FBasicZombie(int row) {
	this->row = row;
	hp = ZOMBIE_BASIC_HP;
	animID = convertToAnimID(ZOMBIE_BASIC, ZOMBIE_WALK, ZOMBIE_NORMAL);
	animFrame = 0;
	step = 0;
	// lay vi tri cham dat cua zom
	rY = LAWN_START_Y + LAWN_GRID_HEIGHT * (row + 1);
	rX = LAWN_START_X + LAWN_GRID_WIDTH * 8; // zombie se o xa cot cuoi
	hitbox.x = rX + zombieSprite[animID][0].w / SPRITE_DOWNSCALE / 2 - LAWN_GRID_WIDTH / 4;
	hitbox.y = LAWN_START_Y + LAWN_GRID_HEIGHT * row + LAWN_GRID_HEIGHT / 4;
	hitbox.w = LAWN_GRID_WIDTH / 2;
	hitbox.y = LAWN_GRID_HEIGHT / 2;
}

FBasicZombie::~FBasicZombie() { 
	myLevel->vecPart.push_back(new FDeadZombie(rX, rY));
}

bool FBasicZombie::update() {
	if (hp <= 0) return 1;
	if (animID == convertToAnimID(ZOMBIE_BASIC, ZOMBIE_WALK, ZOMBIE_NORMAL)) move();
	return 0;
}