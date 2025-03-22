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
	
	int getID();
	int getRow();
	SDL_Rect getHitbox();

	void render(SDL_Renderer* mRenderer);
	virtual bool update() = 0;
};

// render pos = hitbox.x + LAWN_GRID_WIDTH / 4, hitbox.y

//class FPea {
//	int x, y;
//	int row;
//	long long id;
//
//public:
//	FPea(int x, int y, int row);
//	void free();
//	void move();
//	long long getID();
//	int getRow();
//	int getX();
//	int getY();
//	void render(SDL_Renderer* mRenderer);
//
//	static void reset();
//	static void renderAll(SDL_Renderer* mRenderer);
//	static void loadMedia(SDL_Renderer* mRenderer);
//	static bool removePea(long long id);
//	
//};
//
//bool sortByRow(FPea*& lhs, FPea*& rhs);
//
//extern std::vector<FPea*> vecPea;