#include "FSeedPacket.hpp"

class FSeedShovel : public FSeedPacket {
public:
	FSeedShovel();
	~FSeedShovel();

	void action(int row, int col, std::vector<FPlant*>& vecPlant, FLawn& lawn);
};