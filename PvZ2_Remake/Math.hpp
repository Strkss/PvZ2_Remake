#include <cmath>
#include <random>
#include <chrono>

#include "Constants.hpp"

double getDistance(int x1, int y1, int x2, int y2);
bool inSourceRect(int x, int y, int rX, int rY);
bool inRect(int x, int y, int rX, int rY, int rW, int rH);
bool findGrid(int& x, int& y, int& row, int& col);

int Rand(int l, int r);