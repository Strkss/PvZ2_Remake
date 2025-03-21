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
		case ONE_TILE:
			if (it->getRow() == plant->getCol()) {
				plantHitbox = plant->getHitbox();
				zomHitbox = it->getHitbox();
				if (SDL_HasIntersection(&plantHitbox, &zomHitbox)) {
					damagedZom.push_back(it);
				}
			}
			break;
		case NONE:
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

//
//// Chuan hoa bang cach lay center cua sprite lam hitbox
//void checkPeaAndZombie(SDL_Renderer* mRenderer) {
//	sort(vecPea.begin(), vecPea.end(), sortExtra());
//	sort(vecZombie.begin(), vecZombie.end(), sortExtra());
//	vector<int> toBeRemoved;
//	for (int i = 0; i < (int)vecPea.size(); i++) {
//		int xPea = vecPea[i]->getX() + PEA_SPRITE_WIDTH / SPRITE_DOWNSCALE / 2;
//		int yPea = vecPea[i]->getY() + PEA_SPRITE_HEIGHT / SPRITE_DOWNSCALE / 2;
//		for (int j = 0; j < (int)vecZombie.size(); j++) {
//			enum ZOMBIE_STATES state = vecZombie[j]->getState();
//			int addW, addH;
//			if (state == ZOMBIE_WALK) {
//				addW = ZOMBIE_BASIC_WALK_SPRITE_WIDTH / SPRITE_DOWNSCALE;
//				addH = ZOMBIE_BASIC_WALK_SPRITE_HEIGHT / SPRITE_DOWNSCALE;
//			}
//			else {
//				addW = ZOMBIE_BASIC_EAT_SPRITE_WIDTH / SPRITE_DOWNSCALE;
//				addH = ZOMBIE_BASIC_EAT_SPRITE_HEIGHT / SPRITE_DOWNSCALE;
//			}
//			int curX = vecZombie[j]->getX() + LAWN_GRID_WIDTH;
//			int curY = vecZombie[j]->getY() + LAWN_GRID_HEIGHT - ZOMBIE_BASIC_WALK_SPRITE_HEIGHT / SPRITE_DOWNSCALE;
//			int xZom = curX + addW / 2;
//			int yZom = curY + addH / 2;
//			xZom -= PEA_SPRITE_WIDTH / SPRITE_DOWNSCALE;
//			yZom -= PEA_SPRITE_WIDTH / SPRITE_DOWNSCALE;
//
//			//Draw debug hitbox
//			SDL_Rect debugRect = { xZom, yZom, PEA_SPRITE_WIDTH * 2 / SPRITE_DOWNSCALE, PEA_SPRITE_WIDTH * 3 / SPRITE_DOWNSCALE };
//			SDL_Rect debugPea = { xPea, yPea, PEA_SPRITE_WIDTH / SPRITE_DOWNSCALE , PEA_SPRITE_WIDTH / SPRITE_DOWNSCALE };
//			SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0);
//			SDL_RenderDrawRect(mRenderer, &debugRect);
//			SDL_RenderDrawRect(mRenderer, &debugPea);
//
//			//printf("%d %d %d %d\n", xZom, yZom, xPea, yPea);
//			if (inRect(xPea, yPea, xZom, yZom, PEA_SPRITE_WIDTH * 2 / SPRITE_DOWNSCALE, PEA_SPRITE_WIDTH * 3 / SPRITE_DOWNSCALE)) {
//				vecZombie[j]->takeDamage(PEA_DMG);
//				toBeRemoved.push_back(vecPea[i]->getID());
//				Mix_PlayChannel(-1, sfxHit, 0);
//				break;
//			}
//		}
//	}
//	for (int x : toBeRemoved) FPea::removePea(x);
//}
//
//void detectPeashooterZombie() {
//	sort(vecPeashooter.begin(), vecPeashooter.end(), sortExtra());
//	sort(vecZombie.begin(), vecZombie.end(), sortExtra());
//	for (int i = 0; i < (int)vecPeashooter.size(); i++) {
//		bool upd = false;
//		int xPea = vecPeashooter[i]->getCol() * LAWN_GRID_WIDTH + LAWN_START_X + LAWN_GRID_WIDTH / 2;
//		for (int j = 0; j < (int)vecZombie.size(); j++) {
//			enum ZOMBIE_STATES state = vecZombie[j]->getState();
//			int addW;
//			if (state == ZOMBIE_WALK) {
//				addW = ZOMBIE_BASIC_WALK_SPRITE_WIDTH / SPRITE_DOWNSCALE;
//			}
//			else {
//				addW = ZOMBIE_BASIC_EAT_SPRITE_WIDTH / SPRITE_DOWNSCALE;
//			}
//			int curX = vecZombie[j]->getX() + LAWN_GRID_WIDTH;
//			int xZom = curX + addW / 2;
//			xZom -= PEA_SPRITE_WIDTH / SPRITE_DOWNSCALE;
//
//			if (vecPeashooter[i]->getRow() == vecZombie[j]->getRow() && xPea < xZom) {
//				upd = true;
//				break;
//			}
//		}
//		if (upd && vecPeashooter[i]->getState() == PEASHOOTER_IDLE) vecPeashooter[i]->updateState(PEASHOOTER_ATTACK);
//		else if (!upd && vecPeashooter[i]->getState() == PEASHOOTER_ATTACK) vecPeashooter[i]->updateState(PEASHOOTER_IDLE);
//	}
//}
//
//void checkZombieAndPlant(SDL_Renderer* mRenderer) {
//	sort(vecPeashooter.begin(), vecPeashooter.end(), sortExtra());
//	sort(vecZombie.begin(), vecZombie.end(), sortExtra());
//	for (int i = 0; i < (int)vecZombie.size(); i++) {
//		bool upd = false;
//		enum ZOMBIE_STATES state = vecZombie[i]->getState();
//		int addW;
//		if (state == ZOMBIE_WALK) {
//			addW = ZOMBIE_BASIC_WALK_SPRITE_WIDTH / SPRITE_DOWNSCALE;
//		}
//		else {
//			addW = ZOMBIE_BASIC_EAT_SPRITE_WIDTH / SPRITE_DOWNSCALE;
//		}
//		int curX = vecZombie[i]->getX() + LAWN_GRID_WIDTH;
//		int xZom = curX + addW / 2;
//		xZom -= PEA_SPRITE_WIDTH / SPRITE_DOWNSCALE;
//		for (int j = 0; j < (int)vecPeashooter.size(); j++) {
//			int xPea = vecPeashooter[j]->getCol() * LAWN_GRID_WIDTH + LAWN_START_X + LAWN_GRID_WIDTH / 2;
//			int dis = LAWN_GRID_WIDTH / 4;
//			if (vecPeashooter[j]->getRow() == vecZombie[i]->getRow() && xPea - dis <= xZom && xZom <= xPea + dis) {
//				upd = true;
//				vecPeashooter[j]->takeDamage(ZOMBIE_DMG);
//				if (!Mix_Playing(7)) Mix_PlayChannel(7, sfxEat, 0);
//				break;
//			}
//		}
//		if (upd && vecZombie[i]->getState() == ZOMBIE_WALK) vecZombie[i]->updateState(ZOMBIE_EAT);
//		else if (!upd && vecZombie[i]->getState() == ZOMBIE_EAT) vecZombie[i]->updateState(ZOMBIE_WALK);
//	}
//}