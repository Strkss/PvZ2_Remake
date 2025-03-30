#pragma once
#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FPlant.hpp"
#include "FSeedPacket.hpp"
#include "FSeedPeashooter.hpp"
#include "FSeedWallnut.hpp"
#include "FSeedSunflower.hpp"
#include "FSeedPotatomine.hpp"
#include "FSeedShovel.hpp"
#include "Math.hpp"

class SlotManager {
	std::vector<FSeedPacket*> vecSeed; // included shovel
	int slotCount;

public:
	SlotManager();
	~SlotManager();

	bool handleKeyDown(int key); // xu ly khi nhan phim vao seed packet
	bool handleMouse(int x, int y); // xu ly khi nhan chuot vao lawn khi da chon seed packet
	void update();
	void render(SDL_Renderer* mRenderer);
};