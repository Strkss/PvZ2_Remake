#include <stdio.h>
#include "Constants.hpp"
#include "Init.hpp"
#include "RenderEngine.hpp"

int main(int argc, char* argv[]) {
	initEngines();
	SDL_Renderer* mRenderer = NULL;
	SDL_Window* mWindow = NULL;
	createWindow(mWindow);
	createRenderer(mRenderer, mWindow);

	return 0;
}