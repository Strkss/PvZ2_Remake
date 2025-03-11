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

int main(int argc, char* argv[]) {
	initEngines();
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

	//FTexture temp;
	//temp.loadFromText(mRenderer, "YES", COLOR_WHITE, 50);

	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}
			handleEvent(e);
		}
		SDL_RenderClear(mRenderer);

		mTexture.renderAtPosition(mRenderer, -10, 0);
		FLawn::drawGridHitbox(mRenderer);
		FPeashooter::playAllAnim(mRenderer);
		FSeedPacket::renderGUI(mRenderer);
		FSun::renderAll(mRenderer);

		//temp.renderAtPosition(mRenderer, 0, 0);

		SDL_RenderPresent(mRenderer);
	}

	TTF_CloseFont(font);
	font = NULL;
	quitEngines();

	return 0;
}