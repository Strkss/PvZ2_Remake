#include <SDL.h>
#include <stdio.h>
#include <vector>
#include <utility>

#include "Constants.hpp"
#include "FTexture.hpp"
#include "FLawn.hpp"

class FPlant;

extern SDL_Rect* plantSprite[PLANT_MAX_SPRITE];
extern FTexture plantTexture[PLANT_MAX_SPRITE];
extern std::vector<FPlant*> vecPlant;
extern int plantAnimMaxFrame[];

class FPlant {
	int hp;
	int row, col;
	SDL_Rect hitbox;
	int rX, rY;
	int animFrame;
	int animID;

public:
	static void loadMedia(SDL_Renderer* mRenderer);

	virtual bool update() = 0;
	static void updateAll();

	static int convertToAnimID(enum PLANTS plant, enum PLANT_STATES state);
	void updateAnimID(int id);
	int getAnimID();

	static void renderAll(SDL_Renderer* mRenderer);
	void render(SDL_Renderer* mRenderer);

	static void removePlant(int row, int col);

	int getRow();
	int getCol();
	void takeDamage(int dmg);
};
