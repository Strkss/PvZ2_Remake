#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FTexture.hpp"
#include "Constants.hpp"

extern FTexture zombieDieTexture, basicWalkTexture, basicEatTexture;
extern SDL_Rect zombieDieSprite[ZOMBIE_DIE_FRAME], basicWalkSprite[ZOMBIE_BASIC_WALK_FRAME], basicEatSprite[ZOMBIE_BASIC_EAT_FRAME];

class FZombie {
	int hp;
	int x, y;
	int id;
	int step;
	int animFrame;
	enum ZOMBIE_STATES state;
	enum ZOMBIE_TYPES type;

public:
	FZombie(int x, int y, ZOMBIE_TYPES type);
	void free();
	void move();
	int getID();
	void playAnim(SDL_Renderer* mRenderer);
	
	static void loadMedia(SDL_Renderer* mRenderer);
	static bool renderAll(SDL_Renderer* mRenderer);
	static bool removeZombie(int id);
};

extern std::vector<FZombie*> vecZombie;