#include <stdio.h>
#include <SDL.h>

#include "Scene.hpp"
#include "Button.hpp"
#include "FTexture.hpp"

extern FTexture winTexture;
extern Button winOKButton;

class LevelWin : public Scene {
public:
	LevelWin();
	~LevelWin();
	void render(SDL_Renderer* mRenderer);
	void update();
	void handleEvent(SDL_Event& e);
};