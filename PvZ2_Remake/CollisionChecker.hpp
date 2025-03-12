#include <stdio.h>
#include <SDL.h>
#include <vector>
#include <algorithm>

#include "Constants.hpp"
#include "FPea.hpp"
#include "FPeashooter.hpp"
#include "FZombie.hpp"
#include "Math.hpp"

struct sortExtra {
	bool operator()(FPea*& lhs, FPea*& rhs);
	bool operator()(FZombie*& lhs, FZombie*& rhs);
	bool operator()(FPeashooter*& lhs, FPeashooter*& rhs);
};

void checkPeaAndZombie();
void checkZombieAndPlant();
void detectPeashooterZombie();