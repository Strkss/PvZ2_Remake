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
	std::string name, path; // ten level va duong dan den file wave.txt cua level
public:
	std::vector<FPlant*> vecPlant; // vector cac plant dang co
	std::vector<FZombie*> vecZombie; // vector cac zombie dang co
	std::vector<FPea*> vecPea; // vector cac dan dang co
	std::vector<FParticle*> vecPart; // vector cac hieu ung dang co
	FLawn myLawn; // san co
	SunManager mySun; // mat troi
	SlotManager mySlot; // seed packet
	WaveManager* myWave; // wave
	FProgressBar* myProgress; // progress bar

	Level(int level);
	~Level();

	// cac ham xoa
	void removePlant(int id);
	void removeZombie(int id);
	void removePea(int id);
	void removePart(int id);

	void render(SDL_Renderer* mRenderer);
	void update();
	void handleEvent(SDL_Event &e);
};