#include "FZombie.hpp"

class FDeadZombie : public FZombie {
public:
	FDeadZombie(int x, int y);
	~FDeadZombie();
	bool update() override;
};