#include <cmath>
#include <random>
#include <chrono>

double getDistance(int x1, int y1, int x2, int y2);
bool inSourceRect(int x, int y, int rX, int rY);
bool inRect(int x, int y, int rX, int rY, int rW, int rH);

int Rand(int l, int r);