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

public:
	FTexture();
	~FTexture();

	void free();

	// load texture tu file anh
	bool loadFromFile(SDL_Renderer* mRenderer, const std::string& path);
	// load texture tu text + font + color
	bool loadFromText(SDL_Renderer* mRenderer, const std::string& text, const SDL_Color& color, const int& size);
	// lay 1 phan trong hinh chu nhat clip, render o vi tri (x, y), thuc hien thu nho, xoay, lat, ..
	void renderAtPosition(SDL_Renderer* mRenderer, int x, int y, SDL_Rect* clip = NULL, double downScale = 1.0, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	int getW() const;
	int getH() const;
};