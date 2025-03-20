#include "FZombie.hpp"
#include "FDeadZombie.hpp"

class FBasicZombie : public FZombie {
public:
	FBasicZombie(int row);
	~FBasicZombie();
	bool update() override;
	void action();
};