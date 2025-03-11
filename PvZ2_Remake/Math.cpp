#include "Math.hpp"

using std::mersenne_twister_engine;

std::mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());

double getDistance(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool inSourceRect(int x, int y, int rX, int rY) {
	return x <= rX && y <= rY;
}

bool inRect(int x, int y, int rX, int rY, int rW, int rH) {
	return x >= rX && x <= rX + rW && y >= rY && y <= rY + rH;
}

int Rand(int l, int r) {
	return l + rd() % (r - l + 1);
}