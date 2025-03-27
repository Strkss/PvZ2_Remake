#include "LevelWin.hpp"

FTexture winTexture;
Button winOKButton(601, 565, 718, 619);

LevelWin::LevelWin() {
	Mix_HaltMusic();
	Mix_PlayMusic(won, 0);
	nextScene = GAME_STATE_NUM;
	pop = false;
	type = IN_WON;
}

LevelWin::~LevelWin() {
	Mix_HaltMusic();
}

void LevelWin::update() {}

void LevelWin::render(SDL_Renderer* mRenderer) {
	winTexture.renderAtPosition(mRenderer, 0, 0);
}

void LevelWin::handleEvent(SDL_Event& e) {
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		if (winOKButton.isClicked(e)) {
			nextScene = IN_REALM;
			pop = true;
		}
	}
}