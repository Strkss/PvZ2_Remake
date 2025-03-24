#include "FSeedSunflower.hpp"
#include "Global.hpp"

FSeedSunflower::FSeedSunflower(int pos) {
	rX = 10;
	rY = 100 + (pos - 1) * seedPacketSprite[PEASHOOTER][0].h / SPRITE_DOWNSCALE + (pos - 1) * 5;
	cooldownTimer = 0;
	targetCooldownTimer = SEEDPACKET_SUNFLOWER_COOLDOWN;
	keyPress = SDLK_0 + pos;
	type = SUNFLOWER;
	state = SEEDPACKET_UNCHOSEN;
}

FSeedSunflower::~FSeedSunflower() {}

void FSeedSunflower::action(int row, int col) {
	if (myLevel->myLawn.getGridState(row, col) == GRID_EMPTY && myLevel->mySun.getCurSun() >= SUNFLOWER_COST) {
		myLevel->vecPlant.push_back(new FSunflower(row, col));
		state = SEEDPACKET_COOLDOWN;
		cooldownTimer = 0;
		myLevel->mySun.updateCurSun(-SUNFLOWER_COST);
		Mix_PlayChannel(-1, sfxPlant, 0);
	}
	else {
		Mix_PlayChannel(-1, sfxBuzz, 0);
		state = SEEDPACKET_UNCHOSEN;
	}
}