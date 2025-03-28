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
	enum ZOMBIE_HP_TIERS hpTier;
	enum ZOMBIES type;
	enum ZOMBIE_STATES state;
	void move();
public:
	virtual ~FZombie() = 0;
	virtual bool update() = 0;

	int getHP() const;

	static int convertToAnimID(int zombie, int state, int hpTier);
	void updateAnimID(int id);
	int getAnimID();

	int getRow() const;
	int getID() const;
	enum ZOMBIES getType() const;

	void render(SDL_Renderer* mRenderer);

	SDL_Rect getHitbox() const;
	void takeDamage(int dmg);
};