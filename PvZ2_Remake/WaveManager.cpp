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
}

WaveManager::~WaveManager() {
	delete[] flagged;
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
	if (myLevel->vecZombie.size() == 0 && timer < WAVE_DELAY && cur + 1 <= total && flagged[cur + 1]) return 0; // pause truoc flag wave
	if (myLevel->vecZombie.size() == 0 || timer == WAVE_DELAY) {
		timer = 0;
		++cur;
		int numZom;
		reader >> numZom;
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