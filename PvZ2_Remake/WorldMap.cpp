#include "WorldMap.hpp"

FTexture worldMapTexture;
Button levelButton[LEVEL_NUM + 1];
int levelChosen = 0;

WorldMap::WorldMap() {
	nextScene = GAME_STATE_NUM;
	type = IN_REALM;
	pop = false;
	Mix_HaltMusic();
	Mix_HaltChannel(-1);
	levelButton[1] = Button(299, 405, 358, 439);
	levelButton[2] = Button(-1, -1, -1, -1);
	levelButton[3] = Button(-1, -1, -1, -1);
	levelButton[4] = Button(-1, -1, -1, -1);
	levelButton[5] = Button(-1, -1, -1, -1);
}

WorldMap::~WorldMap() { 
	Mix_HaltMusic();
}

void WorldMap::render(SDL_Renderer* mRenderer) {
	worldMapTexture.renderAtPosition(mRenderer, 0, 0);
}

void WorldMap::update() { 
	if (!Mix_PlayingMusic()) Mix_PlayMusic(worldmap, INT_MAX);
}

void WorldMap::handleEvent(SDL_Event& e) {
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		for (int i = 1; i <= 5; i++) {
			if (levelButton[i].isClicked(e)) {
				nextScene = IN_INTRO;
				pop = false;
				levelChosen = i;
				break;
			}
		}
	}
}