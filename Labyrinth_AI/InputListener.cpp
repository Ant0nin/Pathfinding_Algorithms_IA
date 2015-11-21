#include "InputListener.h"
#include "ExecutionResult.h"
#include <SDL2\SDL.h>

InputListener::InputListener(Scene * scene, ControlPanel * panel)
{
	this->scene = scene;
	this->controlPanel = panel;
}

InputListener::~InputListener()
{

}

void InputListener::run()
{
	ExecutionResult algoResult;

	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
			case SDL_KEYDOWN:

			switch (event.key.keysym.sym) {

				case SDLK_DOWN: // Flèche bas
					controlPanel->selectNextController();
					scene->render();
					break;

				case SDLK_UP: // Flèche haut
					controlPanel->selectPreviousController();
					scene->render();
					break;

				case SDLK_RETURN: // Touche entrée
					algoResult = controlPanel->getCurrentController()->execute();
					scene->render(&algoResult);
					break;

				case SDLK_ESCAPE: // Touche echap
					SDL_Quit();
					exit(EXIT_SUCCESS);
					break;
				}

			break;
		}
	}
}