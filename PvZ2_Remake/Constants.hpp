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

enum GRID_STATES {
	GRID_EMPTY,
	GRID_PEASHOOTER,
	GRID_SUNFLOWER,
	GRID_WALLNUT,
	GRID_POTATOMINE
};

const double SPRITE_DOWNSCALE = 1.35;

const int FRAME_PACING = 2;
const int SPRITE_SIZE = 390;
const int PEASHOOTER_ATTACK_FRAME = 31;
const int PEASHOOTER_IDLE_FRAME = 31;
const std::string PEASHOOTER_ATTACK_IMG = "Assets/PlantAnimation/peashooter_attack.png";
const std::string PEASHOOTER_IDLE_IMG = "Assets/PlantAnimation/peashooter_idle.png";