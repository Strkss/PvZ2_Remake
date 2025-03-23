#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <fstream>

//#define DEBUG_HITBOX

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
extern Mix_Chunk* sfxMetalHit;

extern int PEA_ID;
extern int SUN_ID;
extern int ZOMBIE_ID;
extern int PLANT_ID;
extern int PARTICLE_ID;

extern TTF_Font* font;

const std::string FONT = "Assets/Font/font.ttf";

const SDL_Color COLOR_WHITE = { 255, 255, 255 };
const SDL_Color COLOR_RED = { 204, 0, 0 };

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

enum PLANT_STATES {
	PLANT_IDLE_0,
	PLANT_IDLE_1,
	PLANT_IDLE_2,
	PLANT_IDLE_3,
	PLANT_ATTACK,
	PLANT_SPECIAL,
	PLANT_STATES_NUM
};

enum PLANTS {
	NONE,
	PEASHOOTER,
	SUNFLOWER,
	WALLNUT,
	POTATOMINE,
	SHOVEL,
	PLANT_NUM
};

const int PLANT_MAX_SPRITE = PLANT_STATES_NUM * PLANT_NUM;

const double SPRITE_DOWNSCALE = 1.75;
const double SPRITE_DOWNSCALE_OTHER = 1.5;
const int FRAME_PACING = 2;

const int PEASHOOTER_SPRITE_SIZE = 140;
const int PEASHOOTER_ATTACK_FRAME = 31;
const int PEASHOOTER_IDLE_FRAME = 31;
const int SEEDPACKET_PEASHOOTER_COOLDOWN = 300;
const std::string PEASHOOTER_ATTACK_IMG = "Assets/PlantAnimation/peashooter_attack.png";
const std::string PEASHOOTER_IDLE_IMG = "Assets/PlantAnimation/peashooter_idle.png";

//const std::string SEEDPACKET_PEASHOOTER_IMG_UNCHOSEN = "Assets/SeedPacket/peashooter_0.png";
//const std::string SEEDPACKET_PEASHOOTER_IMG_CHOSEN = "Assets/SeedPacket/peashooter_1.png";
//const std::string SEEDPACKET_PEASHOOTER_IMG_COOLDOWN = "Assets/SeedPacket/peashooter_2.png";

const std::string SEEDPACKET_PEASHOOTER_IMG = "Assets/SeedPacket/peashooter.png";
const std::string SEEDPACKET_SHOVEL_IMG = "Assets/SeedPacket/shovel.png";

const std::string SEEDPACKET_SHOVEL_IMG_UNCHOSEN = "Assets/SeedPacket/shovel_0.png";
//const std::string SEEDPACKET_SHOVEL_IMG_CHOSEN = "Assets/SeedPacket/shovel_1.png";

enum SEEDPACKET_STATES {
	SEEDPACKET_UNCHOSEN,
	SEEDPACKET_CHOSEN,
	SEEDPACKET_COOLDOWN,
	SEEDPACKET_STATES_NUM
};

const int SUN_VALUE = 100;
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

const int PEASHOOTER_COST = 100;
const int SUNFLOWER_COST = 50;
const int WALLNUT_COST = 50;
const int POTATOMINE_COST = 25;

const std::string PEA_IMG = "Assets/Etc/pea.png";
const int PEA_VEL = 7;
const int PEA_DMG = 20;
const int PEA_SPRITE_WIDTH = 30;
const int PEA_SPRITE_HEIGHT = 30;

enum ZOMBIES {
	ZOMBIE_BASIC,
	ZOMBIE_CONE,
	ZOMBIE_BUCKET,
	ZOMBIE_FLAG,
	ZOMBIE_NUM
};

enum ZOMBIE_HP_TIERS {
	ZOMBIE_NORMAL,
	ZOMBIE_DAMAGED_0,
	ZOMBIE_DAMAGED_1,
	ZOMBIE_HP_TIERS_NUM
};

enum ZOMBIE_STATES {
	ZOMBIE_WALK,
	ZOMBIE_EAT,
	ZOMBIE_STATES_NUM
};

const int ZOMBIE_MAX_SPRITE = ZOMBIE_NUM * ZOMBIE_HP_TIERS_NUM * ZOMBIE_STATES_NUM;

const int ZOMBIE_BASIC_HP = 190;
const int ZOMBIE_CONE_HP = 560;
const int ZOMBIE_BUCKET_HP = 1290;
const int ZOMBIE_FLAG_HP = 190;

const int ZOMBIE_INV_VEL = 4;
const int ZOMBIE_DMG = 2;

const std::string ZOMBIE_BASIC_WALK_IMG = "Assets/ZombieAnimation/basic_walk.png";
const std::string ZOMBIE_BASIC_EAT_IMG = "Assets/ZombieAnimation/basic_eat.png";
const std::string ZOMBIE_DIE_IMG = "Assets/ZombieAnimation/zombie_die.png";

const std::string ZOMBIE_CONE_NORMAL_WALK_IMG = "Assets/ZombieAnimation/cone_walk_0.png";
const std::string ZOMBIE_CONE_DAMAGED_WALK_IMG = "Assets/ZombieAnimation/cone_walk_1.png";
const std::string ZOMBIE_CONE_NORMAL_EAT_IMG = "Assets/ZombieAnimation/cone_eat_0.png";
const std::string ZOMBIE_CONE_DAMAGED_EAT_IMG = "Assets/ZombieAnimation/cone_eat_1.png";

const std::string ZOMBIE_BUCKET_NORMAL_WALK_IMG = "Assets/ZombieAnimation/bucket_walk_0.png";
const std::string ZOMBIE_BUCKET_DAMAGED_WALK_IMG = "Assets/ZombieAnimation/bucket_walk_1.png";
const std::string ZOMBIE_BUCKET_NORMAL_EAT_IMG = "Assets/ZombieAnimation/bucket_eat_0.png";
const std::string ZOMBIE_BUCKET_DAMAGED_EAT_IMG = "Assets/ZombieAnimation/bucket_eat_1.png";

const std::string ZOMBIE_FLAG_WALK_IMG = "Assets/ZombieAnimation/flag_walk.png";
const std::string ZOMBIE_FLAG_EAT_IMG = "Assets/ZombieAnimation/flag_eat.png";

const int ZOMBIE_BASIC_WALK_FRAME = 90;
const int ZOMBIE_BASIC_WALK_SPRITE_WIDTH = 182;
const int ZOMBIE_BASIC_WALK_SPRITE_HEIGHT = 254;

const int ZOMBIE_BASIC_EAT_FRAME = 259;
const int ZOMBIE_BASIC_EAT_SPRITE_WIDTH = 155;
const int ZOMBIE_BASIC_EAT_SPRITE_HEIGHT = 250;

const int ZOMBIE_FLAG_WALK_FRAME = 90;
const int ZOMBIE_FLAG_WALK_SPRITE_WIDTH = 221;
const int ZOMBIE_FLAG_WALK_SPRITE_HEIGHT = 284;

const int ZOMBIE_FLAG_EAT_FRAME = 121;
const int ZOMBIE_FLAG_EAT_SPRITE_WIDTH = 189;
const int ZOMBIE_FLAG_EAT_SPRITE_HEIGHT = 274;

const int ZOMBIE_DIE_FRAME = 55;
const int ZOMBIE_DIE_SPRITE_WIDTH = 208;
const int ZOMBIE_DIE_SPRITE_HEIGHT = 169;

enum PARTICLES {
	ZOMBIE_DEAD,
	PEA_EXPLODED,
	PARTICLE_NUM
};

const int PARTICLE_MAX_SPRITE = PARTICLE_NUM;

enum ATTACK_RANGES {
	DEFENSIVE,
	ONE_ROW_AHEAD,
	THREE_BY_THREE_SQUARE,
	ONE_TILE,
	ATTACK_RANGE_NUM
};

const int WAVE_DELAY = 1500;

const std::string WAVE_INFO = "Assets/Level/wave.txt";

const std::string PROGRESS_ZOMBIE_IMG = "Assets/UI/progress_meter_zombie.png";
const std::string PROGRESS_FLAG_IMG = "Assets/UI/progress_meter_flag_full.png";
const std::string PROGRESS_METER_IMG = "Assets/UI/progress_meter.png";
const std::string PROGRESS_FILL_IMG = "Assets/UI/progress_meter_fill_pixel.png";

const int PROGRESS_MAX_FILL = 12;
const std::string PROGRESS_FLAG_TEXT = "A HUGE WAVE OF ZOMBIES IS APPROACHING!";

const std::string LEVEL_WON_IMG = "Assets/UI/level_won_screen.png";
const std::string LEVEL_LOST_IMG = "Assets/UI/level_lost_screen.png";

enum GAME_STATES {
	IN_LEVEL,
	IN_INTRO,
	IN_LOSE,
	IN_WON,
	IN_REALM,
	GAME_STATE_NUM
};