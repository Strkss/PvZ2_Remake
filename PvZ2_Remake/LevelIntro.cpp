#include "LevelIntro.hpp"

LevelIntro::LevelIntro(int level) {
	Mix_PlayMusic(intro, 0);
	this->level = level;
	reader.open(SCENE_LEVEL_PREFIX + "day" + std::to_string(level) + "_settings.txt");
	nextScene = GAME_STATE_NUM;
	pop = false;
	type = IN_INTRO;
	frame = 0;
	lawnVelX = 5;
	zomVelX = 5;
	lawnRX = -10;
	zomRX = SCREEN_WIDTH + 60 * zomVelX; // ban dau zombie o ngoai man hinh
	reader >> zomType;
}

LevelIntro::~LevelIntro() {
	Mix_HaltMusic();
	reader.clear();
	reader.seekg(0, std::ios::beg);
	reader.close();
}

void LevelIntro::update() { // 5 seconds intro
	++frame;
	if (frame >= 5 * 60) {
		nextScene = IN_LEVEL;
		pop = true;
		return;
	}
	// dich lawnTexture sang ben trai
	if (frame <= 2 * 60) lawnRX -= lawnVelX;
	else if (frame >= 3 * 60) lawnRX += lawnVelX;
	// dich zombie sang ben trai tu ngoai man hinh
	if (frame <= 2 * 60) zomRX -= zomVelX;
	else if (frame >= 3 * 60) zomRX += zomVelX;
}

void LevelIntro::render(SDL_Renderer* mRenderer) {
	lawnTexture.renderAtPosition(mRenderer, lawnRX, 0);
	// render Zombie
	int posY = 150;
	for (int i = 0; i < zomType; i++) {
		zombieTexture[FZombie::convertToAnimID(i, ZOMBIE_WALK, ZOMBIE_NORMAL)].renderAtPosition(mRenderer, zomRX, posY, &zombieSprite[FZombie::convertToAnimID(i, ZOMBIE_WALK, ZOMBIE_NORMAL)][0], SPRITE_DOWNSCALE);
		posY += 150;
	}
}

void LevelIntro::handleEvent(SDL_Event& e) { }