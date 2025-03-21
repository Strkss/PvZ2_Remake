#include "FDeadZombie.hpp"

FDeadZombie::FDeadZombie(int x, int y) { //(x, y) la vi tri zombie cham dat
	animID = ZOMBIE_DEAD;
	animFrame = 0;
	rX = x;
	rY = y - particleSprite[animID][0].h / SPRITE_DOWNSCALE;
	id = ++PARTICLE_ID;
}

FDeadZombie::~FDeadZombie() {}