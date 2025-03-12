#include <stdio.h>
#include "ZombieSpawner.hpp"
#include "Constants.hpp"

int waveTime = 0;
std::ifstream waveRead(WAVE_INFO);

void spawnWave() {
	if ((int)vecZombie.size() == 0) waveTime = 0;
	if (waveTime > 0) {
		--waveTime;
		return;
	}
	int numZom;
	waveRead >> numZom;
	for (int i = 0; i < numZom; i++) {
		int row = Rand(0, 4);
		int offset = Rand(0, LAWN_GRID_WIDTH / 2);
		FZombie* myZom = new FZombie(LAWN_END_X - LAWN_GRID_WIDTH + offset, LAWN_START_Y + row * LAWN_GRID_HEIGHT, row, ZOMBIE_BASIC);
	}
	waveTime = WAVE_DELAY;
}
