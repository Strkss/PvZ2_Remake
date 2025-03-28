#include "Level.hpp"
#include "Global.hpp"

Level* myLevel = NULL;

Level::Level(int level) {
	delete myWave;
	myWave = NULL;
	delete myProgress;
	myProgress = NULL;
	this->path = SCENE_LEVEL_PREFIX + "day" + std::to_string(level) + "_wave.txt";
	this->name = "Modern Day - Day " + std::to_string(level);
	myWave = new WaveManager(path);
	PLANT_ID = 0;
	PEA_ID = 0;
	ZOMBIE_ID = 0;
	SUN_ID = 0;
	type = IN_LEVEL;
	nextScene = GAME_STATE_NUM;
	pop = false;
	Mix_HaltMusic();
	Mix_PlayMusic(flag_0, INT_MAX);
}

Level::~Level() {
	for (auto& it : vecPlant) {
		delete it;
	}
	vecPlant.clear();

	for (auto& it : vecZombie) {
		delete it;
	}
	vecZombie.clear();

	for (auto& it : vecPea) {
		delete it;
	}
	vecPea.clear();

	for (auto& it : vecPart) {
		delete it;
	}
	vecPart.clear();

	delete myWave;
	myWave = NULL;
	delete myProgress;
	myProgress = NULL;

	Mix_HaltMusic();
	Mix_HaltChannel(-1);
	pop = true;
}

void Level::removePlant(int id) {
	int delIndex = -1;
	for (int i = 0; i < (int)vecPlant.size(); i++) {
		if (vecPlant[i]->getID() == id) {
			delIndex = i;
			break;
		}
	}
	if (delIndex == -1) {
		printf("Can't remove plant with ID %d\n", id);
		return;
	}
	delete vecPlant[delIndex];
	vecPlant.erase(vecPlant.begin() + delIndex);
	printf("DONE: Removed plant with ID %d\n", id);
}

void Level::removeZombie(int id) {
	int delIndex = -1;
	for (int i = 0; i < (int)vecZombie.size(); i++) {
		if (vecZombie[i]->getID() == id) {
			delIndex = i;
			break;
		}
	}
	if (delIndex == -1) {
		printf("Can't remove zombie with ID %d\n", id);
		return;
	}
	delete vecZombie[delIndex];
	vecZombie.erase(vecZombie.begin() + delIndex);
	printf("DONE: Removed zombie with ID %d\n", id);
}

void Level::removePea(int id) {
	int delIndex = -1;
	for (int i = 0; i < (int)vecPea.size(); i++) {
		if (vecPea[i]->getID() == id) {
			delIndex = i;
			break;
		}
	}
	if (delIndex == -1) {
		printf("Can't remove pea with ID %d\n", id);
		return;
	}
	delete vecPea[delIndex];
	vecPea.erase(vecPea.begin() + delIndex);
	printf("DONE: Removed pea with ID %d\n", id);
	return;
}

void Level::removePart(int id) {
	int delIndex = -1;
	for (int i = 0; i < (int)vecPart.size(); i++) {
		if (vecPart[i]->getID() == id) {
			delIndex = i;
			break;
		}
	}
	if (delIndex == -1) {
		printf("Can't remove particle with ID %d\n", id);
		return;
	}
	delete vecPart[delIndex];
	vecPart.erase(vecPart.begin() + delIndex);
	printf("DONE: Removed particle with ID %d\n", id);
	return;
}

void Level::render(SDL_Renderer* mRenderer) {
	myLawn.render(mRenderer);
	mySlot.render(mRenderer);

	for (auto& it : vecPlant) {
		it->render(mRenderer);
	}

	for (auto& it : vecPart) {
		it->render(mRenderer);
	}

	for (auto& it : vecZombie) {
		it->render(mRenderer);
	}

	for (auto& it : vecPea) {
		it->render(mRenderer);
	}

	mySun.render(mRenderer);
	myProgress->render(mRenderer);
}

void Level::update() {
	if (myProgress == NULL) myProgress = new FProgressBar(name);
	std::vector<int> pendingDelete;
	mySlot.update();
	mySun.update();
	myWave->update();
	myProgress->update();
	
	for (auto& it : vecPlant) {
		if (it->update()) {
			pendingDelete.push_back(it->getID());
		}
	}
	for (auto& delID : pendingDelete) {
		removePlant(delID);
	}
	pendingDelete.clear();

	for (auto& it : vecZombie) {
		if (it->update()) {
			pendingDelete.push_back(it->getID());
		}
		else if (it->getHitbox().x <= LAWN_START_X - LAWN_GRID_WIDTH) { // check xem zom den nha chua
			nextScene = IN_LOSE;
			pop = true;
		}
	}
	for (auto& delID : pendingDelete) {
		removeZombie(delID);
	}
	pendingDelete.clear();

	for (auto& it : vecPea) {
		if (it->update()) {
			pendingDelete.push_back(it->getID());
		}
	}
	for (auto& delID : pendingDelete) {
		removePea(delID);
	}
	pendingDelete.clear();

	for (auto& it : vecPart) {
		if (it->update()) {
			pendingDelete.push_back(it->getID());
		}
	}
	for (auto& delID : pendingDelete) {
		removePart(delID);
	}
	pendingDelete.clear();

	if (myWave->isDone() && vecPart.size() == 0) { // check xem da win chua
		nextScene = IN_WON;
		pop = true;
	}
}

void Level::handleEvent(SDL_Event& e) {
	//printf("a %d\n", e.type);

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		if (e.key.keysym.sym == SDLK_ESCAPE) {
			pop = false;
			nextScene = IN_SETTINGS;
		}
		else mySlot.handleKeyDown(e.key.keysym.sym);
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN) {
		int x = -1, y = -1;
		SDL_GetMouseState(&x, &y);
		if (!mySun.handleMouse(x, y)) {
			mySlot.handleMouse(x, y);
		}
	}
}