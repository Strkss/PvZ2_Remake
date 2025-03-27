#include "TitleScreen.hpp"

FTexture titleTexture;

TitleScreen::TitleScreen() {
	nextScene = GAME_STATE_NUM;
	type = IN_TITLE;
	Mix_HaltMusic();
}

TitleScreen::~TitleScreen() { 
	Mix_HaltMusic();
}

void TitleScreen::render(SDL_Renderer* mRenderer) {
	titleTexture.renderAtPosition(mRenderer, 0, 0);
}

void TitleScreen::update() {
	if (!Mix_PlayingMusic()) Mix_PlayMusic(title, INT_MAX);
}

void TitleScreen::handleEvent(SDL_Event& e) {
	if (e.type == SDL_MOUSEBUTTONDOWN && e.key.repeat == 0) {
		nextScene = IN_REALM;
	}
}