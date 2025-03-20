#include "FSeedShovel.hpp"
#include "Global.hpp"

// render pos (10, SCREEN_HEIGHT - 100)
FSeedShovel::FSeedShovel() {
	rX = 10;
	rY = SCREEN_HEIGHT - 100;
	cooldownTimer = 0;
	targetCooldownTimer = 0;
	keyPress = SDLK_q;
	type = SHOVEL;
}

FSeedShovel::~FSeedShovel() {}

void FSeedShovel::action(int row, int col) {
	if (myLevel->myLawn.getGridState(row, col) != GRID_EMPTY) {
		for (auto& it : myLevel->vecPlant) {
			if (it->getRow() == row && it->getCol() == col) {
				myLevel->removePlant(it->getID());
				break;
			}
		}
		state = SEEDPACKET_UNCHOSEN;
		cooldownTimer = 0;
	}
	else {
		state = SEEDPACKET_UNCHOSEN;
	}
}