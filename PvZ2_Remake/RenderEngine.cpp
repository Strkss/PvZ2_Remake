#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Constants.hpp"
#include "RenderEngine.hpp"

bool createRenderer(SDL_Renderer*& mRenderer, SDL_Window* mWindow) {
	SDL_DestroyRenderer(mRenderer);
	mRenderer = NULL;

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	if (mRenderer == NULL) {
		printf("createRenderer -> mRenderer == NULL\n");
		return 0;
	}

	printf("DONE: createRenderer\n");
	return 1;
}

void loadMedia(SDL_Renderer* mRenderer) {
	plantAnimMaxFrame[FPlant::convertToAnimID(PEASHOOTER, PLANT_IDLE_0)] = PEASHOOTER_IDLE_FRAME;
	plantAnimMaxFrame[FPlant::convertToAnimID(PEASHOOTER, PLANT_ATTACK)] = PEASHOOTER_ATTACK_FRAME;
	plantSprite[FPlant::convertToAnimID(PEASHOOTER, PLANT_IDLE_0)] = new SDL_Rect[PEASHOOTER_IDLE_FRAME];
	plantSprite[FPlant::convertToAnimID(PEASHOOTER, PLANT_ATTACK)] = new SDL_Rect[PEASHOOTER_ATTACK_FRAME];

	for (int i = 0; i < PEASHOOTER_IDLE_FRAME; i++) {
		plantSprite[FPlant::convertToAnimID(PEASHOOTER, PLANT_IDLE_0)][i] = {PEASHOOTER_SPRITE_SIZE * i, 0, PEASHOOTER_SPRITE_SIZE, PEASHOOTER_SPRITE_SIZE};
	}
	for (int i = 0; i < PEASHOOTER_ATTACK_FRAME; i++) {
		plantSprite[FPlant::convertToAnimID(PEASHOOTER, PLANT_ATTACK)][i] = { PEASHOOTER_SPRITE_SIZE * i, 0, PEASHOOTER_SPRITE_SIZE, PEASHOOTER_SPRITE_SIZE };
	}
	plantTexture[FPlant::convertToAnimID(PEASHOOTER, PLANT_IDLE_0)].loadFromFile(mRenderer, PEASHOOTER_IDLE_IMG);
	plantTexture[FPlant::convertToAnimID(PEASHOOTER, PLANT_IDLE_0)].loadFromFile(mRenderer, PEASHOOTER_ATTACK_IMG);

	printf("DONE: FPlant -> loadMedia\n");

	peaTexture.loadFromFile(mRenderer, PEA_IMG);

	printf("DONE: FPea -> loadMedia\n");

	sunTexture.loadFromFile(mRenderer, UI_SUN);
	sunCounterTexture.loadFromFile(mRenderer, UI_SUN_COUNTER);
	sunTextTexture.loadFromText(mRenderer, "", COLOR_WHITE, 40);

	printf("DONE: FSun -> loadMedia\n");

	seedPacketMaxSprite[PEASHOOTER] = 3;
	seedPacketTexture[PEASHOOTER].loadFromFile(mRenderer, SEEDPACKET_PEASHOOTER_IMG);
	seedPacketSprite[PEASHOOTER] = new SDL_Rect[SEEDPACKET_STATES_NUM];
	for (int i = 0; i <= 2; i++) {
		seedPacketSprite[PEASHOOTER][i] = { i * 239, 0, 239, 151 };
	}

	seedPacketMaxSprite[SHOVEL] = 2;
	seedPacketTexture[SHOVEL].loadFromFile(mRenderer, SEEDPACKET_SHOVEL_IMG);
	seedPacketSprite[SHOVEL] = new SDL_Rect[SEEDPACKET_STATES_NUM - 1];
	for (int i = 0; i <= 1; i++) {
		seedPacketSprite[SHOVEL][i] = { i * 158, 0, 158, 158 };
	}

	printf("DONE: FSeedPacket -> loadMedia\n");
}