#include <stdio.h>
#include <SDL.h>
#include "FSun.hpp"

extern int peashooterSeedPacketTime;

void resetSeedPacket();
void refreshSeedPacket();
void handleEvent(SDL_Renderer* mRenderer, SDL_Event& e);
bool findGrid(int& x, int& y, int& row, int& col);
