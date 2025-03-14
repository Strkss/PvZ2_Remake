#pragma once
#include <stdio.h>
#include <vector>
#include <SDL.h>

#include "FTexture.hpp"
#include "Constants.hpp"
#include "FPea.hpp"

using std::vector;

extern SDL_Rect peashooterIdleSprite[PEASHOOTER_IDLE_FRAME], peashooterAttackSprite[PEASHOOTER_ATTACK_FRAME];
extern FTexture peashooterIdlePNG, peashooterAttackPNG;

class FPeashooter {
	int hp;
	int row, col;
	int x, y;
	enum PEASHOOTER_STATES animState;
	int animFrame;
	
public:
	FPeashooter(int r, int c);
	void free();
	int getRow();
	int getCol();
	void shoot();
	void playAnim(SDL_Renderer* mRenderer);
	void updateState(enum PEASHOOTER_STATES state);
	enum PEASHOOTER_STATES getState();
	void takeDamage(int dmg);
	
	static void reset();
	static void renderAll(SDL_Renderer* mRenderer);
	static bool loadMedia(SDL_Renderer* mRenderer);
	static bool removePlant(int row, int col);
};

bool sortByRow(FPeashooter*& lhs, FPeashooter*& rhs);

extern vector<FPeashooter*> vecPeashooter;