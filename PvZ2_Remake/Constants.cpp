#include "Constants.hpp"
#include "SDL_ttf.h"
#include <fstream>

TTF_Font* font = NULL;

Mix_Music* flag_0 = NULL;
Mix_Music* flag_1 = NULL;
Mix_Music* flag_2 = NULL;
Mix_Music* flag_3 = NULL;
Mix_Music* intro = NULL;
Mix_Music* won = NULL;
Mix_Music* lost = NULL;

Mix_Chunk* sfxEat = NULL;	
Mix_Chunk* sfxExplode = NULL;
Mix_Chunk* sfxHit = NULL;
Mix_Chunk* sfxPlant = NULL;
Mix_Chunk* sfxSun = NULL;
Mix_Chunk* sfxBuzz = NULL;

long long PEA_ID = 0;
int ZOMBIE_ID = 0;