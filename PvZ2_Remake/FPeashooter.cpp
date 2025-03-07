#include <stdio.h>
#include <SDL.h>

#include "FTexture.hpp"
#include "FPeashooter.hpp"
#include "FLawn.hpp"
#include "Constants.hpp"

SDL_Rect peashooterIdleSprite[PEASHOOTER_IDLE_FRAME], peashooterAttackSprite[PEASHOOTER_ATTACK_FRAME];
FTexture peashooterIdlePNG, peashooterAttackPNG;

bool FPeashooter::loadMedia(SDL_Renderer* mRenderer) {
	for (int i = 0; i < PEASHOOTER_IDLE_FRAME; i++) {
		peashooterIdleSprite[i] = { SPRITE_SIZE * i, 0, SPRITE_SIZE, SPRITE_SIZE };
	}
	for (int i = 0; i < PEASHOOTER_ATTACK_FRAME; i++) {
		peashooterAttackSprite[i] = { SPRITE_SIZE * i, 0, SPRITE_SIZE, SPRITE_SIZE };
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
	animState = 0;
	animFrame = 0;
	FLawn::updateGrid(row, col, GRID_PEASHOOTER);
}

void FPeashooter::playAnim(SDL_Renderer* mRenderer) {
	++animFrame;
	if (!animState) {
		if (animFrame / FRAME_PACING >= PEASHOOTER_IDLE_FRAME) animFrame = 0;
		peashooterIdlePNG.renderAtPosition(mRenderer, x, y, &peashooterIdleSprite[animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
	}
	else {

	}
}