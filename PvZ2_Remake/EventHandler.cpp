#include <stdio.h>
#include <SDL.h>

#include "EventHandler.hpp"
#include "Constants.hpp"
#include "FPeashooter.hpp"
#include "FLawn.hpp"
#include "FSeedPacket.hpp"

static enum PLANTS chosen = NONE;
static bool shovelChosen = false;
int peashooterSeedPacketTime = 0;

bool findGrid(int& x, int& y, int& row, int& col) {
	x -= LAWN_START_X;
	y -= LAWN_START_Y;
	if (x < 0 || y < 0 || x > LAWN_END_X || y > LAWN_END_Y) return 0;
	col = x / LAWN_GRID_WIDTH;
	row = y / LAWN_GRID_HEIGHT;
	if (col >= LAWN_COLUMN_NUM || row >= LAWN_ROW_NUM) return 0;
	return 1;
}

void refreshSeedPacket() {
	if (peashooterSeedPacketTime - 1 == 0) FSeedPacket::updateState(PEASHOOTER, SEEDPACKET_UNCHOSEN);
	peashooterSeedPacketTime = std::max(peashooterSeedPacketTime - 1, 0);
}

void handleEvent(SDL_Renderer* mRenderer, SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_1:
			if (chosen == PEASHOOTER) {
				chosen = NONE;
				FSeedPacket::updateState(PEASHOOTER, SEEDPACKET_UNCHOSEN);
			}
			else {
				chosen = PEASHOOTER;
				shovelChosen = false;
				FSeedPacket::updateState(SHOVEL, SEEDPACKET_UNCHOSEN);
				FSeedPacket::updateState(PEASHOOTER, SEEDPACKET_CHOSEN);
			}
			shovelChosen = false;
			break;
		case SDLK_q:
			if (shovelChosen) {
				shovelChosen = false;
				FSeedPacket::updateState(SHOVEL, SEEDPACKET_UNCHOSEN);
			}
			else {
				chosen = NONE;
				shovelChosen = true;
				FSeedPacket::updateState(PEASHOOTER, SEEDPACKET_UNCHOSEN);
				FSeedPacket::updateState(SHOVEL, SEEDPACKET_CHOSEN);
			}
			chosen = NONE;
			break;
		}
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.key.repeat == 0) {
		int row = 0, col = 0;
		int x = 0, y = 0;
		SDL_GetMouseState(&x, &y);
		bool sunClick = false;
		if (FSun::findSunClick(x, y)) sunClick = true;
		if (findGrid(x, y, row, col) && sunClick == false) {
			switch (chosen) {
			case NONE:
				break;
			case PEASHOOTER:
				if (FLawn::getGridState(row, col) == GRID_EMPTY && peashooterSeedPacketTime == 0 && FSun::getCurSun() - PEASHOOTER_COST >= 0) {
					Mix_PlayChannel(-1, sfxPlant, 0);
					FSun::updateSunCounter(mRenderer, -PEASHOOTER_COST);
					FPeashooter* myPea = new FPeashooter(row, col);
					FSeedPacket::updateState(PEASHOOTER, SEEDPACKET_COOLDOWN);
					peashooterSeedPacketTime = SEEDPACKET_PEASHOOTER_COOLDOWN;
				}
				else {
					Mix_PlayChannel(-1, sfxBuzz, 0);
				}
				break;
			}
			if (shovelChosen) {
				switch (FLawn::getGridState(row, col)) {
				case GRID_EMPTY:
					break;
				case GRID_PEASHOOTER:
					Mix_PlayChannel(-1, sfxPlant, 0);
					FPeashooter::removePlant(row, col);
					break;
				}
			}
		}
		if (chosen != NONE) FSeedPacket::updateState(chosen, SEEDPACKET_UNCHOSEN);
		chosen = NONE;
		if (shovelChosen) FSeedPacket::updateState(SHOVEL, SEEDPACKET_UNCHOSEN);
		shovelChosen = false;
	}
}
