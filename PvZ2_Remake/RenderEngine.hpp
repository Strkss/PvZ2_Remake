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
#include "FZombie.hpp"
#include "FParticle.hpp"
#include "FProgressBar.hpp"

#include "PauseMenu.hpp"
#include "TitleScreen.hpp"
#include "WorldMap.hpp"
#include "LevelLose.hpp"
#include "LevelWin.hpp"

bool createRenderer(SDL_Renderer*& mRenderer, SDL_Window* mWindow); // tao renderer

void loadMedia(SDL_Renderer* mRenderer); // load texture can thiet

void closeMedia(); // giai phong bo nho da dung