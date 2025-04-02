#include "CollisionChecker.hpp"

bool sortExtra::operator()(FPea*& lhs, FPea*& rhs) {
	return sortByRow(lhs, rhs);
}

bool sortExtra::operator()(FZombie*& lhs, FZombie*& rhs) {
	return sortByRow(lhs, rhs);
}

bool sortExtra::operator()(FPlant*& lhs, FPlant*& rhs) {
	return sortByRow(lhs, rhs);
}

bool checkZombieInRange(FPlant* plant, std::vector<FZombie*>& vecZom, std::vector<FZombie*>& damagedZom) {
	sort(vecZom.begin(), vecZom.end(), sortExtra());
	SDL_Rect plantHitbox;
	SDL_Rect zomHitbox;
	for (auto& it : vecZom) {
		switch (plant->getRange()) {
		case ONE_ROW_AHEAD:
			if (it->getRow() == plant->getRow()) {
				plantHitbox = plant->getHitbox();
				zomHitbox = it->getHitbox();
				if (plantHitbox.x <= zomHitbox.x) {
					return 1;
				}
			}
			break;
		case ONE_TILE: // ko can lay hitbox ma lay luon 1 grid
			if (it->getRow() == plant->getRow()) {
				plantHitbox = { LAWN_START_X + plant->getCol() * LAWN_GRID_WIDTH, LAWN_START_Y + plant->getRow() * LAWN_GRID_HEIGHT, LAWN_GRID_WIDTH , LAWN_GRID_HEIGHT };
				zomHitbox = it->getHitbox();
				if (SDL_HasIntersection(&plantHitbox, &zomHitbox)) {
					damagedZom.push_back(it);
				}
			}
			break;
		case DEFENSIVE:
			return 0;
		}
	}
	return (int)damagedZom.size();
}

bool checkPlantInRange(FZombie* zom, std::vector<FPlant*>& vecPlant, FPlant*& damagedPlant) {
	sort(vecPlant.begin(), vecPlant.end(), sortExtra());
	for (auto& it : vecPlant) if (it->getHP() > 0){
		if (it->getRow() > zom->getRow()) break;
		if (it->getRow() < zom->getRow()) continue;
		SDL_Rect plantHitbox = it->getHitbox();
		SDL_Rect zomHitbox = zom->getHitbox();
		if (SDL_HasIntersection(&plantHitbox, &zomHitbox)) {
			damagedPlant = it;
			return 1;
		}
	}
	return 0;
}

bool checkPeaExploded(FPea* pea, std::vector<FZombie*>& vecZom, FZombie*& damagedZom) {
	sort(vecZom.begin(), vecZom.end(), sortExtra());
	for (auto& it : vecZom) if (it->getHP() > 0){
		if (it->getRow() > pea->getRow()) break;
		if (it->getRow() < pea->getRow()) continue;
		SDL_Rect peaHitbox = pea->getHitbox();
		SDL_Rect zomHitbox = it->getHitbox();
		if (SDL_HasIntersection(&peaHitbox, &zomHitbox)) {
			damagedZom = it;
			return 1;
		}
	}
	return 0;
}

void doDamageToZombieGroup(std::vector<FZombie*>& vecZom, int dmg) {
	for (auto& it : vecZom) {
		it->takeDamage(dmg);
	}
}