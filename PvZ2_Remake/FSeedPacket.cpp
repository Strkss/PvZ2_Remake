#include "FSeedPacket.hpp"

FTexture seedPacketTexture[PLANT_NUM];
SDL_Rect* seedPacketSprite[PLANT_NUM];
int seedPacketMaxSprite[PLANT_NUM];

void FSeedPacket::render(SDL_Renderer* mRenderer) {
	 seedPacketTexture[type].renderAtPosition(mRenderer, rX, rY, &seedPacketSprite[type][state], SPRITE_DOWNSCALE);
}

bool FSeedPacket::update() { // phai update state hay khong?
	if ((state == SEEDPACKET_UNCHOSEN || state == SEEDPACKET_CHOSEN) && cooldownTimer != 0) cooldownTimer = 0;
	if (state == SEEDPACKET_COOLDOWN) ++cooldownTimer;
	if (state == SEEDPACKET_COOLDOWN && cooldownTimer >= targetCooldownTimer) {
		state = SEEDPACKET_UNCHOSEN;
		return 1;
	}
	return 0;
}

int FSeedPacket::getKeyPress() const {
	return keyPress;
}

int FSeedPacket::getCost() const {
	return cost;
}