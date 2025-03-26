#pragma once
#include <stdio.h>
#include <stack>
#include "SDL.h"
#include "Scene.hpp"
#include "Constants.hpp"


namespace SceneManager {
	extern std::stack<Scene*> sceneStack;
	void update();
	void render(SDL_Renderer* mRenderer);
	void removeScene();
	void addScene(Scene* scene);
	void handleEvent(SDL_Event& e);
	void clear();
	enum GAME_STATES getSceneType();
}