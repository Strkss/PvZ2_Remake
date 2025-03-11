#pragma once
#include <stdio.h>
#include <SDL.h>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <chrono>

#include "FTexture.hpp"
#include "Math.hpp"

using std::vector;

extern FTexture sun, sunCounter, sunText;

class FSun {
	int sX, sY;
	int curX, curY;
	int velX, velY;
	int despawnTime;
	enum SUN_STATES state;
	static int curSun;
	static int time;

public:
	FSun(int x, int y);
	void free();
	void move();
	void decideVel();
	int getSX();
	int getSY();

	static void summonSkySun();
	static void updateSunCounter(SDL_Renderer* mRenderer, int add);
	static void renderAll(SDL_Renderer* mRenderer);
	static void loadMedia(SDL_Renderer* mRenderer);
	static void removeSun(int x, int y);
	static bool findSunClick(int x, int y);
	static int getCurSun();
};

extern vector<FSun*> vecSun;