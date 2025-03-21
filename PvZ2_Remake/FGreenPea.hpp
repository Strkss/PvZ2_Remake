#include "FPea.hpp"
#include "CollisionChecker.hpp"

class FGreenPea : public FPea {
public:
	FGreenPea(int r, int c);
	~FGreenPea();
	void action();
	bool update();
};