#include "SlotManager.hpp"


SlotManager::SlotManager(){
	slotCount = 4;
	vecSeed.push_back(new FSeedPeashooter(1));
	vecSeed.push_back(new FSeedSunflower(2));
	vecSeed.push_back(new FSeedWallnut(3));
	vecSeed.push_back(new FSeedShovel());
}

SlotManager::~SlotManager() {
	for (auto& it : vecSeed) {
		delete it;
	}
	vecSeed.clear();
}

bool SlotManager::handleKeyDown(int key) { // khi chon cai nay thi phai bo chon cac cai khac, cho biet key nay da duoc handle chua?
	int slotChosen = -1;
	bool haveToUnchosenOther = false;
	for (int i = 0; i < (int)vecSeed.size(); i++) {
		if (key == vecSeed[i]->getKeyPress()) {
			if (vecSeed[i]->state == SEEDPACKET_CHOSEN) {
				vecSeed[i]->state = SEEDPACKET_UNCHOSEN;
				return 1;
			}
			else if (vecSeed[i]->state == SEEDPACKET_UNCHOSEN) {
				vecSeed[i]->state = SEEDPACKET_CHOSEN;
				haveToUnchosenOther = true;
			}
			slotChosen = i;
			break;
		}
	}

	if (haveToUnchosenOther) {
		for (int i = 0; i < (int)vecSeed.size(); i++) if (i != slotChosen){
			if (vecSeed[i]->state == SEEDPACKET_CHOSEN) vecSeed[i]->state = SEEDPACKET_UNCHOSEN;
		}
		return 1;
	}
	return 0;
}

bool SlotManager::handleMouse(int x, int y) {
	int row = 0, col = 0;
	if (findGrid(x, y, row, col)) {
		for (auto& it : vecSeed) {
			if (it->state == SEEDPACKET_CHOSEN) {
				it->action(row, col);
				break;
			}
		}
		return 1;
	}
	return 0;
}

void SlotManager::update() {
	for (auto& it : vecSeed) {
		it->update();
	}
}

void SlotManager::render(SDL_Renderer* mRenderer) {
	for (auto& it : vecSeed) {
		it->render(mRenderer);
	}
}