#include "FBasicZombie.hpp"
#include "Global.hpp"

FBasicZombie::FBasicZombie(int row) {
	this->row = row;
	hp = ZOMBIE_BASIC_HP;
	animID = convertToAnimID(ZOMBIE_BASIC, ZOMBIE_WALK, ZOMBIE_NORMAL);
	// Random animation zombie
	animFrame = Rand(0, zombieAnimMaxFrame[animID] - 1);
	step = 0;
	// lay vi tri cham dat cua zom
	rY = LAWN_START_Y + LAWN_GRID_HEIGHT * (row + 1);
	rX = LAWN_START_X + LAWN_GRID_WIDTH * 9; // zombie se o xa cot cuoi
	hitbox.x = rX + zombieSprite[animID][0].w / SPRITE_DOWNSCALE / 2 - LAWN_GRID_WIDTH / 4;
	hitbox.y = rY - 3 * LAWN_GRID_HEIGHT / 4;
	hitbox.w = LAWN_GRID_WIDTH / 2;
	hitbox.h = LAWN_GRID_HEIGHT / 2;
	// Random vi tri zombie xuat hien
	int posOffset = Rand(0, LAWN_GRID_WIDTH);
	rX += posOffset;
	hitbox.x += posOffset;
	id = ++ZOMBIE_ID;
	//printf("%d %d %d %d\n", rX, rY, hitbox.x, hitbox.y);
}

FBasicZombie::~FBasicZombie() { 
	myLevel->vecPart.push_back(new FDeadZombie(rX, rY));
}

bool FBasicZombie::update() {
	if (hp <= 0) return 1;
	action();
	if (animID == convertToAnimID(ZOMBIE_BASIC, ZOMBIE_WALK, ZOMBIE_NORMAL)) move();
	return 0;
}

void FBasicZombie::action() {
	FPlant* damagedPlant = NULL;
	if (checkPlantInRange(this, myLevel->vecPlant, damagedPlant)) {
		if (animID != convertToAnimID(ZOMBIE_BASIC, ZOMBIE_EAT, ZOMBIE_NORMAL)) updateAnimID(convertToAnimID(ZOMBIE_BASIC, ZOMBIE_EAT, ZOMBIE_NORMAL));
		damagedPlant->takeDamage(ZOMBIE_DMG);
	}
	else {
		if (animID != convertToAnimID(ZOMBIE_BASIC, ZOMBIE_WALK, ZOMBIE_NORMAL)) updateAnimID(convertToAnimID(ZOMBIE_BASIC, ZOMBIE_WALK, ZOMBIE_NORMAL));
	}
}