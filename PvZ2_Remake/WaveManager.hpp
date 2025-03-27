#pragma once
#include <stdio.h>
#include <SDL.h>
#include <fstream>

#include "FZombie.hpp"
#include "FBasicZombie.hpp"
#include "FConeZombie.hpp"
#include "FBucketZombie.hpp"
#include "FFlagZombie.hpp"
#include "Math.hpp"
#include "Constants.hpp"

class WaveManager {
	int timer; // thoi gian tinh tu luc spawn wave
	std::ifstream reader;
	int total;
	int cur;
	int passedFlag; // cho biet so flag da di qua
	int totalFlag;
	bool* flagged;
	bool done;
public:
	WaveManager(std::string path);
	~WaveManager();

	void update();

	bool spawnWave();
	int getTotalWave();
	int getTotalFlag();
	int getCurWave();
	int getTimer();
	int getPassedFlag();
	bool nextFlag(); // check xem wave tiep theo la flag khong
	bool isDone();
};