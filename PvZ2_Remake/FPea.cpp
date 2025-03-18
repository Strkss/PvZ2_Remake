#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FTexture.hpp"
#include "Constants.hpp"
#include "FPea.hpp"

FTexture peaTexture;

bool sortByRow(FPea*& lhs, FPea*& rhs) {
	return lhs->getRow() < rhs->getRow() || (lhs->getRow() == rhs->getRow() && lhs->getHitbox().x < rhs->getHitbox().x);
}

FPea::FPea(int r, int c) {
	rX = LAWN_START_X + LAWN_GRID_WIDTH * c + LAWN_GRID_WIDTH / 2;
	rY = LAWN_START_Y + LAWN_GRID_HEIGHT * r + LAWN_GRID_HEIGHT / 2 - peaTexture.getH() / SPRITE_DOWNSCALE;
	hitbox.x = rX;
	hitbox.y = rY;
	hitbox.w = peaTexture.getW() / SPRITE_DOWNSCALE;
	hitbox.h = peaTexture.getH() / SPRITE_DOWNSCALE;
	row = r;
	isExploded = false;
	id = ++PEA_ID;
}

FPea::~FPea() {}

void FPea::move() {
	rX += PEA_VEL;
	hitbox.x += PEA_VEL;
}

int FPea::getID() {
	return id;
}

int FPea::getRow() {
	return row;
}

SDL_Rect FPea::getHitbox() {
	return hitbox;
}

void FPea::render(SDL_Renderer* mRenderer) {
	peaTexture.renderAtPosition(mRenderer, rX, rY, NULL, SPRITE_DOWNSCALE);
}

bool FPea::update() {
	if (hitbox.x > SCREEN_WIDTH) return 1;
	if (isExploded) return 1;
	return 0;
}

//std::vector<FPea*> vecPea;
//
//FPea::FPea(int x, int y, int row) {
//	this->x = x;
//	this->y = y;
//	this->row = row;
//	id = ++PEA_ID;
//	vecPea.push_back(this);
//}
//
//void FPea::free() {
//	this->x = 0;
//	this->y = 0;
//	id = 0;
//}
//
//void FPea::move() {
//	x += PEA_VEL;
//}
//
//long long FPea::getID() {
//	return id;
//}
//
//void FPea::loadMedia(SDL_Renderer* mRenderer) {
//	peaTexture.loadFromFile(mRenderer, "Assets/Etc/pea.png");
//}
//
//void FPea::render(SDL_Renderer* mRenderer) {
//	peaTexture.renderAtPosition(mRenderer, x, y, NULL, SPRITE_DOWNSCALE);
//}
//
//void FPea::renderAll(SDL_Renderer* mRenderer) {
//	std::vector<long long> despawn;
//	for (auto it : vecPea) {
//		it->render(mRenderer);
//		it->move();
//		if (it->x > SCREEN_WIDTH) {
//			despawn.push_back(it->id);
//		}
//	}
//	for (auto it : despawn) {
//		removePea(it);
//	}
//}
//
//bool FPea::removePea(long long id) {
//	int delIndex = -1;
//	for (int i = 0; i < (int)vecPea.size(); i++) {
//		if (vecPea[i]->getID() == id) {
//			delIndex = i;
//			break;
//		}
//	}
//	if (delIndex == -1) {
//		printf("Can't remove pea with id %lli\n", id);
//		return 0;
//	}
//	vecPea[delIndex]->free();
//	vecPea.erase(vecPea.begin() + delIndex);
//	printf("DONE: Removed pea with id %lli\n", id);
//	return 1;
//}
//
//void FPea::reset() {
//	PEA_ID = 0;
//	vecPea.clear();
//	printf("DONE: Reset FPea\n");
//}
//
//bool sortByRow(FPea*& lhs, FPea*& rhs) {
//	return lhs->getRow() < rhs->getRow() || (lhs->getRow() == rhs->getRow() && lhs->getX() < rhs->getX());
//}
//
//int FPea::getRow() {
//	return row;
//}
//
//int FPea::getX() {
//	return x;
//}
//
//int FPea::getY() {
//	return y;
//}