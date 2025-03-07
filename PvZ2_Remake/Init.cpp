#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Constants.hpp"
#include "Init.hpp"

bool createWindow(SDL_Window*& mWindow) {
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;

	mWindow = SDL_CreateWindow("PvZ2 - Remake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (mWindow == NULL) {
		printf("createWindow -> mWindow == NULL\n");
		return 0;
	}

	printf("DONE: createWindow\n");
	return 1;
}

bool initEngines() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		printf("initEngines -> SDL_INIT_VIDEO + SDL_INIT_AUDIO\n");
		return 0;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		printf("initEngines -> IMG_INIT_PNG\n");
		return 0;
	}

	if (TTF_Init() < 0) {
		printf("initEngines -> TTF_Init\n");
		return 0;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 16, 2048) < 0) {
		printf("initEngines -> Mix_OpenAudio\n");
		return 0;
	}

	printf("DONE: initEngines\n");
	return 1;
}

void quitEngines() {
	SDL_Quit();
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
}