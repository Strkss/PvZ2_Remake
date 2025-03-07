#include <stdio.h>

#include "Constants.hpp"
#include "Init.hpp"
#include "RenderEngine.hpp"
#include "FTexture.hpp"

int main(int argc, char* argv[]) {
	initEngines();
	SDL_Renderer* mRenderer = NULL;
	SDL_Window* mWindow = NULL;
	FTexture mTexture;
	createWindow(mWindow);
	createRenderer(mRenderer, mWindow);
	mTexture.loadFromFile(mRenderer, "Assets/Lawn/lawn.png");
	mTexture.renderAtPosition(mRenderer, 0, 0);
	SDL_RenderPresent(mRenderer);

	SDL_Delay(5000);

	quitEngines();

	return 0;
}