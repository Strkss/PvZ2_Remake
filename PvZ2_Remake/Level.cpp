#include "Level.hpp"
#include "Global.hpp"

Level* myLevel = NULL;

Level::Level() {
	PLANT_ID = 0;
	PEA_ID = 0;
	ZOMBIE_ID = 0;
	SUN_ID = 0;
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

	Mix_HaltMusic();
	Mix_HaltChannel(-1);
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
	/*deadZombie.push_back(new FZombie(vecZombie[delIndex]->getX(), vecZombie[delIndex]->getY()));*/
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

void Level::render(SDL_Renderer* mRenderer) {
	for (auto& it : vecPlant) {
		it->render(mRenderer);
	}

	for (auto& it : vecZombie) {
		it->render(mRenderer);
	}

	for (auto& it : vecPea) {
		it->render(mRenderer);
	}
}

void Level::update() {
	std::vector<int> pendingDelete;
	
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
}

