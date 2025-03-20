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

int FSeedPacket::getKeyPress() {
	return keyPress;
}

//FTexture FSeedPacket::seedPacketPeashooter[SEEDPACKET_NUM];
//enum SEEDPACKET_STATES FSeedPacket::statePeashooter;
//FTexture FSeedPacket::shovel[SEEDPACKET_NUM];
//enum SEEDPACKET_STATES FSeedPacket::stateShovel;
//
//void FSeedPacket::loadMedia(SDL_Renderer* mRenderer) {
//	seedPacketPeashooter[SEEDPACKET_UNCHOSEN].loadFromFile(mRenderer, SEEDPACKET_PEASHOOTER_IMG_UNCHOSEN);
//	seedPacketPeashooter[SEEDPACKET_CHOSEN].loadFromFile(mRenderer, SEEDPACKET_PEASHOOTER_IMG_CHOSEN);
//	seedPacketPeashooter[SEEDPACKET_COOLDOWN].loadFromFile(mRenderer, SEEDPACKET_PEASHOOTER_IMG_COOLDOWN);
//
//	shovel[SEEDPACKET_UNCHOSEN].loadFromFile(mRenderer, SEEDPACKET_SHOVEL_IMG_UNCHOSEN);
//	shovel[SEEDPACKET_CHOSEN].loadFromFile(mRenderer, SEEDPACKET_SHOVEL_IMG_CHOSEN);
//	
//	printf("DONE: Loaded Seed Packet Texture\n");
//}
//
//void FSeedPacket::renderGUI(SDL_Renderer* mRenderer) {
//	seedPacketPeashooter[statePeashooter].renderAtPosition(mRenderer, 10, 100, NULL, SPRITE_DOWNSCALE);
//	shovel[stateShovel].renderAtPosition(mRenderer, 10, SCREEN_HEIGHT - 100, NULL, SPRITE_DOWNSCALE);
//}
//
//void FSeedPacket::updateState(enum PLANTS plant, enum SEEDPACKET_STATES state) {
//	switch (plant) {
//	case PEASHOOTER:
//		if (peashooterSeedPacketTime > 1) break;
//		statePeashooter = state;
//		break;
//	case SHOVEL:
//		stateShovel = state;
//		break;
//	}
//	//printf("DONE: Updated state of %d to state %d\n", plant, state);
//}
//
//void FSeedPacket::reset() {
//	statePeashooter = SEEDPACKET_UNCHOSEN;
//	stateShovel = SEEDPACKET_UNCHOSEN;
//	printf("DONE: Reset SeedPacket\n");
//}