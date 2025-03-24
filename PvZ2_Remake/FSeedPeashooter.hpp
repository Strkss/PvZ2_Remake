#pragma once
#include "FSeedPacket.hpp"

class FSeedPeashooter : public FSeedPacket {
public:
	FSeedPeashooter(int pos);
	~FSeedPeashooter();

	void action(int row, int col);
};