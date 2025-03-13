#pragma once
#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FTexture.hpp"
#include "Constants.hpp"

extern FTexture zombieDieTexture, basicWalkTexture, basicEatTexture;
extern SDL_Rect zombieDieSprite[ZOMBIE_DIE_FRAME], basicWalkSprite[ZOMBIE_BASIC_WALK_FRAME], basicEatSprite[ZOMBIE_BASIC_EAT_FRAME];

class FZombie {
	int hp;
	int x, y;
	int row;
	int id;
	int step;
	int animFrame;
	enum ZOMBIE_STATES state;
	enum ZOMBIE_TYPES type;

public:
	FZombie(int x, int y, int row, ZOMBIE_TYPES type);
	void free();
	void move();
	int getID();
	void playAnim(SDL_Renderer* mRenderer);
	int getRow();
	int getX();
	int getY();
	void takeDamage(int dmg);
	enum ZOMBIE_STATES getState();
	void updateState(enum ZOMBIE_STATES state);
	
	static void loadMedia(SDL_Renderer* mRenderer);
	static bool renderAll(SDL_Renderer* mRenderer);
	static bool removeZombie(int id);
};

bool sortByRow(FZombie*& lhs, FZombie*& rhs);

extern std::vector<FZombie*> vecZombie;