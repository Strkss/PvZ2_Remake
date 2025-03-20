#include "FDeadZombie.hpp"

FDeadZombie::FDeadZombie(int x, int y) { // render pos (x, y)
	hp = ZOMBIE_BASIC_HP;
	animID = convertToAnimID(ZOMBIE_DEAD, ZOMBIE_WALK, ZOMBIE_NORMAL);
	animFrame = 0;
	step = 0;
	rX = x;
	rY = y;
	hitbox.x = 0;
	hitbox.y = 0;
	hitbox.w = 0;
	hitbox.y = 0;
}

FDeadZombie::~FDeadZombie() {}

bool FDeadZombie::update() {
	if (animFrame / FRAME_PACING >= zombieAnimMaxFrame[animID]) return 1;
	return 0;
}