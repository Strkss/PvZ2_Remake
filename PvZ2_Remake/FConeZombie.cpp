#include "FConeZombie.hpp"
#include "Global.hpp"

FConeZombie::FConeZombie(int row) {
	this->row = row;
	hp = ZOMBIE_CONE_HP;
	animID = convertToAnimID(ZOMBIE_CONE, ZOMBIE_WALK, ZOMBIE_NORMAL);
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
	int posOffset = Rand(0, LAWN_GRID_WIDTH / 2);
	rX += posOffset;
	hitbox.x += posOffset;
	id = ++ZOMBIE_ID;
	hpTier = ZOMBIE_NORMAL;
	type = ZOMBIE_CONE;
	state = ZOMBIE_WALK;
	//printf("%d %d %d %d\n", rX, rY, hitbox.x, hitbox.y);
}

FConeZombie::~FConeZombie() {
	myLevel->vecPart.push_back(new FDeadZombie(rX, rY));
}

bool FConeZombie::update() {
	++animFrame;
	if (hp <= 0) return 1;
	if (hp <= 190 + 370 / 2 && hp > 190 && hpTier != ZOMBIE_DAMAGED_0) {
		hpTier = ZOMBIE_DAMAGED_0;
		animID = convertToAnimID(type, state, hpTier);
	}
	if (hp <= 190 && type != ZOMBIE_BASIC) {
		type = ZOMBIE_BASIC;
		hpTier = ZOMBIE_NORMAL;
		animID = convertToAnimID(type, state, hpTier);
	}
	action();
	if (state == ZOMBIE_WALK) move();
	return 0;
}

void FConeZombie::action() {
	FPlant* damagedPlant = NULL;
	if (checkPlantInRange(this, myLevel->vecPlant, damagedPlant)) {
		if (state == ZOMBIE_WALK) {
			state = ZOMBIE_EAT;
			updateAnimID(convertToAnimID(type, state, hpTier));
		}
		damagedPlant->takeDamage(ZOMBIE_DMG);
		if (!Mix_Playing(28)) Mix_PlayChannel(28, sfxEat, 0);
	}
	else {
		if (state == ZOMBIE_EAT) {
			state = ZOMBIE_WALK;
			updateAnimID(convertToAnimID(type, state, hpTier));
		}
	}
}