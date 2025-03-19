#include "FSeedPacket.hpp"

class FSeedPeashooter : public FSeedPacket {
public:
	FSeedPeashooter();
	~FSeedPeashooter();

	void action(int row, int col, std::vector<FPlant*>& vecPlant, FLawn& lawn);
};