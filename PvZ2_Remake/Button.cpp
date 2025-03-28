#include "Button.hpp"

Button::Button() { }

Button::Button(int x1, int y1, int x2, int y2) {
	box = { x1, y1, x2 - x1, y2 - y1 };
}

Button::~Button() { }

bool Button::isClicked(SDL_Event & e) const{
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		int mX = -1, mY = -1;
		SDL_GetMouseState(&mX, &mY);
		SDL_Point p = { mX, mY };
		if (SDL_PointInRect(&p, &box)) {
			return true;
		}
	}
	return false;
}

bool Button::isHeld() const{
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		int mX = -1, mY = -1;
		SDL_GetMouseState(&mX, &mY);
		SDL_Point p = { mX, mY };
		if (SDL_PointInRect(&p, &box)) {
			return true;
		}
	}
	return false;
}