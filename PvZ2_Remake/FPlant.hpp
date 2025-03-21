#pragma once
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include <utility>

#include "Constants.hpp"
#include "FTexture.hpp"
#include "FLawn.hpp"

extern SDL_Rect* plantSprite[PLANT_MAX_SPRITE];
extern FTexture plantTexture[PLANT_MAX_SPRITE];
extern int plantAnimMaxFrame[PLANT_MAX_SPRITE];

class FPlant;

bool sortByRow(FPlant*& lhs, FPlant*& rhs);

class FPlant {
protected:
	int hp;
	int row, col;
	SDL_Rect hitbox;
	int rX, rY; // render pos
	int animFrame;
	int animID;
	int id;
	enum ATTACK_RANGES range;

public:
	virtual bool update() = 0;

	static int convertToAnimID(enum PLANTS plant, enum PLANT_STATES state);
	void updateAnimID(int id);
	int getAnimID();

	int getID();
	enum ATTACK_RANGES getRange();

	void render(SDL_Renderer* mRenderer);

	int getRow();
	int getCol();
	SDL_Rect getHitbox();
	void takeDamage(int dmg);
	int getHP();
};
