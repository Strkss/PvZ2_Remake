#pragma once
#include <stdio.h>
#include <stack>
#include "SDL.h"
#include "Scene.hpp"
#include "Constants.hpp"

namespace SceneManager { // quan ly scene theo scene stack
	extern std::stack<Scene*> sceneStack;
	void update();
	void render(SDL_Renderer* mRenderer);
	void removeScene(); // pop stack
	void addScene(Scene* scene); // push stack
	void handleEvent(SDL_Event& e);
	void clear(); // empty stack
	enum GAME_STATES getSceneType();
}