#include <stdio.h>
#include <vector>
#include <list>
#include <SDL.h>

#include "Constants.hpp"

#include "FPlant.hpp"
#include "FSun.hpp"
#include "FZombie.hpp"
#include "FPea.hpp"
#include "FProgressBar.hpp"

#include "EventHandler.hpp"
#include "ZombieSpawner.hpp"

class Level {
	std::vector<FPlant*> vecPlant;
	std::vector<FSun*> vecSun;
	std::vector<FZombie*> vecZombie;
	std::vector<FZombie*> dedZombie;
	std::vector<FPea*> vecPea;

public:
	Level();
	~Level();

	void removePlant(int id);
	void removeZombie(int id);
	void removeDeadZombie(int id);
	void removePea(int id);
	void removeSun(int id);

	void render(SDL_Renderer* mRenderer);
	void update();
};