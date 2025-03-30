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
	bool needToLoadName, showText; // showText = hien text truoc khi mot dot tan cong lon cua zombie bat dau
	int* flagPos; // vi tri cua flag
	int totalWave, totalFlag, progressMeterFillLen, curWave; // tong so wave, tong so flag, chieu dai progress bar, wave hien tai
	void decideFlagPos(); // tim vi tri render flag
public:
	FProgressBar(std::string name);
	~FProgressBar();
	void update();
	void render(SDL_Renderer* mRenderer);
};