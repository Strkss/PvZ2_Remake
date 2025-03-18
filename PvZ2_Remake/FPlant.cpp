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
	plantTexture->renderAtPosition(mRenderer, rX, rY, &plantSprite[animID][animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
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

void FPlant::takeDamage(int dmg) {
	hp -= dmg;
}