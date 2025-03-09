#include <stdio.h>
#include <SDL.h>

#include "FTexture.hpp"
#include "Constants.hpp"

class FSeedPacket {
	static FTexture seedPacketPeashooter[SEEDPACKET_NUM];
	static enum SEEDPACKET_STATES statePeashooter;
public:
	static void loadMedia(SDL_Renderer* mRenderer);
	static void renderGUI(SDL_Renderer* mRenderer);
	static void updateState(enum PLANTS plant, enum SEEDPACKET_STATES state);
};