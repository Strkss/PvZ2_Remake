#pragma once
#include "FZombie.hpp"
#include "FDeadZombie.hpp"

class FConeZombie : public FZombie {
private:
	enum ZOMBIE_HP_TIERS hpTier;
	enum ZOMBIES type;
	enum ZOMBIE_STATES state;
public:
	FConeZombie(int row);
	~FConeZombie();
	bool update() override;
	void action();
};