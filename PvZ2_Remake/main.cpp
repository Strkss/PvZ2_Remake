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
#include "CollisionChecker.hpp"
#include "ZombieSpawner.hpp"

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
		FPeashooter::renderAll(mRenderer);
		FSeedPacket::renderGUI(mRenderer);
		FPea::renderAll(mRenderer);
		spawnWave();
		FZombie::renderAll(mRenderer);
		checkPeaAndZombie(mRenderer);
		detectPeashooterZombie();
		checkZombieAndPlant();
		FSun::renderAll(mRenderer);

		SDL_RenderPresent(mRenderer);
	}

	TTF_CloseFont(font);
	font = NULL;
	closeMusic();
	quitEngines();

	return 0;
}