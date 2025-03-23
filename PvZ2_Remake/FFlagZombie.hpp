#pragma once
#include "FZombie.hpp"
#include "FDeadZombie.hpp"

class FFlagZombie : public FZombie {
public:
	FFlagZombie(int row);
	~FFlagZombie();
	bool update() override;
	void action();
};