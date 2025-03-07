#include <stdio.h>
#include <SDL.h>

#include "FTexture.hpp"
#include "Constants.hpp"

extern SDL_Rect peashooterIdleSprite[PEASHOOTER_IDLE_FRAME], peashooterAttackSprite[PEASHOOTER_ATTACK_FRAME];
extern FTexture peashooterIdlePNG, peashooterAttackPNG;

class FPeashooter {
	int hp;
	int row, col;
	int x, y;
	int animState;
	int animFrame;
	
public:
	FPeashooter(int r, int c);
	static bool loadMedia(SDL_Renderer* mRenderer);
	void playAnim(SDL_Renderer* mRenderer);
};