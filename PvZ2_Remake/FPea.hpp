#pragma once
#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FTexture.hpp"

extern FTexture peaTexture;

class FPea {
	int x, y;
	int row;
	long long id;

public:
	FPea(int x, int y, int row);
	void free();
	void move();
	long long getID();
	int getRow();
	int getX();
	int getY();

	static void reset();
	static void renderAll(SDL_Renderer* mRenderer);
	static void loadMedia(SDL_Renderer* mRenderer);
	static bool removePea(long long id);
	
};

bool sortByRow(FPea*& lhs, FPea*& rhs);

extern std::vector<FPea*> vecPea;