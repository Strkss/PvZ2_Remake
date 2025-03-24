#pragma once
#include <stdio.h>
#include <SDL.h>

#include "Constants.hpp"
#include "FPlant.hpp"

class FWallnut : public FPlant {
public:
	FWallnut(int row, int col);
	~FWallnut();
	bool update() override;
};