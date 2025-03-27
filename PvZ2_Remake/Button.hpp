#include <stdio.h>
#include <SDL.h>
#include "FTexture.hpp"

class Button {
	SDL_Rect box;
public:
	Button(int x, int y, int w, int h);
	~Button();
	bool isClicked(SDL_Event& e);
};