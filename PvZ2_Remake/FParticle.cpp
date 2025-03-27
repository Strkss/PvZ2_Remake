#include "FParticle.hpp"

FTexture particleTexture[PARTICLE_NUM];
SDL_Rect* particleSprite[PARTICLE_NUM];
int particleAnimMaxFrame[PARTICLE_NUM];

void FParticle::render(SDL_Renderer* mRenderer) {
	particleTexture[animID].renderAtPosition(mRenderer, rX, rY, &particleSprite[animID][animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
}

bool FParticle::update() {
	++animFrame;
	if (animFrame / FRAME_PACING >= particleAnimMaxFrame[animID]) return 1;
	return 0;
}
int FParticle::getID() {
	return id;
}