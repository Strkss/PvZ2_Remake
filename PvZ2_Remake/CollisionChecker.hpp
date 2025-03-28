#pragma once
#include <stdio.h>
#include <SDL.h>
#include <vector>
#include <algorithm>

#include "Constants.hpp"
#include "FPea.hpp"
#include "FPlant.hpp"
#include "FZombie.hpp"
#include "Math.hpp"

struct sortExtra {
	bool operator()(FPlant*& lhs, FPlant*& rhs); // sort plant theo hang roi theo cot
	bool operator()(FZombie*& lhs, FZombie*& rhs); // sort zom theo hang roi theo x
	bool operator()(FPea*& lhs, FPea*& rhs);  // sort pea theo hang roi theo x
};

bool checkZombieInRange(FPlant* plant, std::vector<FZombie*>& vecZom, std::vector<FZombie*>& damagedZom);
bool checkPlantInRange(FZombie* zom, std::vector<FPlant*>& vecPlant, FPlant*& damagedPlant);
bool checkPeaExploded(FPea* pea, std::vector<FZombie*>& vecZom, FZombie*& damagedZom);

void doDamageToZombieGroup(std::vector<FZombie*>& vecZom, int dmg);