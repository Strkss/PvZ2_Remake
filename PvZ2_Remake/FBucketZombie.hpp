#pragma once
#include "FZombie.hpp"
#include "FDeadZombie.hpp"

class FBucketZombie : public FZombie {
public:
	FBucketZombie(int row);
	~FBucketZombie();
	bool update() override;
	void action();
};