#pragma once
#include "FSeedPacket.hpp"

class FSeedPeashooter : public FSeedPacket {
public:
	FSeedPeashooter();
	~FSeedPeashooter();

	void action(int row, int col);
};