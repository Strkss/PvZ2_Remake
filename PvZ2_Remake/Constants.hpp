#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

extern Mix_Music* flag_0;
extern Mix_Music* flag_1;
extern Mix_Music* flag_2;
extern Mix_Music* flag_3;
extern Mix_Music* intro;
extern Mix_Music* won;
extern Mix_Music* lost;

extern Mix_Chunk* sfxEat;
extern Mix_Chunk* sfxExplode;
extern Mix_Chunk* sfxHit;
extern Mix_Chunk* sfxPlant;
extern Mix_Chunk* sfxSun;
extern Mix_Chunk* sfxBuzz;

extern TTF_Font* font;
const std::string FONT = "Assets/Font/font.ttf";

const SDL_Color COLOR_WHITE = { 255, 255, 255 };

const std::string LAWN_IMG = "Assets/Lawn/lawn.png";
const int LAWN_GRID_WIDTH = 81;
const int LAWN_GRID_HEIGHT = 95;
const int LAWN_START_X = 528;
const int LAWN_START_Y = 207;
const int LAWN_END_X = 1257;
const int LAWN_END_Y = 682;
const int LAWN_COLUMN_NUM = 9;
const int LAWN_ROW_NUM = 5;

enum GRID_STATES {
	GRID_EMPTY,
	GRID_PEASHOOTER,
	GRID_SUNFLOWER,
	GRID_WALLNUT,
	GRID_POTATOMINE
};

enum PEASHOOTER_STATES {
	PEASHOOTER_IDLE,
	PEASHOOTER_ATTACK
};

enum PLANTS {
	NONE,
	PEASHOOTER,
	SUNFLOWER,
	WALLNUT,
	POTATOMINE,
	SHOVEL
};

const double SPRITE_DOWNSCALE = 1.75;
const int FRAME_PACING = 2;

const int PEASHOOTER_SPRITE_SIZE = 140;
const int PEASHOOTER_ATTACK_FRAME = 31;
const int PEASHOOTER_IDLE_FRAME = 31;
const int SEEDPACKET_PEASHOOTER_COOLDOWN = 300;
const std::string PEASHOOTER_ATTACK_IMG = "Assets/PlantAnimation/peashooter_attack.png";
const std::string PEASHOOTER_IDLE_IMG = "Assets/PlantAnimation/peashooter_idle.png";

const std::string SEEDPACKET_PEASHOOTER_IMG_UNCHOSEN = "Assets/SeedPacket/peashooter_0.png";
const std::string SEEDPACKET_PEASHOOTER_IMG_CHOSEN = "Assets/SeedPacket/peashooter_1.png";
const std::string SEEDPACKET_PEASHOOTER_IMG_COOLDOWN = "Assets/SeedPacket/peashooter_2.png";

const std::string SEEDPACKET_SHOVEL_IMG_UNCHOSEN = "Assets/SeedPacket/shovel_0.png";
const std::string SEEDPACKET_SHOVEL_IMG_CHOSEN = "Assets/SeedPacket/shovel_1.png";

enum SEEDPACKET_STATES {
	SEEDPACKET_UNCHOSEN,
	SEEDPACKET_CHOSEN,
	SEEDPACKET_COOLDOWN,
	SEEDPACKET_NUM
};

const int SUN_VALUE = 25;
const int SUN_SKYFALL_DELAY = 600;
const int SUN_DESPAWN_TIME = 500;
const int SUN_VEL = 30;
const int SUN_HITBOX = 70;
const std::string UI_SUN = "Assets/UI/sun.png";
const std::string UI_SUN_COUNTER = "Assets/UI/sun_counter.png";

enum SUN_STATES {
	SUN_STILL,
	SUN_MOVE,
	SUN_STATES_NUM
};

enum PLANT_COSTS {
	PEASHOOTER_COST = 100,
	SUNFLOWER_COST = 50,
	WALLNUT_COST = 50,
	POTATOMINE_COST = 25
};