#include <stdio.h>
#include <SDL.h>

#include "FTexture.hpp"
#include "Constants.hpp"
#include "EventHandler.hpp"

class FSeedPacket {
	static FTexture seedPacketPeashooter[SEEDPACKET_NUM];
	static enum SEEDPACKET_STATES statePeashooter;
	static FTexture shovel[SEEDPACKET_NUM];
	static enum SEEDPACKET_STATES stateShovel;
public:
	static void reset();
	static void loadMedia(SDL_Renderer* mRenderer);
	static void renderGUI(SDL_Renderer* mRenderer);
	static void updateState(enum PLANTS plant, enum SEEDPACKET_STATES state);
};