#include <stdio.h>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Constants.hpp"
#include "FTexture.hpp"

FTexture::FTexture() {
	w = 0;
	h = 0;
	mTexture = NULL;
}

FTexture::~FTexture() {
	free();
}

void FTexture::free() {
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;
	w = 0;
	h = 0;
}

bool FTexture::loadFromFile(SDL_Renderer * mRenderer, const std::string & path) {
	free();

	SDL_Surface* loadSurf = NULL;
	loadSurf = IMG_Load(path.c_str());

	if (loadSurf == NULL) {
		printf("loadFromFile -> loadSurf == NULL\n");
		return 0;
	}

	mTexture = SDL_CreateTextureFromSurface(mRenderer, loadSurf);
	w = loadSurf->w;
	h = loadSurf->h;

	if (mTexture == NULL) {
		printf("loadFromFile -> mTexture == NULL\n");
		return 0;
	}

	printf("DONE: loadFromFile %s", path.c_str());
	return 1;
}

void FTexture::renderAtPosition(SDL_Renderer* mRenderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect renderRect = { x, y, w, h};

	if (clip != NULL) {
		renderRect.w = clip->w;
		renderRect.h = clip->h;
	}

	SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderRect, angle, center, flip);
}

int FTexture::getW() {
	return w;
}

int FTexture::getH() {
	return h;
}