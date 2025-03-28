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
	int rX, rY; // vi tri cham dat cua plant
	int animFrame;
	int animID;
	int id;
	enum ATTACK_RANGES range;

public:
	virtual ~FPlant() = 0;
	virtual bool update() = 0;

	static int convertToAnimID(enum PLANTS plant, enum PLANT_STATES state);
	void updateAnimID(int id);
	int getAnimID() const;

	int getID() const;
	enum ATTACK_RANGES getRange() const;

	void render(SDL_Renderer* mRenderer);

	int getRow() const;
	int getCol() const;
	SDL_Rect getHitbox() const;
	void takeDamage(int dmg);
	int getHP() const;
};
