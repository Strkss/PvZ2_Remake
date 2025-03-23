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
	font = NULL;
}

FTexture::~FTexture() {
	free();
}

void FTexture::free() {
	if (mTexture != NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
	w = 0;
	h = 0;
}

bool FTexture::loadFromText(SDL_Renderer* mRenderer, const std::string& text, const SDL_Color& color, const int& size) {
	free();

	TTF_CloseFont(font);
	font = NULL;

	font = TTF_OpenFont(FONT.c_str(), size);
	if (font == NULL) {
		printf("LoadFromText -> OpenFont\n");
		return 0;
	}

	SDL_Surface* loadSurf = NULL;
	loadSurf = TTF_RenderText_Solid(font, text.c_str(), color);

	if (loadSurf == NULL) {
		printf("loadFromText -> loadSurf == NULL\n");
		return 0;
	}

	mTexture = SDL_CreateTextureFromSurface(mRenderer, loadSurf);
	w = loadSurf->w;
	h = loadSurf->h;

	if (mTexture == NULL) {
		printf("loadFromFile -> mTexture == NULL\n");
		return 0;
	}

	SDL_FreeSurface(loadSurf);

	printf("DONE: loadFromText %s\n", text.c_str());
	return 1;
}

bool FTexture::loadFromFile(SDL_Renderer * mRenderer, const std::string & path) {
	free();

	mTexture = IMG_LoadTexture(mRenderer, path.c_str());
	SDL_QueryTexture(mTexture, NULL, NULL, &w, &h);

	if (mTexture == NULL) {
		printf("loadFromFile -> mTexture == NULL\n");
		return 0;
	}

	printf("DONE: loadFromFile %s\n", path.c_str());
	return 1;
}

void FTexture::renderAtPosition(SDL_Renderer* mRenderer, int x, int y, SDL_Rect* clip, double downScale, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect renderRect = { x, y, w, h};

	if (clip != NULL) {
		renderRect.w = clip->w;
		renderRect.h = clip->h;
	}

	renderRect.w /= downScale;
	renderRect.h /= downScale;

	SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderRect, angle, center, flip);
}

int FTexture::getW() {
	return w;
}

int FTexture::getH() {
	return h;
}