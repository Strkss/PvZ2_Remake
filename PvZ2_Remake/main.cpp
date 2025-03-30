#include <stdio.h>

#include "Constants.hpp"
#include "Init.hpp"
#include "RenderEngine.hpp"
#include "FTexture.hpp"
#include "FLawn.hpp"
#include "FGrid.hpp"
#include "FPeashooter.hpp"
#include "FSeedPacket.hpp"
#include "FSun.hpp"
#include "FPea.hpp"
#include "FZombie.hpp"
#include "CollisionChecker.hpp"
#include "FProgressBar.hpp"
#include "FPlant.hpp"
#include "FBasicZombie.hpp"
#include "Global.hpp"
#include "SceneManager.hpp"
#include "LevelIntro.hpp"

extern int levelChosen;

int main(int argc, char* argv[]) {
	initEngines();
	loadMusic();
	SDL_Renderer* mRenderer = NULL;
	SDL_Window* mWindow = NULL;
	FTexture inactiveSceneTexture;

	createWindow(mWindow);
	createRenderer(mRenderer, mWindow);
	loadMedia(mRenderer);
	
	// hien background khi pause game
	inactiveSceneTexture.loadFromFile(mRenderer, "Assets/UI/alphagrey.png");
	Scene* previousScene = NULL;

	SceneManager::addScene(new TitleScreen());

	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}
			SceneManager::handleEvent(e);
		}
		SDL_RenderClear(mRenderer);

		switch (SceneManager::sceneStack.top()->nextScene) { // decide next scene
		case IN_INTRO: //map -> intro
			if (SceneManager::sceneStack.top()->pop) SceneManager::removeScene();
			previousScene = NULL;
			SceneManager::addScene(new LevelIntro(levelChosen));
			break;
		case IN_LEVEL: // intro -> level
			if (SceneManager::sceneStack.top()->pop) SceneManager::removeScene();
			previousScene = NULL;
			myLevel = new Level(levelChosen);
			levelChosen = 0;
			SceneManager::addScene(myLevel);
			break;
		case IN_SETTINGS: // level -> settings, settings -> level (return) / map
			previousScene = SceneManager::sceneStack.top();
			SceneManager::addScene(new PauseMenu);
			break;
		case SCENE_RETURN:
			if (SceneManager::sceneStack.top()->pop) SceneManager::removeScene();
			previousScene = NULL;
			SceneManager::sceneStack.top()->pop = false;
			SceneManager::sceneStack.top()->nextScene = GAME_STATE_NUM;
			break;
		case IN_LOSE:
			if (SceneManager::sceneStack.top()->pop) SceneManager::removeScene();
			previousScene = NULL;
			SceneManager::addScene(new LevelLose);
			break;
		case IN_WON:
			if (SceneManager::sceneStack.top()->pop) SceneManager::removeScene();
			previousScene = NULL;
			SceneManager::addScene(new LevelWin);
			break;
		case IN_REALM: // title / settings / win / lose -> realm, realm -> level
			if (SceneManager::sceneStack.size() == 1) {
				SceneManager::addScene(new WorldMap);
			}
			while (SceneManager::sceneStack.top()->type != IN_REALM) SceneManager::removeScene();
			previousScene = NULL;
			SceneManager::sceneStack.top()->nextScene = GAME_STATE_NUM;
			break;
		case IN_NULL: // exit the game
			quit = true;
			break;
		case GAME_STATE_NUM:
			break;
		}

		if (previousScene != NULL) {
			previousScene->render(mRenderer);
			inactiveSceneTexture.renderAtPosition(mRenderer, 0, 0);
		}
		SceneManager::update();
		SceneManager::render(mRenderer);

		SDL_RenderPresent(mRenderer);
	}

	SceneManager::clear();
	TTF_CloseFont(font);
	font = NULL;
	closeMusic();
	closeMedia();
	quitEngines();

	return 0;
}