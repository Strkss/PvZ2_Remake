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
	// load Peashooter idle
	int animID = FPlant::convertToAnimID(PEASHOOTER, PLANT_IDLE_0);
	plantAnimMaxFrame[animID] = PEASHOOTER_IDLE_FRAME;
	plantSprite[animID] = new SDL_Rect[PEASHOOTER_IDLE_FRAME];
	for (int i = 0; i < PEASHOOTER_IDLE_FRAME; i++) {
		plantSprite[animID][i] = {PEASHOOTER_SPRITE_SIZE * i, 0, PEASHOOTER_SPRITE_SIZE, PEASHOOTER_SPRITE_SIZE};
	}
	plantTexture[animID].loadFromFile(mRenderer, PEASHOOTER_IDLE_IMG);

	// load Peashooter attack
	animID = FPlant::convertToAnimID(PEASHOOTER, PLANT_ATTACK);
	plantAnimMaxFrame[animID] = PEASHOOTER_ATTACK_FRAME;
	plantSprite[animID] = new SDL_Rect[PEASHOOTER_ATTACK_FRAME];
	for (int i = 0; i < PEASHOOTER_ATTACK_FRAME; i++) {
		plantSprite[animID][i] = { PEASHOOTER_SPRITE_SIZE * i, 0, PEASHOOTER_SPRITE_SIZE, PEASHOOTER_SPRITE_SIZE };
	}
	plantTexture[animID].loadFromFile(mRenderer, PEASHOOTER_ATTACK_IMG);

	// load Wallnut idle 0
	animID = FPlant::convertToAnimID(WALLNUT, PLANT_IDLE_0);
	plantAnimMaxFrame[animID] = 270;
	plantSprite[animID] = new SDL_Rect[270];
	for (int i = 0; i <= 270 / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < 270) {
			plantSprite[animID][i * 10 + j] = { 112 * j, 137 * i, 112, 137 };
		}
	}
	plantTexture[animID].loadFromFile(mRenderer, WALLNUT_IDLE_0_IMG);

	//load Wallnut idle 1
	animID = FPlant::convertToAnimID(WALLNUT, PLANT_IDLE_1);
	plantAnimMaxFrame[animID] = 100;
	plantSprite[animID] = new SDL_Rect[100];
	for (int i = 0; i <= 100 / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < 100) {
			plantSprite[animID][i * 10 + j] = { 112 * j, 137 * i, 112, 137 };
		}
	}
	plantTexture[animID].loadFromFile(mRenderer, WALLNUT_IDLE_1_IMG);

	//load Wallnut idle 2
	animID = FPlant::convertToAnimID(WALLNUT, PLANT_IDLE_2);
	plantAnimMaxFrame[animID] = 100;
	plantSprite[animID] = new SDL_Rect[100];
	for (int i = 0; i <= 100 / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < 100) {
			plantSprite[animID][i * 10 + j] = { 112 * j, 137 * i, 112, 137 };
		}
	}
	plantTexture[animID].loadFromFile(mRenderer, WALLNUT_IDLE_2_IMG);

	//load Wallnut idle 3
	animID = FPlant::convertToAnimID(WALLNUT, PLANT_IDLE_3);
	plantAnimMaxFrame[animID] = 200;
	plantSprite[animID] = new SDL_Rect[200];
	for (int i = 0; i <= 200 / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < 200) {
			plantSprite[animID][i * 10 + j] = { 112 * j, 137 * i, 112, 137 };
		}
	}
	plantTexture[animID].loadFromFile(mRenderer, WALLNUT_IDLE_3_IMG);

	//load Sunflower idle
	animID = FPlant::convertToAnimID(SUNFLOWER, PLANT_IDLE_0);
	plantAnimMaxFrame[animID] = 60;
	plantSprite[animID] = new SDL_Rect[60];
	for (int i = 0; i <= 60 / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < 60) {
			plantSprite[animID][i * 10 + j] = { 116 * j, 126 * i, 116, 126 };
		}
	}
	plantTexture[animID].loadFromFile(mRenderer, SUNFLOWER_IDLE_0_IMG);

	//load Sunflower special
	animID = FPlant::convertToAnimID(SUNFLOWER, PLANT_SPECIAL);
	plantAnimMaxFrame[animID] = 60;
	plantSprite[animID] = new SDL_Rect[60];
	for (int i = 0; i <= 60 / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < 60) {
			plantSprite[animID][i * 10 + j] = { 134 * j, 155 * i, 134, 155 };
		}
	}
	plantTexture[animID].loadFromFile(mRenderer, SUNFLOWER_SPECIAL_IMG);

	printf("DONE: FPlant -> loadMedia\n");

	peaTexture.loadFromFile(mRenderer, PEA_IMG);

	printf("DONE: FPea -> loadMedia\n");

	sunTexture.loadFromFile(mRenderer, UI_SUN);
	sunCounterTexture.loadFromFile(mRenderer, UI_SUN_COUNTER);
	sunTextTexture.loadFromText(mRenderer, "50", COLOR_WHITE, 40);

	printf("DONE: FSun -> loadMedia\n");

	seedPacketMaxSprite[PEASHOOTER] = 3;
	seedPacketTexture[PEASHOOTER].loadFromFile(mRenderer, SEEDPACKET_PEASHOOTER_IMG);
	seedPacketSprite[PEASHOOTER] = new SDL_Rect[3];
	for (int i = 0; i < 3; i++) {
		seedPacketSprite[PEASHOOTER][i] = { i * 239, 0, 239, 151 };
	}

	seedPacketMaxSprite[WALLNUT] = 3;
	seedPacketTexture[WALLNUT].loadFromFile(mRenderer, SEEDPACKET_WALLNUT_IMG);
	seedPacketSprite[WALLNUT] = new SDL_Rect[3];
	for (int i = 0; i < 3; i++) {
		seedPacketSprite[WALLNUT][i] = { i * 239, 0, 239, 151 };
	}

	seedPacketMaxSprite[SUNFLOWER] = 3;
	seedPacketTexture[SUNFLOWER].loadFromFile(mRenderer, SEEDPACKET_SUNFLOWER_IMG);
	seedPacketSprite[SUNFLOWER] = new SDL_Rect[3];
	for (int i = 0; i < 3; i++) {
		seedPacketSprite[SUNFLOWER][i] = { i * 239, 0, 239, 151 };
	}

	seedPacketMaxSprite[SHOVEL] = 2;
	seedPacketTexture[SHOVEL].loadFromFile(mRenderer, SEEDPACKET_SHOVEL_IMG);
	seedPacketSprite[SHOVEL] = new SDL_Rect[2];
	for (int i = 0; i < 2; i++) {
		seedPacketSprite[SHOVEL][i] = { i * 158, 0, 158, 158 };
	}

	printf("DONE: FSeedPacket -> loadMedia\n");

	lawnTexture.loadFromFile(mRenderer, LAWN_IMG);

	printf("DONE: FLawn -> loadMedia\n");

	// load Basic Normal Walk
	animID = FZombie::convertToAnimID(ZOMBIE_BASIC, ZOMBIE_WALK, ZOMBIE_NORMAL);
	zombieAnimMaxFrame[animID] = ZOMBIE_BASIC_WALK_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_BASIC_WALK_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_BASIC_WALK_FRAME];
	for (int i = 0; i <= ZOMBIE_BASIC_WALK_FRAME / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_WALK_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_BASIC_WALK_SPRITE_WIDTH * j, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT * i, ZOMBIE_BASIC_WALK_SPRITE_WIDTH, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT };
		}
	}
	// load Basic Normal Eat
	animID = FZombie::convertToAnimID(ZOMBIE_BASIC, ZOMBIE_EAT, ZOMBIE_NORMAL);
	zombieAnimMaxFrame[animID] = ZOMBIE_BASIC_EAT_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_BASIC_EAT_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_BASIC_EAT_FRAME];
	for (int i = 0; i <= ZOMBIE_BASIC_EAT_FRAME / 10; i++) {
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_EAT_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_BASIC_EAT_SPRITE_WIDTH * j, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT * i, ZOMBIE_BASIC_EAT_SPRITE_WIDTH, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT };
		}
	}

	//load Cone Normal Walk
	animID = FZombie::convertToAnimID(ZOMBIE_CONE, ZOMBIE_WALK, ZOMBIE_NORMAL);
	zombieAnimMaxFrame[animID] = ZOMBIE_BASIC_WALK_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_CONE_NORMAL_WALK_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_BASIC_WALK_FRAME];
	for (int i = 0; i <= ZOMBIE_BASIC_WALK_FRAME / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_WALK_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_BASIC_WALK_SPRITE_WIDTH * j, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT * i, ZOMBIE_BASIC_WALK_SPRITE_WIDTH, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT };
		}
	}
	//load Cone Damaged Walk
	animID = FZombie::convertToAnimID(ZOMBIE_CONE, ZOMBIE_WALK, ZOMBIE_DAMAGED_0);
	zombieAnimMaxFrame[animID] = ZOMBIE_BASIC_WALK_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_CONE_DAMAGED_WALK_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_BASIC_WALK_FRAME];
	for (int i = 0; i <= ZOMBIE_BASIC_WALK_FRAME / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_WALK_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_BASIC_WALK_SPRITE_WIDTH * j, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT * i, ZOMBIE_BASIC_WALK_SPRITE_WIDTH, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT };
		}
	}
	//load Cone Normal Eat
	animID = FZombie::convertToAnimID(ZOMBIE_CONE, ZOMBIE_EAT, ZOMBIE_NORMAL);
	zombieAnimMaxFrame[animID] = ZOMBIE_BASIC_EAT_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_CONE_NORMAL_EAT_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_BASIC_EAT_FRAME];
	for (int i = 0; i <= ZOMBIE_BASIC_EAT_FRAME / 10; i++) {
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_EAT_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_BASIC_EAT_SPRITE_WIDTH * j, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT * i, ZOMBIE_BASIC_EAT_SPRITE_WIDTH, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT };
		}
	}
	//load Cone Damaged Eat
	animID = FZombie::convertToAnimID(ZOMBIE_CONE, ZOMBIE_EAT, ZOMBIE_DAMAGED_0);
	zombieAnimMaxFrame[animID] = ZOMBIE_BASIC_EAT_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_CONE_DAMAGED_EAT_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_BASIC_EAT_FRAME];
	for (int i = 0; i <= ZOMBIE_BASIC_EAT_FRAME / 10; i++) {
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_EAT_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_BASIC_EAT_SPRITE_WIDTH * j, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT * i, ZOMBIE_BASIC_EAT_SPRITE_WIDTH, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT };
		}
	}

	//load Bucket Normal Walk
	animID = FZombie::convertToAnimID(ZOMBIE_BUCKET, ZOMBIE_WALK, ZOMBIE_NORMAL);
	zombieAnimMaxFrame[animID] = ZOMBIE_BASIC_WALK_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_BUCKET_NORMAL_WALK_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_BASIC_WALK_FRAME];
	for (int i = 0; i <= ZOMBIE_BASIC_WALK_FRAME / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_WALK_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_BASIC_WALK_SPRITE_WIDTH * j, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT * i, ZOMBIE_BASIC_WALK_SPRITE_WIDTH, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT };
		}
	}
	//load Bucket Damaged Walk
	animID = FZombie::convertToAnimID(ZOMBIE_BUCKET, ZOMBIE_WALK, ZOMBIE_DAMAGED_0);
	zombieAnimMaxFrame[animID] = ZOMBIE_BASIC_WALK_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_BUCKET_DAMAGED_WALK_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_BASIC_WALK_FRAME];
	for (int i = 0; i <= ZOMBIE_BASIC_WALK_FRAME / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_WALK_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_BASIC_WALK_SPRITE_WIDTH * j, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT * i, ZOMBIE_BASIC_WALK_SPRITE_WIDTH, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT };
		}
	}
	//load Bucket Normal Eat
	animID = FZombie::convertToAnimID(ZOMBIE_BUCKET, ZOMBIE_EAT, ZOMBIE_NORMAL);
	zombieAnimMaxFrame[animID] = ZOMBIE_BASIC_EAT_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_BUCKET_NORMAL_EAT_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_BASIC_EAT_FRAME];
	for (int i = 0; i <= ZOMBIE_BASIC_EAT_FRAME / 10; i++) {
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_EAT_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_BASIC_EAT_SPRITE_WIDTH * j, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT * i, ZOMBIE_BASIC_EAT_SPRITE_WIDTH, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT };
		}
	}
	//load Bucket Damaged Eat
	animID = FZombie::convertToAnimID(ZOMBIE_BUCKET, ZOMBIE_EAT, ZOMBIE_DAMAGED_0);
	zombieAnimMaxFrame[animID] = ZOMBIE_BASIC_EAT_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_BUCKET_DAMAGED_EAT_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_BASIC_EAT_FRAME];
	for (int i = 0; i <= ZOMBIE_BASIC_EAT_FRAME / 10; i++) {
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_EAT_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_BASIC_EAT_SPRITE_WIDTH * j, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT * i, ZOMBIE_BASIC_EAT_SPRITE_WIDTH, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT };
		}
	}

	// load Flag Normal Walk
	animID = FZombie::convertToAnimID(ZOMBIE_FLAG, ZOMBIE_WALK, ZOMBIE_NORMAL);
	zombieAnimMaxFrame[animID] = ZOMBIE_FLAG_WALK_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_FLAG_WALK_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_FLAG_WALK_FRAME];
	for (int i = 0; i <= ZOMBIE_FLAG_WALK_FRAME / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_FLAG_WALK_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_FLAG_WALK_SPRITE_WIDTH * j, ZOMBIE_FLAG_WALK_SPRITE_HEIGHT * i, ZOMBIE_FLAG_WALK_SPRITE_WIDTH, ZOMBIE_FLAG_WALK_SPRITE_HEIGHT };
		}
	}
	// load Flag Normal Eat
	animID = FZombie::convertToAnimID(ZOMBIE_FLAG, ZOMBIE_EAT, ZOMBIE_NORMAL);
	zombieAnimMaxFrame[animID] = ZOMBIE_FLAG_EAT_FRAME;
	zombieTexture[animID].loadFromFile(mRenderer, ZOMBIE_FLAG_EAT_IMG);
	zombieSprite[animID] = new SDL_Rect[ZOMBIE_FLAG_EAT_FRAME];
	for (int i = 0; i <= ZOMBIE_FLAG_EAT_FRAME / 10; i++) { // hang = sprite_num / cot
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_FLAG_EAT_FRAME) {
			zombieSprite[animID][i * 10 + j] = { ZOMBIE_FLAG_EAT_SPRITE_WIDTH * j, ZOMBIE_FLAG_EAT_SPRITE_HEIGHT * i, ZOMBIE_FLAG_EAT_SPRITE_WIDTH, ZOMBIE_FLAG_EAT_SPRITE_HEIGHT };
		}
	}
	printf("DONE: FZombie -> loadMedia\n");

	// load dead zombie particle
	animID = ZOMBIE_DEAD;
	particleAnimMaxFrame[animID] = ZOMBIE_DIE_FRAME;
	particleTexture[animID].loadFromFile(mRenderer, ZOMBIE_DIE_IMG);
	particleSprite[animID] = new SDL_Rect[ZOMBIE_DIE_FRAME];
	for (int i = 0; i <= ZOMBIE_DIE_FRAME / 10; i++) {
		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_DIE_FRAME) {
			particleSprite[animID][i * 10 + j] = { ZOMBIE_DIE_SPRITE_WIDTH * j, ZOMBIE_DIE_SPRITE_HEIGHT * i, ZOMBIE_DIE_SPRITE_WIDTH, ZOMBIE_DIE_SPRITE_HEIGHT };
		}
	}

	printf("DONE: FParticle -> loadMedia\n");

	meterFillTexture.loadFromFile(mRenderer, PROGRESS_FILL_IMG);
	meterFlagTexture.loadFromFile(mRenderer, PROGRESS_FLAG_IMG);
	meterBarTexture.loadFromFile(mRenderer, PROGRESS_METER_IMG);
	meterZombieTexture.loadFromFile(mRenderer, PROGRESS_ZOMBIE_IMG);
	flagTextTexture.loadFromText(mRenderer, PROGRESS_FLAG_TEXT, COLOR_RED, 50);
	
	printf("DONE: FProgressBar -> loadMedia\n");
}

void closeMedia() {
	// delete plant
	for (int i = 0; i < PLANT_MAX_SPRITE; i++) {
		delete[] plantSprite[i];
		plantSprite[i] = NULL;
	}

	// delete seedpacket
	for (int i = 0; i < PLANT_NUM; i++) {
		delete[] seedPacketSprite[i];
		seedPacketSprite[i] = NULL;
	}

	// delete zombie
	for (int i = 0; i < ZOMBIE_MAX_SPRITE; i++) {
		delete[] zombieSprite[i];
		zombieSprite[i] = NULL;
	}
	return;
}