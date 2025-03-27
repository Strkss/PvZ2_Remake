#include <stdio.h>
#include <algorithm>
#include <SDL.h>
#include "Scene.hpp"
#include "Button.hpp"

extern FTexture musicVolumeTexture, sfxVolumeTexture, pauseMenuTexture;
extern Button resumeButton, exitButton, upMusicButton, downMusicButton, upSFXButton, downSFXButton;

class PauseMenu : public Scene {
private:
	bool sfxVolumeChanged, musicVolumeChanged;
public:
	PauseMenu();
	~PauseMenu();
	void render(SDL_Renderer* mRenderer);
	void update();
	void handleEvent(SDL_Event& e);
};