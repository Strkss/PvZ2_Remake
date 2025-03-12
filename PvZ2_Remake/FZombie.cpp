#include "FZombie.hpp"

FTexture zombieDieTexture, basicWalkTexture, basicEatTexture;
std::vector<FZombie*> vecZombie;
SDL_Rect zombieDieSprite[ZOMBIE_DIE_FRAME], basicWalkSprite[ZOMBIE_BASIC_WALK_FRAME], basicEatSprite[ZOMBIE_BASIC_EAT_FRAME];

FZombie::FZombie(int x, int y, ZOMBIE_TYPES type) {
	switch (type) {
	case ZOMBIE_BASIC:
		this->type = ZOMBIE_BASIC;
		hp = ZOMBIE_BASIC_HP;
		break;
	case ZOMBIE_CONE:
		this->type = ZOMBIE_CONE;
		hp = ZOMBIE_CONE_HP;
		break;
	case ZOMBIE_BUCKET:
		this->type = ZOMBIE_BUCKET;
		hp = ZOMBIE_BUCKET_HP;
		break;
	case ZOMBIE_FLAG:
		this->type = ZOMBIE_FLAG;
		hp = ZOMBIE_FLAG_HP;
		break;
	default:
		this->type = ZOMBIE_BASIC;
		hp = ZOMBIE_BASIC_HP;
	}
	this->x = x;
	this->y = y;
	id = ++ZOMBIE_ID;
	step = 0;
	state = ZOMBIE_WALK;
	animFrame = 0;
	vecZombie.push_back(this);
}

void FZombie::free() {
	hp = 0;
	x = 0;
	y = 0;
	id = 0;
	step = 0;
}

void FZombie::move() {
	++step;
	if (step >= ZOMBIE_INV_VEL) {
		--x;
		step = 0;
	}
}

int FZombie::getID() {
	return id;
}

void FZombie::playAnim(SDL_Renderer* mRenderer) {
	++animFrame;
	switch (state) {
	case ZOMBIE_WALK:
		switch (type) {
		case ZOMBIE_BASIC:
			if (animFrame / FRAME_PACING >= ZOMBIE_BASIC_WALK_FRAME) animFrame = 0;
			basicWalkTexture.renderAtPosition(mRenderer, x, y, &basicWalkSprite[animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
			//printf("Zombie at %d %d %d\n", x, y, animFrame);
			break;
		}
		break;
	}
}

void FZombie::loadMedia(SDL_Renderer* mRenderer) {
	zombieDieTexture.loadFromFile(mRenderer, ZOMBIE_DIE_IMG);
	basicWalkTexture.loadFromFile(mRenderer, ZOMBIE_BASIC_WALK_IMG);
	basicEatTexture.loadFromFile(mRenderer, ZOMBIE_BASIC_EAT_IMG);

	for (int i = 0; i < ZOMBIE_DIE_FRAME; i++) {
		zombieDieSprite[i] = { ZOMBIE_DIE_SPRITE_WIDTH * i, 0, ZOMBIE_DIE_SPRITE_WIDTH, ZOMBIE_DIE_SPRITE_HEIGHT };
	}
	
	for (int i = 0; i < ZOMBIE_BASIC_WALK_FRAME; i++) {
		basicWalkSprite[i] = { ZOMBIE_BASIC_WALK_SPRITE_WIDTH * i, 0, ZOMBIE_BASIC_WALK_SPRITE_WIDTH, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT };
	}

	for (int i = 0; i < ZOMBIE_BASIC_EAT_FRAME; i++) {
		basicEatSprite[i] = { ZOMBIE_BASIC_EAT_SPRITE_WIDTH * i, 0, ZOMBIE_BASIC_EAT_SPRITE_WIDTH, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT };
	}

	printf("DONE: FZombie -> loadMedia\n");
}

bool FZombie::removeZombie(int id) {
	int delIndex = -1;
	for (int i = 0; i < (int)vecZombie.size(); i++) {
		if (vecZombie[i]->getID() == id) {
			delIndex = i;
			break;
		}
	}
	if (delIndex == -1) {
		printf("Can't remove zombie with id %d\n", id);
		return 0;
	}
	vecZombie[delIndex]->free();
	vecZombie.erase(vecZombie.begin() + delIndex);
	printf("DONE: Removed zombie with id %d\n", id);
	return 1;
}

bool FZombie::renderAll(SDL_Renderer* mRenderer) {
	std::vector<int> despawn;
	for (auto it : vecZombie) {
		switch (it->type) {
		case ZOMBIE_BASIC:
			it->playAnim(mRenderer);
			break;
		case ZOMBIE_CONE:
			break;
		case ZOMBIE_BUCKET:
			break;
		case ZOMBIE_FLAG:
			break;
		}
		it->move();
		if (it->x < LAWN_START_X) {
			despawn.push_back(it->id);
		}
	}
	for (auto it : despawn) {
		printf("GAME: Zombie WON\n");
		removeZombie(it);
		return 1;
	}
	return 0;
}