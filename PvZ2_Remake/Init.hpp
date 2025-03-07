#pragma once
#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Constants.hpp"

bool createWindow(SDL_Window*& mWindow);
bool initEngines();

void quitEngines();