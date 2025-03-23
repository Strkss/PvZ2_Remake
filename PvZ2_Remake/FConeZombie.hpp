#pragma once
#include "FZombie.hpp"
#include "FDeadZombie.hpp"

class FConeZombie : public FZombie {
public:
	FConeZombie(int row);
	~FConeZombie();
	bool update() override;
	void action();
};