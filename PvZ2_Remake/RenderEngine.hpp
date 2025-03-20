#pragma once
#include <stdio.h>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Constants.hpp"
#include "FPlant.hpp"
#include "FPea.hpp"
#include "FSun.hpp"
#include "FSeedPacket.hpp"
#include "FLawn.hpp"

bool createRenderer(SDL_Renderer*& mRenderer, SDL_Window* mWindow);

void loadMedia(SDL_Renderer* mRenderer);