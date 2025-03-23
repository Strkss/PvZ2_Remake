#include "FFlagZombie.hpp"
#include "Global.hpp"

FFlagZombie::FFlagZombie(int row) {
	this->row = row;
	hp = ZOMBIE_FLAG_HP;
	animID = convertToAnimID(ZOMBIE_FLAG, ZOMBIE_WALK, ZOMBIE_NORMAL);
	animFrame = 0;
	step = 0;
	// lay vi tri cham dat cua zom
	rY = LAWN_START_Y + LAWN_GRID_HEIGHT * (row + 1);
	rX = LAWN_START_X + LAWN_GRID_WIDTH * 9; // zombie se o xa cot cuoi
	hitbox.x = rX + zombieSprite[animID][0].w / SPRITE_DOWNSCALE / 2 - LAWN_GRID_WIDTH / 4;
	hitbox.y = rY - 3 * LAWN_GRID_HEIGHT / 4;
	hitbox.w = LAWN_GRID_WIDTH / 2;
	hitbox.h = LAWN_GRID_HEIGHT / 2;
	id = ++ZOMBIE_ID;
	type = ZOMBIE_FLAG;
	hpTier = ZOMBIE_NORMAL;
	state = ZOMBIE_WALK;
	//printf("%d %d %d %d\n", rX, rY, hitbox.x, hitbox.y);
}

FFlagZombie::~FFlagZombie() {
	myLevel->vecPart.push_back(new FDeadZombie(rX, rY));
}

bool FFlagZombie::update() {
	if (hp <= 0) return 1;
	action();
	if (state == ZOMBIE_WALK) move();
	return 0;
}

void FFlagZombie::action() {
	FPlant* damagedPlant = NULL;
	if (checkPlantInRange(this, myLevel->vecPlant, damagedPlant)) {
		if (state == ZOMBIE_WALK) {
			state = ZOMBIE_EAT;
			updateAnimID(convertToAnimID(type, state, hpTier));
		}
		damagedPlant->takeDamage(ZOMBIE_DMG);
		if (!Mix_Playing(7)) Mix_PlayChannel(7, sfxEat, 0);
	}
	else {
		if (state == ZOMBIE_EAT) {
			state = ZOMBIE_WALK;
			updateAnimID(convertToAnimID(type, state, hpTier));
		}
	}
}