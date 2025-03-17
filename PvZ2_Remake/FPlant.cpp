#include "FPlant.hpp"

SDL_Rect* plantSprite[PLANT_MAX_SPRITE];
FTexture plantTexture[PLANT_MAX_SPRITE];
std::vector<FPlant*> vecPlant;
int plantAnimMaxFrame[PLANT_MAX_SPRITE];

void loadMedia(SDL_Renderer* mRenderer) {

}

int FPlant::convertToAnimID(enum PLANTS plant, enum PLANT_STATES state) {
	return plant * PLANT_STATES_NUM + state;
}

void FPlant::updateAnimID(int id) {
	animID = id;
	animFrame = 0;
}

int FPlant::getAnimID() {
	return animID;
}

void FPlant::updateAll() {
	std::vector<std::pair<int, int>> toBeRemoved;
	for (auto& it : vecPlant) {
		if (it->update()) {
			toBeRemoved.push_back(std::make_pair(it->getRow(), it->getCol()));
		}
	}
	for (auto& it : toBeRemoved) {
		removePlant(it.first, it.second);
	}
}

void FPlant::renderAll(SDL_Renderer* mRenderer) {
	for (auto& it : vecPlant) {
		it->render(mRenderer);
	}
}

void FPlant::render(SDL_Renderer* mRenderer) {
	++animFrame;
	if (animFrame / FRAME_PACING >= plantAnimMaxFrame[animID]) animFrame = 0;
	plantTexture->renderAtPosition(mRenderer, rX, rY, &plantSprite[animID][animFrame], SPRITE_DOWNSCALE);
}

void FPlant::removePlant(int row, int col) {
	int delIndex = -1;
	for (int i = 0; i < (int)vecPlant.size(); i++) {
		if (vecPlant[i]->getRow() == row && vecPlant[i]->getCol() == col) {
			delIndex = i;
			break;
		}
	}
	if (delIndex == -1) {
		printf("Can't remove plant at %d %d\n", row, col);
		return;
	}
	delete vecPlant[delIndex];
	FLawn::updateGrid(row, col, GRID_EMPTY);
	vecPlant.erase(vecPlant.begin() + delIndex);
	printf("DONE: Removed plant at %d %d\n", row, col);
	return;
}

int FPlant::getRow() {
	return row;
}

int FPlant::getCol() {
	return col;
}

void FPlant::takeDamage(int dmg) {
	hp -= dmg;
}