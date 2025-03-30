#include <stdio.h>
#include <SDL.h>

#include "FLawn.hpp"
#include "Scene.hpp"
#include "Math.hpp"
#include "FZombie.hpp"

class LevelIntro : public Scene {
private:
	int level; // so hieu level
	std::ifstream reader; // doc vao so loai zombie
	int frame; // frame hien tai cua scene
	int lawnRX, lawnVelX; // vi tri cua lawn va van toc
	int zomType; // so loai zombie
	int zomRX, zomVelX; // vi tri zombie va van toc
public:
	LevelIntro(int level);
	~LevelIntro();
	void render(SDL_Renderer* mRenderer);
	void update();
	void handleEvent(SDL_Event& e);
};