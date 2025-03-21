#include "FPlant.hpp"

SDL_Rect* plantSprite[PLANT_MAX_SPRITE];
FTexture plantTexture[PLANT_MAX_SPRITE];
int plantAnimMaxFrame[PLANT_MAX_SPRITE];

bool sortByRow(FPlant*& lhs, FPlant*& rhs) {
	return lhs->getRow() < rhs->getRow() || (lhs->getRow() == rhs->getRow() && lhs->getCol() < rhs->getCol());
}

int FPlant::convertToAnimID(enum PLANTS plant, enum PLANT_STATES state) {
	return plant * PLANT_STATES_NUM + state;
}

void FPlant::updateAnimID(int id) {
	animID = id;
	animFrame = 0;
}

int FPlant::getAnimID() {
	return animID;
}

void FPlant::render(SDL_Renderer* mRenderer) {
	++animFrame;
	if (animFrame / FRAME_PACING >= plantAnimMaxFrame[animID]) animFrame = 0;
	plantTexture[animID].renderAtPosition(mRenderer, rX, rY, &plantSprite[animID][animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
#ifdef DEBUG_HITBOX
	SDL_GetRenderDrawColor(mRenderer, 0, 0, 0, 0);
	SDL_RenderDrawRect(mRenderer, &hitbox);
#endif	
}

int FPlant::getRow() {
	return row;
}

int FPlant::getCol() {
	return col;
}

int FPlant::getID() {
	return id;
}

SDL_Rect FPlant::getHitbox() {
	return hitbox;
}

void FPlant::takeDamage(int dmg) {
	hp -= dmg;
}

enum ATTACK_RANGES FPlant::getRange() {
	return range;
}

int FPlant::getHP() {
	return hp;
}