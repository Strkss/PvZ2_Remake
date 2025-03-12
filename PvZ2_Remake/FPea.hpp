#pragma once
#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FTexture.hpp"

extern FTexture peaTexture;

class FPea {
	int x, y;
	long long id;

public:
	FPea(int x, int y);
	void free();
	void move();
	long long getID();

	static void renderAll(SDL_Renderer* mRenderer);
	static void loadMedia(SDL_Renderer* mRenderer);
	static bool removePea(long long id);
	
};

extern std::vector<FPea*> vecPea;