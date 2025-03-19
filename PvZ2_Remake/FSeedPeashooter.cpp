#include "FSeedPeashooter.hpp"

FSeedPeashooter::FSeedPeashooter() {
	rX = 10;
	rY = 100;
	cooldownTimer = 0;
	targetCooldownTimer = SEEDPACKET_PEASHOOTER_COOLDOWN;
	keyPress = SDLK_1;
	type = PEASHOOTER;
	state = SEEDPACKET_COOLDOWN;
}

FSeedPeashooter::~FSeedPeashooter() {}

void FSeedPeashooter::action(int row, int col, std::vector<FPlant*>& vecPlant, FLawn& lawn) {
	if (lawn.getGridState(row, col) == GRID_EMPTY) {
		vecPlant.push_back(new FPeashooter(row, col));
		lawn.updateGrid(row, col, GRID_PEASHOOTER);
		state = SEEDPACKET_COOLDOWN;
		cooldownTimer = 0;
	}
	else {
		state = SEEDPACKET_UNCHOSEN;
	}
}