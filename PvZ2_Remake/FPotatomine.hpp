#pragma once
#include <stdio.h>
#include <vector>
#include <SDL.h>
#include <utility>

#include "FTexture.hpp"
#include "Constants.hpp"
#include "FPlant.hpp"
#include "CollisionChecker.hpp"

class FPotatomine : public FPlant {
private:
	int timer;
	void explode(std::vector<FZombie*> damagedZom);
public:
	FPotatomine(int row, int col);
	~FPotatomine();
	bool update() override;
	void action();
};