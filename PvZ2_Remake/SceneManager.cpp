#include "SceneManager.hpp"

std::stack<Scene*> SceneManager::sceneStack;

void SceneManager::update() {
	sceneStack.top()->update();
}

void SceneManager::render(SDL_Renderer* mRenderer) {
	sceneStack.top()->render(mRenderer);
}

void SceneManager::removeScene() {
	delete sceneStack.top();
	sceneStack.pop();
}

void SceneManager::addScene(Scene* scene) {
	sceneStack.push(scene);
}

void SceneManager::handleEvent(SDL_Event& e) {
	sceneStack.top()->handleEvent(e);
}

void SceneManager::clear() {
	while (!sceneStack.empty()) {
		removeScene();
	}
	printf("DONE: Emptied all scenes\n");
}

enum GAME_STATES SceneManager::getSceneType() {
	return sceneStack.top()->type;
}