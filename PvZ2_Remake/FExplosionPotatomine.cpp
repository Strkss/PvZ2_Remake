#include "FExplosionPotatomine.hpp"

FExplosionPotatomine::FExplosionPotatomine(int x, int y) { //(x, y) la vi tri plant cham dat, can x o chinh giua
	animID = POTATOMINE_EXPLOSION;
	animFrame = 0;
	rX = x - particleSprite[animID][0].w / 2 / SPRITE_DOWNSCALE;
	rY = y - particleSprite[animID][0].h / SPRITE_DOWNSCALE + 50;
	id = ++PARTICLE_ID;
}

FExplosionPotatomine::~FExplosionPotatomine() {}