#pragma once
#include <stdio.h>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Constants.hpp"

class FTexture {
private:
	int w, h;
	SDL_Texture* mTexture;
	TTF_Font* font;

public:
	FTexture();
	~FTexture();

	void free();

	bool loadFromFile(SDL_Renderer* mRenderer, const std::string& path);
	bool loadFromText(SDL_Renderer* mRenderer, const std::string& text, const SDL_Color& color, const int& size);
	void renderAtPosition(SDL_Renderer* mRenderer, int x, int y, SDL_Rect* clip = NULL, double downScale = 1.0, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	int getW();
	int getH();
};