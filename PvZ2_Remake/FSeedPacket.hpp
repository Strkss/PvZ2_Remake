#pragma once
#include <stdio.h>
#include <SDL.h>
#include <vector>

#include "FPlant.hpp"
#include "FPeashooter.hpp"
#include "FWallnut.hpp"
#include "FSunflower.hpp"
#include "FPotatomine.hpp"
#include "FTexture.hpp"
#include "Constants.hpp"
#include "FLawn.hpp"

extern FTexture seedPacketTexture[PLANT_NUM];
extern SDL_Rect* seedPacketSprite[PLANT_NUM];
extern int seedPacketMaxSprite[PLANT_NUM];

class FSeedPacket {
protected:
	int cooldownTimer; // thoi gian hien tai
	int targetCooldownTimer; // thoi gian cooldown
	int rX, rY; // render pos
	int keyPress; // phim tat
	enum PLANTS type; // loai seedpacket
	int cost; // gia tien
public:
	enum SEEDPACKET_STATES state;

	void render(SDL_Renderer *mRenderer);
	bool update();
	virtual void action(int row, int col) = 0;
	int getKeyPress() const;
	int getCost() const;
};

//#include "EventHandler.hpp"
//
//class FSeedPacket {
//	static FTexture seedPacketPeashooter[SEEDPACKET_NUM];
//	static enum SEEDPACKET_STATES statePeashooter;
//	static FTexture shovel[SEEDPACKET_NUM];
//	static enum SEEDPACKET_STATES stateShovel;
//public:
//	static void reset();
//	static void loadMedia(SDL_Renderer* mRenderer);
//	static void renderGUI(SDL_Renderer* mRenderer);
//	static void updateState(enum PLANTS plant, enum SEEDPACKET_STATES state);
//};