#include "FSeedWallnut.hpp"
#include "Global.hpp"

FSeedWallnut::FSeedWallnut() {
	rX = 10;
	rY = 100 + seedPacketSprite[PEASHOOTER][0].h / SPRITE_DOWNSCALE + 5; // o duoi peashooter
	cooldownTimer = 0;
	targetCooldownTimer = SEEDPACKET_WALLNUT_COOLDOWN;
	keyPress = SDLK_2;
	type = WALLNUT;
	state = SEEDPACKET_COOLDOWN;
}

FSeedWallnut::~FSeedWallnut() {}

void FSeedWallnut::action(int row, int col) {
	if (myLevel->myLawn.getGridState(row, col) == GRID_EMPTY && myLevel->mySun.getCurSun() >= WALLNUT_COST) {
		myLevel->vecPlant.push_back(new FWallnut(row, col));
		state = SEEDPACKET_COOLDOWN;
		cooldownTimer = 0;
		myLevel->mySun.updateCurSun(-WALLNUT_COST);
		Mix_PlayChannel(-1, sfxPlant, 0);
	}
	else {
		Mix_PlayChannel(-1, sfxBuzz, 0);
		state = SEEDPACKET_UNCHOSEN;
	}
}