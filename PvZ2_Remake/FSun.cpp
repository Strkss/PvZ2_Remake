#include <stdio.h>
#include <SDL.h>
#include <vector>
#include <string>
#include <cmath>

#include "FTexture.hpp"
#include "FSun.hpp"
#include "Math.hpp"

FTexture sun, sunCounter, sunText;

FSun::FSun(int x, int y) {
	rX = x;
	rY = y;
	decideVel(velX, velY);
	hitbox.x = rX;
	hitbox.y = rY;
	hitbox.w = sun.getW() / SPRITE_DOWNSCALE;
	hitbox.h = sun.getH() / SPRITE_DOWNSCALE;
	state = SUN_STILL;
	timer = 0;
	id = ++SUN_ID;
}

FSun::~FSun() { }

void FSun::move() {
	rX += SUN_VEL;
	rY += SUN_VEL;
	hitbox.x += SUN_VEL;
	hitbox.y += SUN_VEL;
}

void FSun::decideVel(int& velX, int& velY) {
	int dis = getDistance(rX, rY, 120, 30); // Lay khoang cach den SunCounter
	int disX = abs(rX - 120);
	int disY = abs(rX - 30);
	int frameTaken = dis / SUN_VEL;
	velX = disX / frameTaken;
	velY = disY / frameTaken;
}

SDL_Rect FSun::getHitbox() {
	return hitbox;
}

int FSun::getID() {
	return id;
}

enum SUN_STATES FSun::getState() {
	return state;
}

void FSun::render(SDL_Renderer* mRenderer) {
	sunTexture.renderAtPosition(mRenderer, rX, rY, NULL, SPRITE_DOWNSCALE);
}

void FSun::updateState(enum SUN_STATES uState) {
	state = uState;
}

bool FSun::update() {
	++timer;
	if (state == SUN_MOVE) move();
	if (inSourceRect(rX, rY, 150, 50) || (state == SUN_STILL && timer >= SUN_DESPAWN_TIME)) return 1;
	return 0;
}

//void FSun::loadMedia(SDL_Renderer* mRenderer) {
//	sun.loadFromFile(mRenderer, UI_SUN);
//	sunCounter.loadFromFile(mRenderer, UI_SUN_COUNTER);
//	sunText.loadFromText(mRenderer, "200", COLOR_WHITE, 40);
//}
//
//void FSun::render(SDL_Renderer* mRenderer) {
//	sun.renderAtPosition(mRenderer, curX, curY, NULL, SPRITE_DOWNSCALE);
//}
//
//void FSun::renderAll(SDL_Renderer* mRenderer) {
//	++time;
//	if (time >= 600)	summonSkySun();
//	sunCounter.renderAtPosition(mRenderer, 10, 5);
//	sunText.renderAtPosition(mRenderer, 120, 30);
//	vector<FSun*> collected;
//	vector<FSun*> despawn;
//	for (auto it : vecSun) {
//		it->render(mRenderer);
//		it->despawnTime++;
//		if (it->state == SUN_MOVE) it->move();
//		if (inSourceRect(it->curX, it->curY, 150, 50)) collected.push_back(it);
//		if (it->state == SUN_STILL && it->despawnTime >= SUN_DESPAWN_TIME) despawn.push_back(it);
//	}
//	for (auto it : collected) {
//		removeSun(it->sX, it->sY);
//		updateSunCounter(mRenderer, SUN_VALUE);
//	}
//	for (auto it : despawn) {
//		removeSun(it->sX, it->sY);
//	}
//}
//
//void FSun::updateSunCounter(SDL_Renderer* mRenderer, int add) {
//	curSun += add;
//	sunText.loadFromText(mRenderer, std::to_string(curSun), COLOR_WHITE, 40);
//}
//
//void FSun::removeSun(int id) {
//	int delIndex = -1;
//	for (int i = 0; i < (int)vecSun.size(); i++) {
//		if (vecSun[i]->getID() == id) {
//			delIndex = i;
//			break;
//		}
//	}
//	if (delIndex == -1) {
//		printf("Can't remove sun with ID %d\n", id);
//		return;
//	}
//	delete vecSun[delIndex];
//	vecSun.erase(vecSun.begin() + delIndex);
//	printf("DONE: Removed sun with ID %d\n", id);
//	return;
//}
//
//bool FSun::findSunClick(int x, int y) {
//	for (auto it : vecSun) {
//		if (inRect(x, y, it->curX, it->curY, SUN_HITBOX, SUN_HITBOX) && it->state == SUN_STILL) {
//			Mix_PlayChannel(-1, sfxSun, 0);
//			it->state = SUN_MOVE;
//			return 1;
//		}
//	}
//	return 0;
//}
//
//void FSun::summonSkySun() {
//	int x = Rand(LAWN_START_X, LAWN_END_X - SUN_HITBOX);
//	int y = Rand(LAWN_START_Y, LAWN_END_Y - SUN_HITBOX);
//	FSun* mySun = new FSun(x, y);
//	time = 0;
//}
//
//int FSun::getCurSun() {
//	return curSun;
//}
//
//void FSun::reset(SDL_Renderer* mRenderer) {
//	vecSun.clear();
//	curSun = 50;
//	time = 0;
//	sunText.loadFromText(mRenderer, std::to_string(curSun), COLOR_WHITE, 40);
//	printf("DONE: Reset FSun\n");
//}
//
//FSun::FSun(int x, int y) {
//	curX = x;
//	curY = y;
//	sX = x;
//	sY = y;
//	velX = 0;
//	velY = 0;
//	despawnTime = 0;
//	state = SUN_STILL;
//	decideVel();
//	vecSun.push_back(this);
//}
//
//void FSun::free() {
//	sX = 0;
//	curX = 0;
//	curY = 0;
//	sX = 0;
//	sY = 0;
//	velX = 0;
//	velY = 0;
//	despawnTime = 0;
//	state = SUN_STILL;
//}
//
//void FSun::decideVel() {
//	int dis = getDistance(sX, sY, 120, 30);
//	int disX = abs(sX - 120);
//	int disY = abs(sY - 30);
//	int frameTaken = dis / SUN_VEL;
//	velX = disX / frameTaken;
//	velY = disY / frameTaken;
//}
//
//void FSun::move() {
//	curX -= velX;
//	curY -= velY;
//}
//
//int FSun::getSX() {
//	return sX;
//}
//
//int FSun::getSY() {
//	return sY;
//}
//
//int FSun::getID() {
//	return id;
//}