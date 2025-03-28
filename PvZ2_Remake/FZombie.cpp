#include "FZombie.hpp"

FTexture zombieTexture[ZOMBIE_MAX_SPRITE];
SDL_Rect* zombieSprite[ZOMBIE_MAX_SPRITE];
int zombieAnimMaxFrame[ZOMBIE_MAX_SPRITE];

bool sortByRow(FZombie*& lhs, FZombie*& rhs) {
	return lhs->getRow() < rhs->getRow() || (lhs->getRow() == rhs->getRow() && lhs->getHitbox().x < rhs->getHitbox().x);
}

FZombie::~FZombie() {}

int FZombie::convertToAnimID(int zombie, int state, int hpTier) {
	return zombie * ZOMBIE_HP_TIERS_NUM * ZOMBIE_STATES_NUM  + hpTier * ZOMBIE_STATES_NUM + state;
}

void FZombie::updateAnimID(int id) {
	animID = id;
	animFrame = 0;
}

int FZombie::getAnimID() {
	return animID;
}

int FZombie::getID() const {
	return id;
}

enum ZOMBIES FZombie::getType() const {
	return type;
}

void FZombie::render(SDL_Renderer* mRenderer) {
	if (animFrame / FRAME_PACING >= zombieAnimMaxFrame[animID]) animFrame = 0;
	zombieTexture[animID].renderAtPosition(mRenderer, rX, rY - zombieSprite[animID][0].h / SPRITE_DOWNSCALE, &zombieSprite[animID][animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
#ifdef DEBUG_HITBOX
	SDL_GetRenderDrawColor(mRenderer, 0, 0, 0, 0);
	SDL_RenderDrawRect(mRenderer, &hitbox);
#endif
}

SDL_Rect FZombie::getHitbox() const {
	return hitbox;
}

void FZombie::takeDamage(int dmg) {
	hp -= dmg;
}

void FZombie::move() {
	++step;
	if (step >= ZOMBIE_INV_VEL) {
		--rX;
		--hitbox.x;
		step = 0;
	}
}

int FZombie::getRow() const {
	return row;
}

int FZombie::getHP() const {
	return hp;
}

//FTexture zombieDieTexture, basicWalkTexture, basicEatTexture;
//std::vector<FZombie*> vecZombie;
//std::vector<FZombie*> deadZombie;
//SDL_Rect zombieDieSprite[ZOMBIE_DIE_FRAME], basicWalkSprite[ZOMBIE_BASIC_WALK_FRAME], basicEatSprite[ZOMBIE_BASIC_EAT_FRAME];
//bool levelLost = false;
//
//FZombie::FZombie(int x, int y, int row, ZOMBIE_TYPES type) {
//	switch (type) {
//	case ZOMBIE_BASIC:
//		this->type = ZOMBIE_BASIC;
//		hp = ZOMBIE_BASIC_HP;
//		break;
//	case ZOMBIE_CONE:
//		this->type = ZOMBIE_CONE;
//		hp = ZOMBIE_CONE_HP;
//		break;
//	case ZOMBIE_BUCKET:
//		this->type = ZOMBIE_BUCKET;
//		hp = ZOMBIE_BUCKET_HP;
//		break;
//	case ZOMBIE_FLAG:
//		this->type = ZOMBIE_FLAG;
//		hp = ZOMBIE_FLAG_HP;
//		break;
//	default:
//		this->type = ZOMBIE_BASIC;
//		hp = ZOMBIE_BASIC_HP;
//	}
//	this->x = x;
//	this->y = y;
//	this->row = row;
//	id = ++ZOMBIE_ID;
//	step = 0;
//	state = ZOMBIE_WALK;
//	animFrame = 0;
//	vecZombie.push_back(this);
//}
//
//FZombie::FZombie(int x, int y) {
//	this->x = x;
//	this->y = y;
//	this->type = ZOMBIE_BASIC;
//	row = -1;
//	hp = 1;
//	id = ++ZOMBIE_ID;
//	step = 0;
//	state = ZOMBIE_DIE;
//	animFrame = 0;
//	deadZombie.push_back(this);
//}
//
//void FZombie::free() {
//	hp = 0;
//	x = 0;
//	y = 0;
//	id = 0;
//	step = 0;
//}
//
//void FZombie::move() {
//	++step;
//	if (step >= ZOMBIE_INV_VEL) {
//		--x;
//		step = 0;
//	}
//}
//
//int FZombie::getID() {
//	return id;
//}
//
//void FZombie::updateAnimFrame(int frame) {
//	animFrame = frame;
//}
//
//void FZombie::render(SDL_Renderer* mRenderer) {
//	++animFrame;
//	switch (state) {
//	case ZOMBIE_WALK:
//		switch (type) {
//		case ZOMBIE_BASIC:
//			if (animFrame / FRAME_PACING >= ZOMBIE_BASIC_WALK_FRAME) animFrame = 0;
//			basicWalkTexture.renderAtPosition(mRenderer, x + LAWN_GRID_WIDTH, y + LAWN_GRID_HEIGHT - ZOMBIE_BASIC_WALK_SPRITE_HEIGHT / SPRITE_DOWNSCALE, &basicWalkSprite[animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
//			SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0);
//			SDL_Rect debugRect = { x + LAWN_GRID_WIDTH, y + LAWN_GRID_HEIGHT - ZOMBIE_BASIC_WALK_SPRITE_HEIGHT / SPRITE_DOWNSCALE, ZOMBIE_BASIC_WALK_SPRITE_WIDTH / SPRITE_DOWNSCALE, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT / SPRITE_DOWNSCALE };
//			SDL_RenderDrawRect(mRenderer, &debugRect);
//			//printf("Zombie at %d %d %d\n", x, y, animFrame);
//			break;
//		}
//		break;
//	case ZOMBIE_EAT:
//		switch (type) {
//		case ZOMBIE_BASIC:
//			if (animFrame / FRAME_PACING >= ZOMBIE_BASIC_EAT_FRAME) animFrame = 0;
//			basicEatTexture.renderAtPosition(mRenderer, x + LAWN_GRID_WIDTH, y + LAWN_GRID_HEIGHT - ZOMBIE_BASIC_EAT_SPRITE_HEIGHT / SPRITE_DOWNSCALE, &basicEatSprite[animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
//			break;
//		}
//		break;
//	case ZOMBIE_DIE:
//		zombieDieTexture.renderAtPosition(mRenderer, x + LAWN_GRID_WIDTH, y + LAWN_GRID_HEIGHT - ZOMBIE_DIE_SPRITE_HEIGHT / SPRITE_DOWNSCALE, &zombieDieSprite[animFrame / FRAME_PACING], SPRITE_DOWNSCALE);
//		break;
//	}
//}
//
//int FZombie::getRow() {
//	return row;
//}
//
//int FZombie::getX() {
//	return x;
//}
//
//int FZombie::getY() {
//	return y;
//}
//
//void FZombie::takeDamage(int dmg) {
//	hp -= dmg;
//	if (hp < 0) {
//		state = ZOMBIE_DIE;
//	}
//}
//
//enum ZOMBIE_STATES FZombie::getState() {
//	return state;
//}
//
//void FZombie::updateState(enum ZOMBIE_STATES state) {
//	this->state = state;
//}
//
//bool sortByRow(FZombie*& lhs, FZombie*& rhs) {
//	return lhs->getRow() < rhs->getRow() || (lhs->getRow() == rhs->getRow() && lhs->getX() < rhs->getX());
//}
//
//void FZombie::loadMedia(SDL_Renderer* mRenderer) {
//	zombieDieTexture.loadFromFile(mRenderer, ZOMBIE_DIE_IMG);
//	basicWalkTexture.loadFromFile(mRenderer, ZOMBIE_BASIC_WALK_IMG);
//	basicEatTexture.loadFromFile(mRenderer, ZOMBIE_BASIC_EAT_IMG);
//
//	for (int i = 0; i <= ZOMBIE_DIE_FRAME / 10; i++) { // for row
//		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_DIE_FRAME) { // for col
//			zombieDieSprite[i * 10 + j] = { ZOMBIE_DIE_SPRITE_WIDTH * j, ZOMBIE_DIE_SPRITE_HEIGHT * i, ZOMBIE_DIE_SPRITE_WIDTH, ZOMBIE_DIE_SPRITE_HEIGHT };
//		}
//	}
//	for (int i = 0; i <= ZOMBIE_BASIC_WALK_FRAME / 10; i++) {
//		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_WALK_FRAME) {
//			basicWalkSprite[i * 10 + j] = { ZOMBIE_BASIC_WALK_SPRITE_WIDTH * j, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT * i, ZOMBIE_BASIC_WALK_SPRITE_WIDTH, ZOMBIE_BASIC_WALK_SPRITE_HEIGHT };
//		}
//	}
//	for (int i = 0; i <= ZOMBIE_BASIC_EAT_FRAME / 10; i++) {
//		for (int j = 0; j < 10; j++) if (i * 10 + j < ZOMBIE_BASIC_EAT_FRAME) {
//			basicEatSprite[i * 10 + j] = { ZOMBIE_BASIC_EAT_SPRITE_WIDTH * j, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT * i, ZOMBIE_BASIC_EAT_SPRITE_WIDTH, ZOMBIE_BASIC_EAT_SPRITE_HEIGHT };
//		}
//	}
//
//	printf("DONE: FZombie -> loadMedia\n");
//}
//
//bool FZombie::removeZombie(int id) {
//	int delIndex = -1;
//	for (int i = 0; i < (int)vecZombie.size(); i++) {
//		if (vecZombie[i]->getID() == id) {
//			delIndex = i;
//			break;
//		}
//	}
//	if (delIndex == -1) {
//		printf("Can't remove zombie with id %d\n", id);
//		return 0;
//	}
//	vecZombie[delIndex]->free();
//	vecZombie.erase(vecZombie.begin() + delIndex);
//	printf("DONE: Removed zombie with id %d\n", id);
//	return 1;
//}
//
//bool FZombie::removeDeadZombie(int id) {
//	int delIndex = -1;
//	for (int i = 0; i < (int)deadZombie.size(); i++) {
//		if (deadZombie[i]->getID() == id) {
//			delIndex = i;
//			break;
//		}
//	}
//	if (delIndex == -1) {
//		printf("Can't remove dead zombie with id %d\n", id);
//		return 0;
//	}
//	deadZombie[delIndex]->free();
//	deadZombie.erase(deadZombie.begin() + delIndex);
//	printf("DONE: Removed dead zombie with id %d\n", id);
//	return 1;
//}
//
//bool FZombie::renderAll(SDL_Renderer* mRenderer) {
//	std::vector<int> despawn;
//	std::vector<int> removeDead;
//	for (auto it : deadZombie) {
//		if ((it->animFrame + 1) / FRAME_PACING >= ZOMBIE_DIE_FRAME) removeDead.push_back(it->id);
//		else it->render(mRenderer);
//	}
//	for (auto it : vecZombie) {
//		switch (it->type) {
//		case ZOMBIE_BASIC:
//			it->render(mRenderer);
//			break;
//		case ZOMBIE_CONE:
//			break;
//		case ZOMBIE_BUCKET:
//			break;
//		case ZOMBIE_FLAG:
//			break;
//		}
//		if (it->getState() == ZOMBIE_WALK) it->move();
//		if (it->x < LAWN_START_X - 4 * LAWN_GRID_WIDTH / 3) {
//			despawn.push_back(it->id);
//			levelLost = true;
//		}
//		if (it->state == ZOMBIE_DIE) {
//			FZombie* myDedZom = new FZombie(it->x, it->y);
//			despawn.push_back(it->id);
//		}
//	}
//	for (auto it : despawn) {
//		removeZombie(it);
//	}
//	for (auto it : removeDead) {
//		removeDeadZombie(it);
//	}
//	return 0;
//}
//
//void FZombie::reset() {
//	vecZombie.clear();
//	deadZombie.clear();
//	ZOMBIE_ID = 0;
//
//	printf("DONE: Reset FZombie\n");
//}