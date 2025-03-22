#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FPlant.hpp"
#include "FSeedPacket.hpp"
#include "FSeedPeashooter.hpp"
#include "FSeedShovel.hpp"
#include "Math.hpp"

class SlotManager {
	std::vector<FSeedPacket*> vecSeed; // included shovel
	int slotCount;

public:
	SlotManager();
	~SlotManager();

	bool handleKeyDown(int key);
	bool handleMouse(int x, int y);
	void update();
	void render(SDL_Renderer* mRenderer);
};