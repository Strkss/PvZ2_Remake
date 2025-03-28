#pragma once
#include <stdio.h>
#include <SDL.h>
#include "FTexture.hpp"

extern FTexture particleTexture[PARTICLE_NUM];
extern SDL_Rect* particleSprite[PARTICLE_NUM];
extern int particleAnimMaxFrame[PARTICLE_NUM];

class FParticle { // despawn animation for pea/zombie/etc
protected:
	int rX, rY;
	int id;
	int animID;
	int animFrame;
public:
	bool update();
	void render(SDL_Renderer* mRenderer);
	int getID() const;
};