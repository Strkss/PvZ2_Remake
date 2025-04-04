#include <stdio.h>
#include <SDL.h>

#include "Scene.hpp"
#include "Button.hpp"
#include "FTexture.hpp"

extern FTexture loseTexture;
extern Button loseOKButton;

class LevelLose : public Scene {
public:
	LevelLose();
	~LevelLose();
	void render(SDL_Renderer* mRenderer);
	void update();
	void handleEvent(SDL_Event& e);
};