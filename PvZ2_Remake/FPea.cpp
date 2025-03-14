#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FTexture.hpp"
#include "Constants.hpp"
#include "FPea.hpp"

FTexture peaTexture;
std::vector<FPea*> vecPea;

FPea::FPea(int x, int y, int row) {
	this->x = x;
	this->y = y;
	this->row = row;
	id = ++PEA_ID;
	vecPea.push_back(this);
}

void FPea::free() {
	this->x = 0;
	this->y = 0;
	id = 0;
}

void FPea::move() {
	x += PEA_VEL;
}

long long FPea::getID() {
	return id;
}

void FPea::loadMedia(SDL_Renderer* mRenderer) {
	peaTexture.loadFromFile(mRenderer, "Assets/Etc/pea.png");
}

void FPea::renderAll(SDL_Renderer* mRenderer) {
	std::vector<long long> despawn;
	for (auto it : vecPea) {
		peaTexture.renderAtPosition(mRenderer, it->x, it->y, NULL, SPRITE_DOWNSCALE);
		it->move();
		if (it->x > SCREEN_WIDTH) {
			despawn.push_back(it->id);
		}
	}
	for (auto it : despawn) {
		removePea(it);
	}
}

bool FPea::removePea(long long id) {
	int delIndex = -1;
	for (int i = 0; i < (int)vecPea.size(); i++) {
		if (vecPea[i]->getID() == id) {
			delIndex = i;
			break;
		}
	}
	if (delIndex == -1) {
		printf("Can't remove pea with id %lli\n", id);
		return 0;
	}
	vecPea[delIndex]->free();
	vecPea.erase(vecPea.begin() + delIndex);
	printf("DONE: Removed pea with id %lli\n", id);
	return 1;
}

void FPea::reset() {
	PEA_ID = 0;
	vecPea.clear();
	printf("DONE: Reset FPea\n");
}

bool sortByRow(FPea*& lhs, FPea*& rhs) {
	return lhs->getRow() < rhs->getRow() || (lhs->getRow() == rhs->getRow() && lhs->getX() < rhs->getX());
}

int FPea::getRow() {
	return row;
}

int FPea::getX() {
	return x;
}

int FPea::getY() {
	return y;
}