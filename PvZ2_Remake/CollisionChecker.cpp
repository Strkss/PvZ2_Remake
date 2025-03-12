#include "CollisionChecker.hpp"

bool sortExtra::operator()(FPea*& lhs, FPea*& rhs) {
	return sortByRow(lhs, rhs);
}

bool sortExtra::operator()(FZombie*& lhs, FZombie*& rhs) {
	return sortByRow(lhs, rhs);
}
bool sortExtra::operator()(FPeashooter*& lhs, FPeashooter*& rhs) {
	return sortByRow(lhs, rhs);
}

void checkPeaAndZombie() {
	sort(vecPea.begin(), vecPea.end(), sortExtra());
	sort(vecZombie.begin(), vecZombie.end(), sortExtra());
	int l = 0, r = 0;
	while (l < (int)vecPea.size() && r < (int)vecZombie.size()) {
		if (vecPea[l]->getRow() < vecZombie[r]->getRow()) {
			++l;
			continue;
		}
		if (vecPea[l]->getRow() > vecZombie[r]->getRow()) {
			++r;
			continue;
		}
		if (inRect(vecPea[l]->getX(), vecPea[l]->getY(), vecZombie[r]->getX() + 4 * LAWN_GRID_WIDTH / 3, vecZombie[r]->getY() + LAWN_GRID_HEIGHT / 4, 4 * LAWN_GRID_WIDTH / 3 + PEA_VEL, LAWN_GRID_HEIGHT * 3 / 4)) {
			vecZombie[r]->takeDamage(PEA_DMG);
			FPea::removePea(vecPea[l]->getID());
			Mix_PlayChannel(-1, sfxHit, 0);
			++l;
		}
		else if (vecPea[l]->getX() < vecZombie[r]->getX()) {
			++l;
		}
		else {
			++r;
		}
	}
}

void detectPeashooterZombie() {
	sort(vecPeashooter.begin(), vecPeashooter.end(), sortExtra());
	sort(vecZombie.begin(), vecZombie.end(), sortExtra());
	int l = 0, r = 0;
	while (l < (int)vecPeashooter.size() && r < (int)vecZombie.size()) {
		if (vecPeashooter[l]->getRow() < vecZombie[r]->getRow()) {
			++l;
			continue;
		}
		if (vecPeashooter[l]->getRow() > vecZombie[r]->getRow()) {
			++r;
			continue;
		}
		if (vecPeashooter[l] -> getCol() * LAWN_GRID_WIDTH + LAWN_GRID_WIDTH / 2 + LAWN_START_X < vecZombie[r]->getX() + 3 * LAWN_GRID_WIDTH / 2) {
			if (vecPeashooter[l]->getState() != PEASHOOTER_ATTACK) vecPeashooter[l]->updateState(PEASHOOTER_ATTACK);
			++l;
		}
		else {
			if (vecPeashooter[l]->getState() != PEASHOOTER_IDLE) vecPeashooter[l]->updateState(PEASHOOTER_IDLE);
			++r;
		}
	}
	for (; l < (int)vecPeashooter.size(); ++l) {
		if (vecPeashooter[l]->getState() != PEASHOOTER_IDLE) vecPeashooter[l]->updateState(PEASHOOTER_IDLE); 
	}
}