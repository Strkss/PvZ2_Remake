#include <stdio.h>
#include <SDL.h>
#include <vector>
#include <string>

#include "FSun.hpp"
#include "Math.hpp"

class SunManager {
	int curSun; // sun hien tai
	int skyTimer; // thoi gian random sun tiep theo
	bool curSunChanged;

public:
	std::vector<FSun*> vecSun;

	SunManager();
	~SunManager();

	void summonSkySun(); // tao ra sun ngau nhien sau 10s
	bool handleMouse(int x, int y); // check xem nguoi choi click vao sun de thu thap
	void removeSun(int id);
	void render(SDL_Renderer* mRenderer);
	void update();
	int getCurSun() const;
	void updateCurSun(int add);
};