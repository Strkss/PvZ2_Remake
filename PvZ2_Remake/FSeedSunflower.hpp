#pragma once
#include "FSeedPacket.hpp"

class FSeedSunflower : public FSeedPacket {
public:
	FSeedSunflower(int pos);
	~FSeedSunflower();

	void action(int row, int col);
};