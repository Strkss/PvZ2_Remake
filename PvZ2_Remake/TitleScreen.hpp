#include "Scene.hpp"

extern FTexture titleTexture;

class TitleScreen : public Scene{
public:
	TitleScreen();
	~TitleScreen();
	void render(SDL_Renderer* mRenderer);
	void update();
	void handleEvent(SDL_Event& e);
};