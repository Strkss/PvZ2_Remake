#include "SunManager.hpp"

SunManager::SunManager() {
	curSun = 50;
	skyTimer = 0;
	curSunChanged = false;
}

SunManager::~SunManager() {
	for (auto& it : vecSun) {
		delete it;
	}
	vecSun.clear();
}

void SunManager::summonSkySun() {
	if (skyTimer >= SUN_SKYFALL_DELAY) {
		skyTimer = 0;
		vecSun.push_back(new FSun(Rand(LAWN_START_X, LAWN_END_X - sunTexture.getW()), Rand(LAWN_START_Y, LAWN_END_Y - sunTexture.getH())));
	}
}

bool SunManager::handleMouse(int x, int y) {
	SDL_Point mousePos = { x, y };
	FSun* chosen = NULL;
	for (auto& it : vecSun) {
		SDL_Rect thisHitbox = it->getHitbox();
		if (it->getState() == SUN_STILL && SDL_PointInRect(&mousePos, &thisHitbox)) {
			chosen = it;
			break;
		}
	}
	if (chosen != NULL) {
		chosen->updateState(SUN_MOVE);
		Mix_PlayChannel(-1, sfxSun, 0);
		return 1;
	}
	return 0;
}

void SunManager::removeSun(int id) {
	int delIndex = -1;
	for (int i = 0; i < (int)vecSun.size(); i++) {
		if (vecSun[i]->getID() == id) {
			delIndex = i;
			break;
		}
	}
	if (delIndex == -1) {
		printf("Can't remove sun with ID %d\n", id);
		return;
	}
	delete vecSun[delIndex];
	vecSun.erase(vecSun.begin() + delIndex);
	printf("DONE: Removed sun with ID %d\n", id);
	return;
}

void SunManager::update() {
	std::vector<int> pendingDelete;
	for (auto& it : vecSun) {
		if (it->update()) {
			if (it->getState() == SUN_MOVE) {
				curSun += SUN_VALUE;
				curSunChanged = true;
			}
			pendingDelete.push_back(it->getID());
		}
	}
}

void SunManager::render(SDL_Renderer* mRenderer) {
	if (curSunChanged) sunTextTexture.loadFromText(mRenderer, std::to_string(curSun), COLOR_WHITE, 40);
	curSunChanged = false;

	sunCounterTexture.renderAtPosition(mRenderer, 10, 5);
	sunTextTexture.renderAtPosition(mRenderer, 120, 30);

	for (auto& it : vecSun) {
		it->render(mRenderer);
	}
}