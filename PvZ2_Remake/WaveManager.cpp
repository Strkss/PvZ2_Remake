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
	timer = 0;
	passedFlag = 0;
}

WaveManager::~WaveManager() {
	delete[] flagged;
	flagged = NULL;
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
	if (myLevel->vecZombie.size() == 0 && timer < WAVE_DELAY && cur + 1 <= total && flagged[cur + 1]) {
		if (timer < WAVE_DELAY - 200) {
			timer = WAVE_DELAY - 200;
		}
		return 0;
	}
	if (myLevel->vecZombie.size() == 0 || timer == WAVE_DELAY) {
		timer = 0;
		++cur;
		int numZom = 0;
		reader >> numZom;
		if (flagged[cur]) ++passedFlag; // wave nay la flag
		for (int i = 0; i < numZom; i++) {
			int smRow = Rand(0, 4);
			myLevel->vecZombie.push_back(new FBasicZombie(smRow));
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