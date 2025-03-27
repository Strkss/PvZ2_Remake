#pragma once
#include <stdio.h>
#include <SDL.h>
#include "FTexture.hpp"

class Scene {
public:
	enum GAME_STATES type;
	enum GAME_STATES nextScene;
	bool pop;
	virtual ~Scene() = 0;
	virtual void render(SDL_Renderer* mRenderer) = 0;
	virtual void update() = 0;
	virtual void handleEvent(SDL_Event& e) = 0;
};