#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Constants.hpp"
#include "RenderEngine.hpp"

bool createRenderer(SDL_Renderer*& mRenderer, SDL_Window* mWindow) {
	SDL_DestroyRenderer(mRenderer);
	mRenderer = NULL;

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	if (mRenderer == NULL) {
		printf("createRenderer -> mRenderer == NULL\n");
		return 0;
	}

	printf("DONE: createRenderer\n");
	return 1;
}
