#pragma once
#include <stdio.h>
#include <SDL.h>

#include "Scene.hpp"
#include "Button.hpp"

extern FTexture worldMapTexture;
extern Button levelButton[LEVEL_NUM + 1];
extern int levelChosen;

class WorldMap : public Scene {
public:
	WorldMap();
	~WorldMap();
	void render(SDL_Renderer* mRenderer);
	void update();
	void handleEvent(SDL_Event& e);
};