#pragma once
#include <stdio.h>
#include <vector>
#include <list>
#include <SDL.h>

#include "Constants.hpp"

#include "FPlant.hpp"
#include "FPeashooter.hpp"
#include "FSun.hpp"
#include "FZombie.hpp"
#include "FPea.hpp"
#include "FProgressBar.hpp"
#include "SunManager.hpp"
#include "SlotManager.hpp"

#include "EventHandler.hpp"
#include "ZombieSpawner.hpp"

class Level {
public:
	std::vector<FPlant*> vecPlant;
	std::vector<FZombie*> vecZombie;
	std::vector<FPea*> vecPea;
	FLawn myLawn;
	SunManager mySun;
	SlotManager mySlot;

	Level();
	~Level();

	void removePlant(int id);
	void removeZombie(int id);
	void removePea(int id);

	void render(SDL_Renderer* mRenderer);
	void update();
};