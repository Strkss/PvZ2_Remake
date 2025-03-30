#pragma once
#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Constants.hpp"

bool createWindow(SDL_Window*& mWindow); // tao window
bool initEngines(); // khoi tao engine
bool loadMusic(); // load nhac, sfx
bool closeMusic(); // unload nhac, sfx

void quitEngines(); // thoat engine