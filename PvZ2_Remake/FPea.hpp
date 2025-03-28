#pragma once
#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FTexture.hpp"

class FPea;

extern FTexture peaTexture;

bool sortByRow(FPea*& lhs, FPea*& rhs);

class FPea {
protected:
	int rX, rY; // render pos
	SDL_Rect hitbox;
	int row;
	int id;

	void move();

public:
	bool isExploded;
	
	int getID() const;
	int getRow() const;
	SDL_Rect getHitbox() const;

	void render(SDL_Renderer* mRenderer);
	virtual bool update() = 0;
};