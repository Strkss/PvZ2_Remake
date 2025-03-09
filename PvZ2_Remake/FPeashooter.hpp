#include <stdio.h>
#include <vector>
#include <SDL.h>

#include "FTexture.hpp"
#include "Constants.hpp"

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
	static void playAllAnim(SDL_Renderer* mRenderer);
	static bool loadMedia(SDL_Renderer* mRenderer);
	static bool removePlant(int row, int col);
	static bool compFunc(FPeashooter*& lhs, FPeashooter*& rhs);
	void playAnim(SDL_Renderer* mRenderer);
	
};

extern vector<FPeashooter*> vecPeashooter;