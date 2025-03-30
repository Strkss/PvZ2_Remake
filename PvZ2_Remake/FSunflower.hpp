#pragma once
#include <stdio.h>
#include <vector>
#include <SDL.h>
#include <utility>

#include "FTexture.hpp"
#include "Constants.hpp"
#include "FSun.hpp"
#include "FPlant.hpp"

class FSunflower : public FPlant {
private:
	int timer;
	void giveSun(); // cho sun sau mot khoang thoi gian
public:
	FSunflower(int row, int col);
	~FSunflower();
	bool update() override;
	void action();
};