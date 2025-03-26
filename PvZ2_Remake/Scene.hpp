#pragma once
#include <stdio.h>
#include <SDL.h>

class Scene {
public:
	enum GAME_STATES type;
	virtual ~Scene() = 0;
	virtual void render(SDL_Renderer* mRenderer) = 0;
	virtual void update() = 0;
	virtual void handleEvent(SDL_Event& e) = 0;
};