#include "FSeedPeashooter.hpp"
#include "Global.hpp"

FSeedPeashooter::FSeedPeashooter(int pos) {
	rX = 10;
	rY = 100 + (pos - 1) * seedPacketSprite[PEASHOOTER][0].h / SPRITE_DOWNSCALE + (pos - 1) * 5;
	cooldownTimer = 0;
	targetCooldownTimer = SEEDPACKET_PEASHOOTER_COOLDOWN;
	keyPress = SDLK_0 + pos;
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
		Mix_PlayChannel(-1, sfxPlant, 0);
	}
	else {
		Mix_PlayChannel(-1, sfxBuzz, 0);
		state = SEEDPACKET_UNCHOSEN;
	}
}