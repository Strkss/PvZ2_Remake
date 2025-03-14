#include <fstream>
#include <stdio.h>
#include <SDL.h>
#include <iostream>

#include "Constants.hpp"
#include "FZombie.hpp"
#include "Math.hpp"

extern int waveTime;
extern std::ifstream waveRead;
extern bool levelWon;

bool spawnWave(bool wait);
void resetLevel();