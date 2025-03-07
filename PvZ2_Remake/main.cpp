#include <stdio.h>

#include "Constants.hpp"
#include "Init.hpp"
#include "RenderEngine.hpp"
#include "FTexture.hpp"
#include "FLawn.hpp"
#include "FGrid.hpp"
#include "FPeashooter.hpp"

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
	FPeashooter myPea(0, 0);

	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN){
				int x, y;
				SDL_GetMouseState(&x, &y);
				printf("%d %d\n", x, y);
			}
		}
		SDL_RenderClear(mRenderer);

		mTexture.renderAtPosition(mRenderer, -10, 0);
		FLawn::drawGridHitbox(mRenderer);
		myPea.playAnim(mRenderer);

		SDL_RenderPresent(mRenderer);
	}

	quitEngines();

	return 0;
}