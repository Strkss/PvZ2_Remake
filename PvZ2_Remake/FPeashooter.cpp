#include "FPeashooter.hpp"
#include "Global.hpp"

FPeashooter::FPeashooter(int row, int col) {
	hp = 300;
	this->row = row;
	this->col = col;
	hitbox.x = LAWN_START_X + col * LAWN_GRID_WIDTH + LAWN_GRID_WIDTH / 4;
	hitbox.y = LAWN_START_Y + row * LAWN_GRID_HEIGHT + LAWN_GRID_HEIGHT / 4;
	hitbox.w = LAWN_GRID_WIDTH / 2;
	hitbox.h = LAWN_GRID_HEIGHT / 2;
	rX = LAWN_START_X + LAWN_GRID_WIDTH * col + 5;
	rY = LAWN_START_Y + LAWN_GRID_HEIGHT * row + 8;
	animFrame = 0;
	animID = convertToAnimID(PEASHOOTER, PLANT_IDLE_0);
	id = ++PLANT_ID;
	range = ONE_ROW_AHEAD;
	myLevel->myLawn.updateGrid(row, col, GRID_PEASHOOTER);
}

FPeashooter::~FPeashooter() { 
	myLevel->myLawn.updateGrid(row, col, GRID_EMPTY);
}

void FPeashooter::shoot() {
	myLevel->vecPea.push_back(new FPea(row, col));
}

bool FPeashooter::update() {
	if (hp <= 0) return 1;
	action();
	return 0;
}

void FPeashooter::action() {
	if (animID != convertToAnimID(PEASHOOTER, PLANT_ATTACK)) return;
	std::vector<FZombie*> damagedZom;
	if (checkZombieInRange(this, myLevel->vecZombie, damagedZom) && animFrame == plantAnimMaxFrame[animID] * FRAME_PACING - 1) {
		shoot();
	}
}

//SDL_Rect peashooterIdleSprite[PEASHOOTER_IDLE_FRAME], peashooterAttackSprite[PEASHOOTER_ATTACK_FRAME];
//FTexture peashooterIdlePNG, peashooterAttackPNG;
//vector<FPeashooter*> vecPeashooter;
//
//bool FPeashooter::loadMedia(SDL_Renderer* mRenderer) {
//	for (int i = 0; i < PEASHOOTER_IDLE_FRAME; i++) {
//		peashooterIdleSprite[i] = { PEASHOOTER_SPRITE_SIZE * i, 0, PEASHOOTER_SPRITE_SIZE, PEASHOOTER_SPRITE_SIZE };
//	}
//	for (int i = 0; i < PEASHOOTER_ATTACK_FRAME; i++) {
//		peashooterAttackSprite[i] = { PEASHOOTER_SPRITE_SIZE * i, 0, PEASHOOTER_SPRITE_SIZE, PEASHOOTER_SPRITE_SIZE };
//	}
//	peashooterIdlePNG.loadFromFile(mRenderer, PEASHOOTER_IDLE_IMG);
//	peashooterAttackPNG.loadFromFile(mRenderer, PEASHOOTER_ATTACK_IMG);
//
//	printf("DONE: FPeashooter -> loadMedia\n");
//	return 1;
//}
//
//FPeashooter::FPeashooter(int r, int c) {
//	hp = 300;
//	row = r;
//	col = c;
//	x = LAWN_START_X + LAWN_GRID_WIDTH * col + 5;
//	y = LAWN_START_Y + LAWN_GRID_HEIGHT * row + 8;
//	animState = PEASHOOTER_IDLE;
//	animFrame = 0;
//	FLawn::updateGrid(row, col, GRID_PEASHOOTER);
//	vecPeashooter.push_back(this);
//}
//
//void FPeashooter::free() {
//	FLawn::updateGrid(row, col, GRID_EMPTY);
//	hp = 0;
//	row = -1;
//	col = -1;
//	x = 0;
//	y = 0;
//	animState = PEASHOOTER_IDLE;
//	animFrame = 0;
//}
//
//void FPeashooter::updateState(enum PEASHOOTER_STATES state) {
//	this->animState = state;
//	animFrame = 0;
//}
//
//void FPeashooter::playAnim(SDL_Renderer* mRenderer) {
//	++animFrame;
//	switch (animState) {
//	case PEASHOOTER_IDLE:
//		if (animFrame / FRAME_PACING >= PEASHOOTER_IDLE_FRAME) animFrame = 0;
//		peashooterIdlePNG.renderAtPosition(mRenderer, x, y, &peashooterIdleSprite[animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
//		break;
//	case PEASHOOTER_ATTACK:
//		if (animFrame / FRAME_PACING >= PEASHOOTER_ATTACK_FRAME) animFrame = 0;
//		if (animFrame * FRAME_PACING - 1 == PEASHOOTER_ATTACK_FRAME * 2 - 1) {
//			shoot();
//		}
//		peashooterAttackPNG.renderAtPosition(mRenderer, x, y, &peashooterAttackSprite[animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
//	}
//}
//
//void FPeashooter::takeDamage(int dmg) {
//	hp -= dmg;
//}
//
//void FPeashooter::renderAll(SDL_Renderer* mRenderer) {
//	vector<std::pair<int, int>> toBeRemoved;
//	for (FPeashooter* myPea : vecPeashooter) {
//		if (myPea->hp < 0) {
//			toBeRemoved.push_back(std::make_pair(myPea->getRow(), myPea->getCol()));
//		}
//		else myPea->playAnim(mRenderer);
//	}
//	for (std::pair<int, int>& it : toBeRemoved) {
//		removePlant(it.first, it.second);
//	}
//}
//
//bool FPeashooter::removePlant(int row, int col) {
//	int delIndex = -1;
//	for (int i = 0; i < (int)vecPeashooter.size(); i++) {
//		if (vecPeashooter[i]->getRow() == row && vecPeashooter[i]->getCol() == col) {
//			delIndex = i;
//			break;
//		}
//	}
//	if (delIndex == -1) {
//		printf("Can't remove plant at %d %d\n", row, col);
//		return 0;
//	}
//	vecPeashooter[delIndex]->free();
//	vecPeashooter.erase(vecPeashooter.begin() + delIndex);
//	printf("DONE: Removed plant at %d %d\n", row, col);
//	return 1;
//}
//
//void FPeashooter::reset() {
//	vecPeashooter.clear();
//
//	printf("DONE: reset FPeashooter\n");
//}
//
//bool sortByRow(FPeashooter*& lhs, FPeashooter*& rhs) {
//	return lhs->getRow() < rhs->getRow() || (lhs->getRow() == rhs->getRow() && lhs->getCol() < rhs->getCol());
//}
//
//int FPeashooter::getRow() {
//	return row;
//}
//
//int FPeashooter::getCol() {
//	return col;
//}
//
//void FPeashooter::shoot() {
//	FPea* myPea = new FPea(LAWN_START_X + LAWN_GRID_WIDTH * col + LAWN_GRID_WIDTH / 2, LAWN_START_Y + LAWN_GRID_HEIGHT * row + LAWN_GRID_HEIGHT / 2 - peaTexture.getH() / SPRITE_DOWNSCALE, row);
//}
//
//enum PEASHOOTER_STATES FPeashooter::getState() {
//	return animState;
//}