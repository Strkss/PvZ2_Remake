#pragma once
#include "FSeedPacket.hpp"

class FSeedPotatomine : public FSeedPacket {
public:
	FSeedPotatomine(int pos);
	~FSeedPotatomine();

	void action(int row, int col);
};