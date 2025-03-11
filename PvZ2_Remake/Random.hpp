#include <random>
#include <chrono>

using std::mersenne_twister_engine;

std::mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r);