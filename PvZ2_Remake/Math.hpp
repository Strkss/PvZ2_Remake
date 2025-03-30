#include <cmath>
#include <random>
#include <chrono>

#include "Constants.hpp"

double getDistance(int x1, int y1, int x2, int y2); // lay khoang cach 2 diem
bool inSourceRect(int x, int y, int rX, int rY); // check xem (x,y) co thuoc hcn (0, 0) (rX, rY)
bool inRect(int x, int y, int rX, int rY, int rW, int rH); // check xem (x, y) co thuoc hcn (rX, rY) (rX + rW, rY + rH)
bool findGrid(int& x, int& y, int& row, int& col); // tim xem (x,y) thuoc vao o nao cua lawn

int Rand(int l, int r); // random 1 so thuoc [l, r]