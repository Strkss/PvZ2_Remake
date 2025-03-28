#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FTexture.hpp"
#include "Constants.hpp"
#include "FPea.hpp"

FTexture peaTexture;

bool sortByRow(FPea*& lhs, FPea*& rhs) {
	return lhs->getRow() < rhs->getRow() || (lhs->getRow() == rhs->getRow() && lhs->getHitbox().x < rhs->getHitbox().x);
}

void FPea::move() {
	rX += PEA_VEL;
	hitbox.x += PEA_VEL;
}

int FPea::getID() const {
	return id;
}

int FPea::getRow() const {
	return row;
}

SDL_Rect FPea::getHitbox() const {
	return hitbox;
}

void FPea::render(SDL_Renderer* mRenderer) {
	peaTexture.renderAtPosition(mRenderer, rX, rY, NULL, SPRITE_DOWNSCALE);
#ifdef DEBUG_HITBOX
	SDL_GetRenderDrawColor(mRenderer, 0, 0, 0, 0);
	SDL_RenderDrawRect(mRenderer, &hitbox);
#endif	
}