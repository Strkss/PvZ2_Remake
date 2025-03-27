#include "LevelLose.hpp"

FTexture loseTexture;
Button loseOKButton(597, 622, 715, 674);

LevelLose::LevelLose() {
	Mix_HaltMusic();
	Mix_PlayMusic(lost, 0);
	nextScene = GAME_STATE_NUM;
	pop = false;
	type = IN_LOSE;
}

LevelLose::~LevelLose() {
	Mix_HaltMusic();
}

void LevelLose::update() { }

void LevelLose::render(SDL_Renderer* mRenderer) {
	loseTexture.renderAtPosition(mRenderer, 0, 0);
}

void LevelLose::handleEvent(SDL_Event& e) {
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		if (loseOKButton.isClicked(e)) {
			nextScene = IN_REALM;
			pop = true;
		}
	}
}