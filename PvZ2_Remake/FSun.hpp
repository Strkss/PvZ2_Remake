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

	int getID() const;
	SDL_Rect getHitbox() const;
	enum SUN_STATES getState() const;

	void updateState(enum SUN_STATES uState);
	void render(SDL_Renderer* mRenderer);
	bool update();
};