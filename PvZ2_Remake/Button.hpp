#pragma once
#include <stdio.h>
#include <SDL.h>
#include "FTexture.hpp"

class Button {
	SDL_Rect box;
public:
	Button();
	Button(int x1, int y1, int x2, int y2);
	~Button();
	bool isClicked(SDL_Event& e) const; // check xem button co duoc click khong
	bool isHeld() const; // check xem button co dang duoc hold hay khong
};