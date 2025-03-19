#include "FSeedShovel.hpp"

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

void FSeedShovel::action(int row, int col, std::vector<FPlant*>& vecPlant, FLawn& lawn) {
	if (lawn.getGridState(row, col) != GRID_EMPTY) {
		for (auto& it : vecPlant) {
			if (it->getRow() == row && it->getCol() == col) {
				it->takeDamage((int)1e5); // basically delete it!?
				break;
			}
		}
		lawn.updateGrid(row, col, GRID_EMPTY);
		state = SEEDPACKET_UNCHOSEN;
		cooldownTimer = 0;
	}
	else {
		state = SEEDPACKET_UNCHOSEN;
	}
}