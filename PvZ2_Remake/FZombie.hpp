#pragma once
#include <stdio.h>
#include <SDL.h>
#include <vector>
#include <algorithm>

#include "FTexture.hpp"
#include "Constants.hpp"

extern FTexture zombieDieTexture, basicWalkTexture, basicEatTexture;
extern SDL_Rect zombieDieSprite[ZOMBIE_DIE_FRAME], basicWalkSprite[ZOMBIE_BASIC_WALK_FRAME], basicEatSprite[ZOMBIE_BASIC_EAT_FRAME];
extern bool levelLost;

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
	FZombie(int x, int y); // Dead zombie
	void free();
	void move();
	int getID();
	void playAnim(SDL_Renderer* mRenderer);
	int getRow();
	int getX();
	int getY();
	void updateAnimFrame(int frame);
	void takeDamage(int dmg);
	enum ZOMBIE_STATES getState();
	void updateState(enum ZOMBIE_STATES state);
	
	static void reset();
	static void loadMedia(SDL_Renderer* mRenderer);
	static bool renderAll(SDL_Renderer* mRenderer);
	static bool removeZombie(int id);
	static bool removeDeadZombie(int id);
};

bool sortByRow(FZombie*& lhs, FZombie*& rhs);

extern std::vector<FZombie*> vecZombie;
extern std::vector<FZombie*> deadZombie;