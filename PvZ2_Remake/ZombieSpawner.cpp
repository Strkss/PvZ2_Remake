//#include <stdio.h>
//#include "ZombieSpawner.hpp"
//#include "Constants.hpp"
//
//int waveTime = 0;
//std::ifstream waveRead(WAVE_INFO);
//bool levelWon = false;
//
//bool spawnWave(bool wait) {
//	if (waveRead.eof() && (int)vecZombie.size() == 0) levelWon = true;
//	if (waveRead.eof()) return 0;
//	if (wait) {
//		--waveTime;
//		return 0;
//	}
//	if ((int)vecZombie.size() == 0) waveTime = 0;
//	if (waveTime > 0) {
//		--waveTime;
//		return 0;
//	}
//	int numZom;
//	waveRead >> numZom;
//	for (int i = 0; i < numZom; i++) {
//		int row = Rand(0, 4);
//		int offset = Rand(0, LAWN_GRID_WIDTH / 2);
//		int animOffset = Rand(0, ZOMBIE_BASIC_WALK_FRAME * 2);
//		FZombie* myZom = new FZombie(LAWN_END_X - LAWN_GRID_WIDTH + offset, LAWN_START_Y + row * LAWN_GRID_HEIGHT, row, ZOMBIE_BASIC);
//		myZom->updateAnimFrame(animOffset);
//	}
//	waveTime = WAVE_DELAY;
//	return 1;
//}
//
//void resetLevel() {
//	waveTime = 0;
//	waveRead.clear();
//	waveRead.seekg(0, std::ios::beg);
//
//	printf("DONE: reset level Wave info\n");
//}