#pragma once
#include <stdio.h>
#include <vector>
#include <SDL.h>
#include <utility>

#include "FTexture.hpp"
#include "Constants.hpp"
#include "FGreenPea.hpp"
#include "FPlant.hpp"
#include "CollisionChecker.hpp"

class FPeashooter : public FPlant {
private:
	void shoot();
public:
	FPeashooter(int row, int col);
	~FPeashooter();
	bool update() override;
	void action();
};