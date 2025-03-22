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

//void FProgressBar::init() {
//	flagIndex.clear();
//	passed = 0;
//	name = "";
//	getline(waveRead, name);
//	waveRead >> total >> flag;
//	fillPerWave = (double)PROGRESS_MAX_FILL / total;
//	displayedText = 0;
//	for (int i = 0; i < flag; i++) {
//		int idx;
//		waveRead >> idx;
//		flagIndex.push_back(idx);
//	}
//	displayedText = false;
//}
//
//void FProgressBar::loadMedia(SDL_Renderer* mRenderer) {
//	meterFillTexture.loadFromFile(mRenderer, PROGRESS_FILL_IMG);
//	meterFlagTexture.loadFromFile(mRenderer, PROGRESS_FLAG_IMG);
//	meterTexture.loadFromFile(mRenderer, PROGRESS_METER_IMG);
//	meterZombieTexture.loadFromFile(mRenderer, PROGRESS_ZOMBIE_IMG);
//	levelName.loadFromText(mRenderer, name, COLOR_WHITE, 30);
//	levelFlagText.loadFromText(mRenderer, PROGRESS_FLAG_TEXT, COLOR_RED, 50);
//	
//	printf("DONE: loaded ProgressBar texture\n");
//}
//
//void FProgressBar::renderAll(SDL_Renderer* mRenderer) {
//	levelName.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 - levelName.getW() / 2, 80);
//	meterTexture.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 - meterTexture.getW() / 2 / SPRITE_DOWNSCALE, 30, NULL, SPRITE_DOWNSCALE);
//	for (int i = 0; i < (int)flagIndex.size(); i++) if (passed + 1 == flagIndex[i]) {
//		if (!displayedText && (waveTime <= 10 || (int)vecZombie.size() == 0)) {
//			displayedText = 1;
//			waveTime = 180;
//			Mix_FadeOutMusic(180 / 60 * 1000); // 180 frame / 60 frame/second * 1000 milisecond
//		}
//		else if (displayedText && (waveTime <= 10)) {
//			displayedText = 0;
//			waveTime = 0;
//			Mix_HaltMusic();
//			switch (i) {
//			case 0:
//				Mix_PlayMusic(flag_1, INT_MAX);
//				break;
//			case 1:
//				Mix_PlayMusic(flag_2, INT_MAX);
//				break;
//			case 2:
//				Mix_PlayMusic(flag_3, INT_MAX);
//				break;
//			}
//		}
//		if (displayedText) {
//			levelFlagText.renderAtPosition(mRenderer, LAWN_START_X, SCREEN_HEIGHT / 2);
//		}
//	}
//	passed += spawnWave(displayedText);
//	for (int i = 1; i <= PROGRESS_MAX_FILL; i++) if (i <= passed * fillPerWave) { // wave tu 1 -> passed
//		meterFillTexture.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 + meterTexture.getW() / 2 / SPRITE_DOWNSCALE - i * meterFillTexture.getW() / SPRITE_DOWNSCALE - 19 / SPRITE_DOWNSCALE, 40, NULL, SPRITE_DOWNSCALE);
//	}
//	for (int idx : flagIndex) {
//		meterFlagTexture.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 + meterTexture.getW() / 2 / SPRITE_DOWNSCALE - idx * fillPerWave * meterFillTexture.getW() / SPRITE_DOWNSCALE - 19 / SPRITE_DOWNSCALE, 15, NULL, SPRITE_DOWNSCALE_OTHER);
//	}
//	meterZombieTexture.renderAtPosition(mRenderer, SCREEN_WIDTH / 2 + meterTexture.getW() / 2 / SPRITE_DOWNSCALE - passed * fillPerWave * meterFillTexture.getW() / SPRITE_DOWNSCALE - 19 / SPRITE_DOWNSCALE - meterFillTexture.getW() / SPRITE_DOWNSCALE, 30, NULL, SPRITE_DOWNSCALE);
//}