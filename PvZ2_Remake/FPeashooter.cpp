#include <stdio.h>
#include <SDL.h>

#include "FTexture.hpp"
#include "FPeashooter.hpp"
#include "FLawn.hpp"
#include "Constants.hpp"

SDL_Rect peashooterIdleSprite[PEASHOOTER_IDLE_FRAME], peashooterAttackSprite[PEASHOOTER_ATTACK_FRAME];
FTexture peashooterIdlePNG, peashooterAttackPNG;
vector<FPeashooter*> vecPeashooter;

bool FPeashooter::loadMedia(SDL_Renderer* mRenderer) {
	for (int i = 0; i < PEASHOOTER_IDLE_FRAME; i++) {
		peashooterIdleSprite[i] = { PEASHOOTER_SPRITE_SIZE * i, 0, PEASHOOTER_SPRITE_SIZE, PEASHOOTER_SPRITE_SIZE };
	}
	for (int i = 0; i < PEASHOOTER_ATTACK_FRAME; i++) {
		peashooterAttackSprite[i] = { PEASHOOTER_SPRITE_SIZE * i, 0, PEASHOOTER_SPRITE_SIZE, PEASHOOTER_SPRITE_SIZE };
	}
	peashooterIdlePNG.loadFromFile(mRenderer, PEASHOOTER_IDLE_IMG);
	peashooterAttackPNG.loadFromFile(mRenderer, PEASHOOTER_ATTACK_IMG);

	printf("DONE: FPeashooter -> loadMedia\n");
	return 1;
}

FPeashooter::FPeashooter(int r, int c) {
	hp = 300;
	row = r;
	col = c;
	x = LAWN_START_X + LAWN_GRID_WIDTH * col + 5;
	y = LAWN_START_Y + LAWN_GRID_HEIGHT * row + 8;
	animState = PEASHOOTER_ATTACK;
	animFrame = 0;
	FLawn::updateGrid(row, col, GRID_PEASHOOTER);
	vecPeashooter.push_back(this);
}

void FPeashooter::free() {
	FLawn::updateGrid(row, col, GRID_EMPTY);
	hp = 0;
	row = -1;
	col = -1;
	x = 0;
	y = 0;
	animState = PEASHOOTER_IDLE;
	animFrame = 0;
}

void FPeashooter::playAnim(SDL_Renderer* mRenderer) {
	++animFrame;
	switch (animState) {
	case PEASHOOTER_IDLE:
		if (animFrame / FRAME_PACING >= PEASHOOTER_IDLE_FRAME) animFrame = 0;
		peashooterIdlePNG.renderAtPosition(mRenderer, x, y, &peashooterIdleSprite[animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
		break;
	case PEASHOOTER_ATTACK:
		if (animFrame / FRAME_PACING >= PEASHOOTER_ATTACK_FRAME) animFrame = 0;
		if (animFrame * FRAME_PACING - 1 == PEASHOOTER_ATTACK_FRAME * 2 - 1) {
			shoot();
		}
		peashooterAttackPNG.renderAtPosition(mRenderer, x, y, &peashooterAttackSprite[animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
	}
}

void FPeashooter::playAllAnim(SDL_Renderer* mRenderer) {
	for (FPeashooter* myPea : vecPeashooter) {
		myPea->playAnim(mRenderer);
	}
}

bool FPeashooter::removePlant(int row, int col) {
	int delIndex = -1;
	for (int i = 0; i < (int)vecPeashooter.size(); i++) {
		if (vecPeashooter[i]->getRow() == row && vecPeashooter[i]->getCol() == col) {
			delIndex = i;
			break;
		}
	}
	if (delIndex == -1) {
		printf("Can't remove plant at %d %d\n", row, col);
		return 0;
	}
	vecPeashooter[delIndex]->free();
	vecPeashooter.erase(vecPeashooter.begin() + delIndex);
	printf("DONE: Removed plant at %d %d\n", row, col);
	return 1;
}

bool FPeashooter::compFunc(FPeashooter*& lhs, FPeashooter*& rhs) {
	return lhs->getRow() < rhs->getRow() || (lhs->getRow() == rhs->getRow() && lhs->getCol() < rhs->getCol());
}

int FPeashooter::getRow() {
	return row;
}

int FPeashooter::getCol() {
	return col;
}

void FPeashooter::shoot() {
	FPea* myPea = new FPea(LAWN_START_X + LAWN_GRID_WIDTH * col + LAWN_GRID_WIDTH / 2, LAWN_START_Y + LAWN_GRID_HEIGHT * row + LAWN_GRID_HEIGHT / 2 - peaTexture.getH() / SPRITE_DOWNSCALE);
}