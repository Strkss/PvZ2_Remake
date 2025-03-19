#include <stdio.h>
#include <SDL.h>
#include <vector>
#include <string>

#include "FSun.hpp"
#include "Math.hpp"

class SunManager {
	int curSun;
	int skyTimer;
	std::vector<FSun*> vecSun;
	bool curSunChanged;

public:
	SunManager();
	~SunManager();

	void summonSkySun();
	bool handleMouse(int x, int y);
	void removeSun(int id);
	void render(SDL_Renderer* mRenderer);
	void update();
};