#include "WaveManager.hpp"
#include "Global.hpp"

WaveManager::WaveManager(std::string path) {
	reader.open(path.c_str());
	reader >> total >> totalFlag;
	flagged = new bool[total + 1] {0}; // wave 1 -> total
	for (int i = 0; i < totalFlag; i++) {
		int flag;
		reader >> flag;
		flagged[flag] = true;
	}
	cur = 0;
	timer = WAVE_DELAY - 18 * 60; // 18 giay truoc wave 1
	passedFlag = 0;
}

WaveManager::~WaveManager() {
	delete[] flagged;
	flagged = NULL;
	reader.clear();
	reader.seekg(0, std::ios::beg);
	reader.close();
}

void WaveManager::update() {
	++timer;
	if (spawnWave()) {
		printf("DONE: Spawned wave %d\n", cur);
	}
}

bool WaveManager::spawnWave() {
	if (reader.eof()) return 0;
	if (myLevel->vecZombie.size() > 0 && timer < WAVE_DELAY) return 0;
	if (cur == 0 && timer < WAVE_DELAY) return 0; // pause truoc wave 1
	if (myLevel->vecZombie.size() == 0 && timer < WAVE_DELAY && cur + 1 <= total && flagged[cur + 1]) { // pause truoc flag
		if (timer < WAVE_DELAY - 200) {
			timer = WAVE_DELAY - 200;
			Mix_FadeOutMusic(3000);
		}
		return 0;
	}
	if (myLevel->vecZombie.size() == 0 || timer == WAVE_DELAY) {
		timer = 0;
		++cur;
		int numBasic = 0, numCone = 0, numBucket = 0;
		reader >> numBasic >> numCone >> numBucket;
		if (flagged[cur]) { // wave nay la flag, bat music cho flag moi
			++passedFlag;
			switch (passedFlag) {
			case 1:
				Mix_PlayMusic(flag_1, INT_MAX);
				break;
			case 2:
				Mix_PlayMusic(flag_2, INT_MAX);
				break;
			case 3:
				Mix_PlayMusic(flag_3, INT_MAX);
				break;
			}
			myLevel->vecZombie.push_back(new FFlagZombie(Rand(0, 4)));
		} 
		for (int i = 0; i < numBasic; i++) {
			int smRow = Rand(0, 4);
			myLevel->vecZombie.push_back(new FBasicZombie(smRow));
		}
		for (int i = 0; i < numCone; i++) {
			int smRow = Rand(0, 4);
			myLevel->vecZombie.push_back(new FConeZombie(smRow));
		}
		for (int i = 0; i < numBucket; i++) {
			int smRow = Rand(0, 4);
			myLevel->vecZombie.push_back(new FBucketZombie(smRow));
		}
		return 1;
	}
	return 0;
}

int WaveManager::getTotalWave() {
	return total;
}

int WaveManager::getCurWave() {
	return cur;
}

int WaveManager::getTimer() {
	return timer;
}

int WaveManager::getPassedFlag() {
	return passedFlag;
}

int WaveManager::getTotalFlag() {
	return totalFlag;
}

bool WaveManager::nextFlag() {
	return cur + 1 <= total && flagged[cur + 1];
}