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

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 8, 2048) < 0) {
		if (Mix_AllocateChannels(32) != 32) {
			printf("initEngines -> Mix_OpenAudio\n");
		}
		return 0;
	}

	printf("DONE: initEngines\n");
	return 1;
}

bool loadMusic() {
	flag_0 = Mix_LoadMUS("Assets/Music/flag_0.mp3");
	if (flag_0 == NULL) {
		printf("loadMusic -> flag_0\n");
		return 0;
	}
	flag_1 = Mix_LoadMUS("Assets/Music/flag_1.mp3");
	if (flag_1 == NULL) {
		printf("loadMusic -> flag_1\n");
		return 0;
	}
	flag_2 = Mix_LoadMUS("Assets/Music/flag_2.mp3");
	if (flag_2 == NULL) {
		printf("loadMusic -> flag_2\n");
		return 0;
	}
	flag_3 = Mix_LoadMUS("Assets/Music/flag_3.mp3");
	if (flag_3 == NULL) {
		printf("loadMusic -> flag_3\n");
		return 0;
	}
	intro = Mix_LoadMUS("Assets/Music/intro.mp3");
	if (intro == NULL) {
		printf("loadMusic -> intro\n");
		return 0;
	}
	won = Mix_LoadMUS("Assets/Music/won.mp3");
	if (won == NULL) {
		printf("loadMusic -> won\n");
		return 0;
	}
	lost = Mix_LoadMUS("Assets/Music/lost.mp3");
	if (lost == NULL) {
		printf("loadMusic -> lost\n");
		return 0;
	}
	title = Mix_LoadMUS("Assets/Music/title.mp3");
	if (title == NULL) {
		printf("loadMusic -> title\n");
		return 0;
	}
	worldmap = Mix_LoadMUS("Assets/Music/worldmap.mp3");
	if (worldmap == NULL) {
		printf("loadMusic -> worldmap\n");
		return 0;
	}
	sfxEat = Mix_LoadWAV("Assets/SFX/eat.mp3");
	if (sfxEat == NULL) {
		printf("loadMusic -> sfxEat\n");
		return 0;
	}
	sfxExplode = Mix_LoadWAV("Assets/SFX/explode.mp3");
	if (sfxExplode == NULL) {
		printf("loadMusic -> sfxExplode\n");
		return 0;
	}
	sfxHit = Mix_LoadWAV("Assets/SFX/hit.mp3");
	if (sfxHit == NULL) {
		printf("loadMusic -> sfxHit\n");
		return 0;
	}
	sfxPlant = Mix_LoadWAV("Assets/SFX/plant.mp3");
	if (sfxPlant == NULL) {
		printf("loadMusic -> sfxPlant\n");
		return 0;
	}
	sfxSun = Mix_LoadWAV("Assets/SFX/sun.mp3");
	if (sfxSun == NULL) {
		printf("loadMusic -> sfxSun\n");
		return 0;
	}
	sfxBuzz = Mix_LoadWAV("Assets/SFX/buzz.mp3");
	if (sfxBuzz == NULL) {
		printf("loadMusic -> sfxBuzz\n");
		return 0;
	}
	sfxMetalHit = Mix_LoadWAV("Assets/SFX/metal_hit.mp3");
	if (sfxHit == NULL) {
		printf("loadMusic -> sfxMetalHit\n");
		return 0;
	}
	Mix_Volume(-1, 100);
	Mix_VolumeMusic(100);
	printf("DONE: loadMusic\n");
	return 1;
}

bool closeMusic() {
	Mix_FreeMusic(flag_0);
	Mix_FreeMusic(flag_1);
	Mix_FreeMusic(flag_2);
	Mix_FreeMusic(flag_3);
	Mix_FreeMusic(intro);
	Mix_FreeMusic(won);
	Mix_FreeMusic(lost);
	Mix_FreeChunk(sfxEat);
	Mix_FreeChunk(sfxExplode);
	Mix_FreeChunk(sfxHit);
	Mix_FreeChunk(sfxPlant);
	Mix_FreeChunk(sfxSun);
	Mix_FreeChunk(sfxBuzz);
	Mix_FreeChunk(sfxMetalHit);
	printf("DONE: closeMusic\n");
	return 1;
}

void quitEngines() {
	SDL_Quit();
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
}