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
#include "FParticle.hpp"
#include "FProgressBar.hpp"
#include "SunManager.hpp"
#include "SlotManager.hpp"
#include "WaveManager.hpp"

class Level {
public:
	std::vector<FPlant*> vecPlant;
	std::vector<FZombie*> vecZombie;
	std::vector<FPea*> vecPea;
	std::vector<FParticle*> vecPart;
	FLawn myLawn;
	SunManager mySun;
	SlotManager mySlot;
	WaveManager* myWave;

	bool won, lost;

	Level(std::string path);
	~Level();

	void removePlant(int id);
	void removeZombie(int id);
	void removePea(int id);
	void removePart(int id);

	void render(SDL_Renderer* mRenderer);
	void update();
	void handleEvent(SDL_Event &e);
};