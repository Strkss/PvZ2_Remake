#pragma once
#include "FSeedPacket.hpp"

class FSeedWallnut : public FSeedPacket {
public:
	FSeedWallnut();
	~FSeedWallnut();

	void action(int row, int col);
};