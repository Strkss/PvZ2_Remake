#pragma once
#include <stdio.h>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Constants.hpp"

bool createRenderer(SDL_Renderer*& mRenderer, SDL_Window* mWindow);