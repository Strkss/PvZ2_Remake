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
#include "FProgressBar.hpp"
#include "Scene.hpp"

class Level : public Scene{
	std::string name, path;
public:
	std::vector<FPlant*> vecPlant;
	std::vector<FZombie*> vecZombie;
	std::vector<FPea*> vecPea;
	std::vector<FParticle*> vecPart;
	FLawn myLawn;
	SunManager mySun;
	SlotManager mySlot;
	WaveManager* myWave;
	FProgressBar* myProgress;

	bool won, lost;

	Level(std::string path, std::string name);
	~Level();

	void removePlant(int id);
	void removeZombie(int id);
	void removePea(int id);
	void removePart(int id);

	void render(SDL_Renderer* mRenderer);
	void update();
	void handleEvent(SDL_Event &e);
};