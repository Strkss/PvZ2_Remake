#include <stdio.h>
#include <SDL.h>
#include <vector>
#include <string>

#include "FSun.hpp"
#include "Math.hpp"

class SunManager {
	int curSun;
	int skyTimer;
	bool curSunChanged;

public:
	std::vector<FSun*> vecSun;

	SunManager();
	~SunManager();

	void summonSkySun();
	bool handleMouse(int x, int y);
	void removeSun(int id);
	void render(SDL_Renderer* mRenderer);
	void update();
	int getCurSun();
	void updateCurSun(int add);
};