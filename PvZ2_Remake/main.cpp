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
#include "FProgressBar.hpp"
#include "FPlant.hpp"

//int newGameFrame = 0, newGameAnimationX;
//
//void newGameAnimation(SDL_Renderer* mRenderer, FTexture &lawn) {
//	++newGameFrame;
//	if (newGameFrame >= 360) {
//		newGameAnimationX -= 3;
//	}
//	else if (newGameFrame <= 180){
//		newGameAnimationX += 3;
//	}
//	lawn.renderAtPosition(mRenderer, -10 - newGameAnimationX, 0);
//}
//
//void startNewGame(SDL_Renderer* mRenderer) {
//	resetSeedPacket();
//	FLawn::initGrid();
//	FPea::reset();
//	FPeashooter::reset();
//	FSeedPacket::reset();
//	FSun::reset(mRenderer);
//	FZombie::reset();
//	resetLevel();
//	FProgressBar::init();
//	newGameFrame = 0;
//}

int main(int argc, char* argv[]) {
	initEngines();
	loadMusic();
	SDL_Renderer* mRenderer = NULL;
	SDL_Window* mWindow = NULL;
	
	createWindow(mWindow);
	createRenderer(mRenderer, mWindow);

	loadMedia(mRenderer);
	
	//FLawn::initGrid();
	//FProgressBar::init();
	//FPeashooter::loadMedia(mRenderer);
	//FSeedPacket::loadMedia(mRenderer);
	//FSun::loadMedia(mRenderer);
	//FPea::loadMedia(mRenderer);
	//FZombie::loadMedia(mRenderer);
	//FProgressBar::loadMedia(mRenderer);

	//FTexture levelWonScreen, levelLostScreen;
	//levelWonScreen.loadFromFile(mRenderer, LEVEL_WON_IMG);
	//levelLostScreen.loadFromFile(mRenderer, LEVEL_LOST_IMG);
	//bool introPlaying = 0, levelPlaying = 0, resultPlaying = 0, levelFirstFrame = 1;

	//bool quit = false;
	//SDL_Event e;
	//while (!quit) {
	//	while (SDL_PollEvent(&e)) {
	//		if (e.type == SDL_QUIT) {
	//			quit = true;
	//			break;
	//		}
	//		if (!levelLost && !levelWon) handleEvent(mRenderer, e);
	//		if ((levelLost || levelWon) && (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)) {
	//			levelFirstFrame = 1;
	//			resultPlaying = 0;
	//			levelPlaying = 0;
	//			introPlaying = 0;
	//			levelWon = false;
	//			levelLost = false;
	//			startNewGame(mRenderer);
	//		}
	//	}

	//	if (levelFirstFrame) {
	//		introPlaying = 1;
	//		Mix_PlayMusic(intro, 0);
	//		levelFirstFrame = 0;
	//	}

	//	SDL_RenderClear(mRenderer);
	//	
	//	if (newGameFrame <= 540) { // 9 giay intro
	//		newGameAnimation(mRenderer, lawnTexture);
	//	}
	//	else if (!levelLost && !levelWon) {
	//		if (Mix_PlayingMusic() == 0) {
	//			Mix_PlayMusic(flag_0, INT_MAX);
	//			introPlaying = false;
	//			levelPlaying = true;
	//		}
	//		FLawn::drawGridHitbox(mRenderer);
	//		FPeashooter::renderAll(mRenderer);
	//		refreshSeedPacket();
	//		FSeedPacket::renderGUI(mRenderer);
	//		FPea::renderAll(mRenderer);
	//		FZombie::renderAll(mRenderer);
	//		checkPeaAndZombie(mRenderer);
	//		detectPeashooterZombie();
	//		checkZombieAndPlant();
	//		FSun::renderAll(mRenderer);
	//		FProgressBar::renderAll(mRenderer);
	//	}
	//	else if (levelWon) {
	//		if (introPlaying || levelPlaying) {
	//			Mix_HaltMusic();
	//			introPlaying = false;
	//			levelPlaying = false;
	//		}
	//		else if (!Mix_PlayingMusic() && !resultPlaying) {
	//			Mix_PlayMusic(won, 0);
	//			resultPlaying = true;
	//		}
	//		levelWonScreen.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 - levelWonScreen.getW() / 2 / 0.5, SCREEN_HEIGHT / 2 - levelWonScreen.getH() / 2 / 0.5, NULL, 0.5);
	//	}
	//	else if (levelLost) {
	//		if (introPlaying || levelPlaying) {
	//			Mix_HaltMusic();
	//			introPlaying = false;
	//			levelPlaying = false;
	//		}
	//		else if (!Mix_PlayingMusic() && !resultPlaying) {
	//			Mix_PlayMusic(lost, 0);
	//			resultPlaying = true;
	//		}
	//		levelLostScreen.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 - levelLostScreen.getW() / 2 / SPRITE_DOWNSCALE, 0, NULL, SPRITE_DOWNSCALE);
	//	}

	//	SDL_RenderPresent(mRenderer);
	//}

	TTF_CloseFont(font);
	font = NULL;
	closeMusic();
	quitEngines();

	return 0;
}