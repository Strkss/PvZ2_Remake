#include "FGreenPea.hpp"
#include "Global.hpp"

FGreenPea::FGreenPea(int r, int c) {
	rX = LAWN_START_X + LAWN_GRID_WIDTH * c + LAWN_GRID_WIDTH / 2;
	rY = LAWN_START_Y + LAWN_GRID_HEIGHT * r + LAWN_GRID_HEIGHT / 2 - peaTexture.getH() / SPRITE_DOWNSCALE;
	hitbox.x = rX;
	hitbox.y = rY;
	hitbox.w = peaTexture.getW() / SPRITE_DOWNSCALE;
	hitbox.h = peaTexture.getH() / SPRITE_DOWNSCALE;
	row = r;
	isExploded = false;
	id = ++PEA_ID;
}

FGreenPea::~FGreenPea() {}

bool FGreenPea::update() {
	action();
	if (hitbox.x >= SCREEN_WIDTH || isExploded) return 1;
	move();
	return 0;
}

void FGreenPea::action() {
	if (hitbox.x >= SCREEN_WIDTH) isExploded = 1;
	FZombie* damagedZom = NULL;
	if (checkPeaExploded(this, myLevel->vecZombie, damagedZom) && !isExploded) {
		isExploded = 1;
		damagedZom->takeDamage(PEA_DMG);
		if (damagedZom->getType() == ZOMBIE_BUCKET) Mix_PlayChannel(-1, sfxMetalHit, 0);
		else Mix_PlayChannel(-1, sfxHit, 0);
	}
}
