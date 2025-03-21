#include "FSeedPeashooter.hpp"
#include "Global.hpp"

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

void FSeedPeashooter::action(int row, int col) {
	if (myLevel->myLawn.getGridState(row, col) == GRID_EMPTY && myLevel->mySun.getCurSun() >= PEASHOOTER_COST) {
		myLevel->vecPlant.push_back(new FPeashooter(row, col));
		state = SEEDPACKET_COOLDOWN;
		cooldownTimer = 0;
		myLevel->mySun.updateCurSun(-PEASHOOTER_COST);
	}
	else {
		state = SEEDPACKET_UNCHOSEN;
	}
}