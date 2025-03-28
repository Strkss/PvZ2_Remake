#include "PauseMenu.hpp"

FTexture musicVolumeTexture, sfxVolumeTexture, pauseMenuTexture;
Button resumeButton(SCENE_PAUSE_MENU_X + 44, SCENE_PAUSE_MENU_Y + 334, SCENE_PAUSE_MENU_X + 259, SCENE_PAUSE_MENU_Y + 453);
Button exitButton(SCENE_PAUSE_MENU_X + 362, SCENE_PAUSE_MENU_Y + 333, SCENE_PAUSE_MENU_X + 577, SCENE_PAUSE_MENU_Y + 449);
Button upMusicButton(SCENE_PAUSE_MENU_X + 460, SCENE_PAUSE_MENU_Y + 114, SCENE_PAUSE_MENU_X + 507, SCENE_PAUSE_MENU_Y + 163);
Button downMusicButton(SCENE_PAUSE_MENU_X + 298, SCENE_PAUSE_MENU_Y + 133, SCENE_PAUSE_MENU_X + 348, SCENE_PAUSE_MENU_Y + 162);
Button upSFXButton(SCENE_PAUSE_MENU_X + 454, SCENE_PAUSE_MENU_Y + 217, SCENE_PAUSE_MENU_X + 509, SCENE_PAUSE_MENU_Y + 272);
Button downSFXButton(SCENE_PAUSE_MENU_X + 293, SCENE_PAUSE_MENU_Y + 219, SCENE_PAUSE_MENU_X + 347, SCENE_PAUSE_MENU_Y + 269);

PauseMenu::PauseMenu() {
	pop = false;
	nextScene = GAME_STATE_NUM;
	type = IN_SETTINGS;
	sfxVolumeChanged = 1;
	musicVolumeChanged = 1;
	Mix_PauseMusic();
	Mix_HaltChannel(-1);
	lastTick = 0;
}

PauseMenu::~PauseMenu() { }

void PauseMenu::render(SDL_Renderer* mRenderer) {
	if (sfxVolumeChanged) {
		sfxVolumeChanged = 0;
		sfxVolumeTexture.loadFromText(mRenderer, std::to_string(Mix_Volume(-1, -1)), COLOR_WHITE, 60);
	}
	if (musicVolumeChanged) {
		musicVolumeChanged = 0;
		musicVolumeTexture.loadFromText(mRenderer, std::to_string(Mix_VolumeMusic(-1)), COLOR_WHITE, 60);
	}
	pauseMenuTexture.renderAtPosition(mRenderer, SCENE_PAUSE_MENU_X, SCENE_PAUSE_MENU_Y);
	musicVolumeTexture.renderAtPosition(mRenderer, SCENE_PAUSE_MENU_X + 386 - 20, SCENE_PAUSE_MENU_Y + 115 - 15);
	sfxVolumeTexture.renderAtPosition(mRenderer, SCENE_PAUSE_MENU_X + 386 - 20, SCENE_PAUSE_MENU_Y + 224 - 15);
}

void PauseMenu::update() {  // check xem mouse co dang hold ko phu thuoc vao event!
	 if (upMusicButton.isHeld() && SDL_GetTicks() - lastTick >= tickGap) {
		int cur = std::min(Mix_VolumeMusic(-1) + 1, 100);
		Mix_VolumeMusic(cur);
		musicVolumeChanged = 1;
		lastTick = SDL_GetTicks();
	}
	else if (upSFXButton.isHeld() && SDL_GetTicks() - lastTick >= tickGap) {
		int cur = std::min(Mix_Volume(-1, -1) + 1, 100);
		Mix_Volume(-1, cur);
		sfxVolumeChanged = 1;
		lastTick = SDL_GetTicks();
	}
	else if (downMusicButton.isHeld() && SDL_GetTicks() - lastTick >= tickGap) {
		int cur = std::max(Mix_VolumeMusic(-1) - 1, 0);
		Mix_VolumeMusic(cur);
		musicVolumeChanged = 1;
		lastTick = SDL_GetTicks();
	}
	else if (downSFXButton.isHeld() && SDL_GetTicks() - lastTick >= tickGap) {
		int cur = std::max(Mix_Volume(-1, -1) - 1, 0);
		Mix_Volume(-1, cur);
		sfxVolumeChanged = 1;
		lastTick = SDL_GetTicks();
	}
}

void PauseMenu::handleEvent(SDL_Event& e) {
	if (resumeButton.isClicked(e)) {
		pop = true;
		nextScene = SCENE_RETURN;
		Mix_ResumeMusic();
	}
	else if (exitButton.isClicked(e)) {
		pop = true;
		nextScene = IN_REALM;
	}
}