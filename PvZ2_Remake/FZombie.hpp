#pragma once
#include <stdio.h>
#include <SDL.h>
#include <vector>
#include <algorithm>

#include "FTexture.hpp"
#include "Constants.hpp"
#include "Math.hpp"

extern FTexture zombieTexture[ZOMBIE_MAX_SPRITE];
extern SDL_Rect* zombieSprite[ZOMBIE_MAX_SPRITE];
extern int zombieAnimMaxFrame[ZOMBIE_MAX_SPRITE];

class FZombie;

bool sortByRow(FZombie*& lhs, FZombie*& rhs);

class FZombie {
protected:
	int hp;
	int row;
	SDL_Rect hitbox;
	int rX, rY; // pos zombie cham dat
	int animFrame;
	int animID;
	int id;
	int step;

	void move();
public:
	virtual ~FZombie() = 0;
	virtual bool update() = 0;

	int getHP();

	static int convertToAnimID(enum ZOMBIES zombie, enum ZOMBIE_STATES state, enum ZOMBIE_HP_TIERS hpTier);
	void updateAnimID(int id);
	int getAnimID();

	int getRow();
	int getID();

	void render(SDL_Renderer* mRenderer);

	SDL_Rect getHitbox();
	void takeDamage(int dmg);
};

//extern FTexture zombieDieTexture, basicWalkTexture, basicEatTexture;
//extern SDL_Rect zombieDieSprite[ZOMBIE_DIE_FRAME], basicWalkSprite[ZOMBIE_BASIC_WALK_FRAME], basicEatSprite[ZOMBIE_BASIC_EAT_FRAME];
//extern bool levelLost;
//
//class FZombie {
//	int hp;
//	int x, y;
//	int row;
//	int id;
//	int step;
//	int animFrame;
//	enum ZOMBIE_STATES state;
//	enum ZOMBIE_TYPES type;
//
//public:
//	FZombie(int x, int y, int row, ZOMBIE_TYPES type);
//	FZombie(int x, int y); // Dead zombie
//	void free();
//	void move();
//	int getID();
//	void render(SDL_Renderer* mRenderer);
//	int getRow();
//	int getX();
//	int getY();
//	void updateAnimFrame(int frame);
//	void takeDamage(int dmg);
//	enum ZOMBIE_STATES getState();
//	void updateState(enum ZOMBIE_STATES state);
//	
//	static void reset();
//	static void loadMedia(SDL_Renderer* mRenderer);
//	static bool renderAll(SDL_Renderer* mRenderer);
//	static bool removeZombie(int id);
//	static bool removeDeadZombie(int id);
//};
//
//bool sortByRow(FZombie*& lhs, FZombie*& rhs);
//
//extern std::vector<FZombie*> vecZombie;
//extern std::vector<FZombie*> deadZombie;