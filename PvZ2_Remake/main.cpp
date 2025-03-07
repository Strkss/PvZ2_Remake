#include <stdio.h>

#include "Constants.hpp"
#include "Init.hpp"
#include "RenderEngine.hpp"
#include "FTexture.hpp"
#include "FLawn.hpp"
#include "FGrid.hpp"

int main(int argc, char* argv[]) {
	initEngines();
	SDL_Renderer* mRenderer = NULL;
	SDL_Window* mWindow = NULL;
	FTexture mTexture;
	FLawn mLawn;
	createWindow(mWindow);
	createRenderer(mRenderer, mWindow);
	mTexture.loadFromFile(mRenderer, LAWN_IMG);
	mTexture.renderAtPosition(mRenderer, -10, 0);
	mLawn.drawGridHitbox(mRenderer);
	
	SDL_RenderPresent(mRenderer);

	

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
	}

	quitEngines();

	return 0;
}