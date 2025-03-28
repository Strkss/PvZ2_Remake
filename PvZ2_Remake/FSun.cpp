#include "FSun.hpp"

FTexture sunTexture, sunCounterTexture, sunTextTexture;

FSun::FSun(int x, int y) {
	rX = x;
	rY = y;
	hitbox.x = rX;
	hitbox.y = rY;
	hitbox.w = sunTexture.getW() / SPRITE_DOWNSCALE;
	hitbox.h = sunTexture.getH() / SPRITE_DOWNSCALE;
	decideVel();
	state = SUN_STILL;
	timer = 0;
	id = ++SUN_ID;
}

FSun::~FSun() { }

void FSun::move() {
	rX -= velX;
	rY -= velY;
	hitbox.x -= velX;
	hitbox.y -= velY;
}

void FSun::decideVel() {
	int dis = getDistance(rX, rY, 120, 30); // Lay khoang cach den SunCounter
	int disX = abs(rX - 120);
	int disY = abs(rY - 30);
	int frameTaken = dis / SUN_VEL;
	velX = disX / frameTaken;
	velY = disY / frameTaken;
}

SDL_Rect FSun::getHitbox() const{
	return hitbox;
}

int FSun::getID() const{
	return id;
}

enum SUN_STATES FSun::getState() const{
	return state;
}

void FSun::render(SDL_Renderer* mRenderer) {
	sunTexture.renderAtPosition(mRenderer, rX, rY, NULL, SPRITE_DOWNSCALE);
#ifdef DEBUG_HITBOX
	SDL_GetRenderDrawColor(mRenderer, 0, 0, 0, 0);
	SDL_RenderDrawRect(mRenderer, &hitbox);
#endif	
}

void FSun::updateState(enum SUN_STATES uState) {
	state = uState;
}

bool FSun::update() {
	++timer;
	if (state == SUN_MOVE) move();
	if (inSourceRect(rX, rY, 150, 50) || (state == SUN_STILL && timer >= SUN_DESPAWN_TIME)) return 1;
	return 0;
}