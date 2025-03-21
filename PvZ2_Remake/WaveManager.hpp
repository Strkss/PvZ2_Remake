#pragma once
#include <stdio.h>
#include <SDL.h>
#include <fstream>

#include "FZombie.hpp"
#include "FBasicZombie.hpp"
#include "Math.hpp"
#include "Constants.hpp"

class WaveManager {
	int timer; // thoi gian tinh tu luc spawn wave
	std::ifstream reader;
	int total;
	int cur;
	int totalFlag;
	bool* flagged;
public:
	WaveManager(std::string path);
	~WaveManager();

	void update();

	bool spawnWave();
	int getTotalWave();
	int getCurWave();
	int getTimer();
};