#include <stdio.h>
#include <SDL.h>

#include "FTexture.hpp"
#include "FSeedPacket.hpp"

FTexture FSeedPacket::seedPacketPeashooter[SEEDPACKET_NUM];
enum SEEDPACKET_STATES FSeedPacket::statePeashooter;

void FSeedPacket::loadMedia(SDL_Renderer* mRenderer) {
	seedPacketPeashooter[SEEDPACKET_UNCHOSEN].loadFromFile(mRenderer, SEEDPACKET_PEASHOOTER_IMG_UNCHOSEN);
	seedPacketPeashooter[SEEDPACKET_CHOSEN].loadFromFile(mRenderer, SEEDPACKET_PEASHOOTER_IMG_CHOSEN);
	seedPacketPeashooter[SEEDPACKET_COOLDOWN].loadFromFile(mRenderer, SEEDPACKET_PEASHOOTER_IMG_COOLDOWN);
	printf("DONE: Loaded Seed Packet Texture\n");
}

void FSeedPacket::renderGUI(SDL_Renderer* mRenderer) {
	seedPacketPeashooter[statePeashooter].renderAtPosition(mRenderer, 10, 50, NULL, SPRITE_DOWNSCALE);
}

void FSeedPacket::updateState(enum PLANTS plant, enum SEEDPACKET_STATES state) {
	switch (plant) {
	case PEASHOOTER:
		statePeashooter = state;
		break;
	}
	printf("DONE: Updated state of %d to state %d\n", plant, state);
}