#pragma once
#include <stdio.h>
#include <SDL.h>
#include <string>
#include <cmath>
#include <random>
#include <chrono>

#include "FTexture.hpp"
#include "Math.hpp"
#include "Constants.hpp"

extern FTexture sunTexture, sunCounterTexture, sunTextTexture;

class FSun {
	int rX, rY;
	int velX, velY;
	SDL_Rect hitbox;
	enum SUN_STATES state;
	int timer;
	int id;
	
	void move();
	void decideVel();
public:
	FSun(int x, int y);
	~FSun();

	int getID();
	SDL_Rect getHitbox();
	enum SUN_STATES getState();

	void updateState(enum SUN_STATES uState);
	void render(SDL_Renderer* mRenderer);
	bool update();
};

//class FSun {
//	int sX, sY;
//	int curX, curY;
//	int velX, velY;
//	int despawnTime;
//	int id;
//	enum SUN_STATES state;
//	static int curSun;
//	static int time;
//
//public:
//	FSun(int x, int y);
//	void free();
//	void move();
//	void decideVel();
//	int getSX();
//	int getSY();
//	int getID();
//	void render(SDL_Renderer* mRenderer);
//
//	static void reset(SDL_Renderer* mRenderer);
//	static void summonSkySun();
//	static void updateSunCounter(SDL_Renderer* mRenderer, int add);
//	static void renderAll(SDL_Renderer* mRenderer);
//	static void loadMedia(SDL_Renderer* mRenderer);
//	static void removeSun(int id);
//	static bool findSunClick(int x, int y);
//	static int getCurSun();
//};
//
//extern vector<FSun*> vecSun;