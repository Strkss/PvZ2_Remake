#pragma once
#include "FSeedPacket.hpp"

class FSeedWallnut : public FSeedPacket {
public:
	FSeedWallnut(int pos);
	~FSeedWallnut();

	void action(int row, int col);
};