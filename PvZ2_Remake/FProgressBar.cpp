#include "FProgressBar.hpp"
#include "Global.hpp"

FTexture meterFillTexture, meterBarTexture, meterZombieTexture, meterFlagTexture, levelName, flagTextTexture;

FProgressBar::FProgressBar(std::string name) {
	this->name = name;
	needToLoadName = true;
	showText = false;
	flagPos = NULL;
	totalWave = myLevel->myWave->getTotalWave();
	totalFlag = myLevel->myWave->getTotalFlag();
	progressMeterFillLen = (546 - 2 * 19) / SPRITE_DOWNSCALE;
	curWave = 0;
	decideFlagPos();
}

FProgressBar::~FProgressBar() { 
	delete[] flagPos;
	flagPos = NULL;
}

void FProgressBar::decideFlagPos() {
	flagPos = new int[totalFlag + 1] {0};
	for (int i = 1; i <= totalFlag; i++) {
		flagPos[i] = 19 / SPRITE_DOWNSCALE + i * progressMeterFillLen / totalFlag;
	}
}

void FProgressBar::render(SDL_Renderer* mRenderer) {
	if (needToLoadName) {
		levelName.loadFromText(mRenderer, name, COLOR_WHITE, 30);
		needToLoadName = false;
	}

	levelName.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 - levelName.getW() / 2, 80);
	meterBarTexture.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 - meterBarTexture.getW() / 2 / SPRITE_DOWNSCALE, 30, NULL, SPRITE_DOWNSCALE);
	// place fill
	int maxPlacedPixel = curWave * progressMeterFillLen / totalWave;
	for (int i = 1; i <= maxPlacedPixel; i++) {
		int pos = 19 / SPRITE_DOWNSCALE + i;
		meterFillTexture.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 + meterBarTexture.getW() / 2 / SPRITE_DOWNSCALE - pos, 40);
	}
	// place flag
	for (int i = 1; i <= myLevel->myWave->getTotalFlag(); i++) {
		meterFlagTexture.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 + meterBarTexture.getW() / 2 / SPRITE_DOWNSCALE - flagPos[i] - 10, 15, NULL, SPRITE_DOWNSCALE_OTHER);
	}
	// place zomhead
	meterZombieTexture.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 + meterBarTexture.getW() / 2 / SPRITE_DOWNSCALE - 19 / SPRITE_DOWNSCALE - maxPlacedPixel - 10, 30, NULL, SPRITE_DOWNSCALE);
	// place flag text if needed
	if (showText) {
		flagTextTexture.renderAtPosition(mRenderer, LAWN_START_X, SCREEN_HEIGHT / 2);
	}
}

void FProgressBar::update() {
	curWave = myLevel->myWave->getCurWave();
	if (myLevel->myWave->getTimer() >= WAVE_DELAY - 180 && myLevel->myWave->nextFlag()) {
		showText = true;
	}
	else showText = false;
}