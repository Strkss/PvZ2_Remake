#include <stdio.h>

#include "Constants.hpp"
#include "Init.hpp"
#include "RenderEngine.hpp"
#include "FTexture.hpp"
#include "FLawn.hpp"
#include "FGrid.hpp"
#include "FPeashooter.hpp"
#include "EventHandler.hpp"
#include "FSeedPacket.hpp"
#include "FSun.hpp"
#include "FPea.hpp"
#include "FZombie.hpp"

int main(int argc, char* argv[]) {
	initEngines();
	loadMusic();
	SDL_Renderer* mRenderer = NULL;
	SDL_Window* mWindow = NULL;
	FTexture mTexture;
	createWindow(mWindow);
	createRenderer(mRenderer, mWindow);

	mTexture.loadFromFile(mRenderer, LAWN_IMG);
	FLawn::initGrid();
	FPeashooter::loadMedia(mRenderer);
	FSeedPacket::loadMedia(mRenderer);
	FSun::loadMedia(mRenderer);
	FPea::loadMedia(mRenderer);
	FZombie::loadMedia(mRenderer);
	FZombie myZombie(LAWN_END_X - LAWN_GRID_WIDTH, LAWN_END_Y - LAWN_GRID_HEIGHT, ZOMBIE_BASIC);

	//FTexture temp;
	//temp.loadFromFile(mRenderer, ZOMBIE_BASIC_EAT_IMG);

	Mix_PlayMusic(intro, 0);

	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}
			handleEvent(mRenderer, e);
		}
		refreshSeedPacket();

		if (Mix_PlayingMusic() == 0) {
			Mix_PlayMusic(flag_0, INT_MAX);
		}

		SDL_RenderClear(mRenderer);

		mTexture.renderAtPosition(mRenderer, -10, 0);
		FLawn::drawGridHitbox(mRenderer);
		FPeashooter::playAllAnim(mRenderer);
		FSeedPacket::renderGUI(mRenderer);
		FSun::renderAll(mRenderer);
		FPea::renderAll(mRenderer);
		FZombie::renderAll(mRenderer);

		/*basicWalkTexture.renderAtPosition(mRenderer, LAWN_START_X, LAWN_START_Y, &basicWalkSprite[0], SPRITE_DOWNSCALE);*/
		//myZombie.playAnim(mRenderer);
		//temp.renderAtPosition(mRenderer, 100, 100);

		SDL_RenderPresent(mRenderer);
	}

	TTF_CloseFont(font);
	font = NULL;
	closeMusic();
	quitEngines();

	return 0;
}