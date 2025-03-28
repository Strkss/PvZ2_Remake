#include "FZombie.hpp"

FTexture zombieTexture[ZOMBIE_MAX_SPRITE];
SDL_Rect* zombieSprite[ZOMBIE_MAX_SPRITE];
int zombieAnimMaxFrame[ZOMBIE_MAX_SPRITE];

bool sortByRow(FZombie*& lhs, FZombie*& rhs) {
	return lhs->getRow() < rhs->getRow() || (lhs->getRow() == rhs->getRow() && lhs->getHitbox().x < rhs->getHitbox().x);
}

FZombie::~FZombie() {}

int FZombie::convertToAnimID(int zombie, int state, int hpTier) {
	return zombie * ZOMBIE_HP_TIERS_NUM * ZOMBIE_STATES_NUM  + hpTier * ZOMBIE_STATES_NUM + state;
}

void FZombie::updateAnimID(int id) {
	animID = id;
	animFrame = 0;
}

int FZombie::getAnimID() {
	return animID;
}

int FZombie::getID() const {
	return id;
}

enum ZOMBIES FZombie::getType() const {
	return type;
}

void FZombie::render(SDL_Renderer* mRenderer) {
	if (animFrame / FRAME_PACING >= zombieAnimMaxFrame[animID]) animFrame = 0;
	zombieTexture[animID].renderAtPosition(mRenderer, rX, rY - zombieSprite[animID][0].h / SPRITE_DOWNSCALE, &zombieSprite[animID][animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
#ifdef DEBUG_HITBOX
	SDL_GetRenderDrawColor(mRenderer, 0, 0, 0, 0);
	SDL_RenderDrawRect(mRenderer, &hitbox);
#endif
}

SDL_Rect FZombie::getHitbox() const {
	return hitbox;
}

void FZombie::takeDamage(int dmg) {
	hp -= dmg;
}

void FZombie::move() {
	++step;
	if (step >= ZOMBIE_INV_VEL) {
		--rX;
		--hitbox.x;
		step = 0;
	}
}

int FZombie::getRow() const {
	return row;
}

int FZombie::getHP() const {
	return hp;
}