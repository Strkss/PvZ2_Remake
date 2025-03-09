#pragma once
#include <string>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

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

