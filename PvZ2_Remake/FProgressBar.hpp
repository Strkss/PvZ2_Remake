#pragma once
#include <stdio.h>
#include <SDL.h>
#include <fstream>
#include <vector>
#include <string>

#include "Math.hpp"
#include "FTexture.hpp"
#include "Constants.hpp"

// Meter = MeterBar + MeterFill + meterZom + meterFlag
// Level name
// Truoc moi wave se hien levelFlag text
extern FTexture meterFillTexture, meterBarTexture, meterZombieTexture, meterFlagTexture, levelName, flagTextTexture;

class FProgressBar {
	std::string name;
	bool needToLoadName, showText;
	int* flagPos;
	int totalWave, totalFlag, progressMeterFillLen, curWave;
	void decideFlagPos();
public:
	FProgressBar(std::string name);
	~FProgressBar();
	void update();
	void render(SDL_Renderer* mRenderer);
};