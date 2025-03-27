#include <stdio.h>
#include <SDL.h>

#include "FLawn.hpp"
#include "Scene.hpp"
#include "Math.hpp"
#include "FZombie.hpp"

class LevelIntro : public Scene {
private:
	int level;
	std::ifstream reader;
	int frame;
	int lawnRX, lawnVelX;
	int zomType;
	int zomRX, zomVelX;
public:
	LevelIntro(int level);
	~LevelIntro();
	void render(SDL_Renderer* mRenderer);
	void update();
	void handleEvent(SDL_Event& e);
};