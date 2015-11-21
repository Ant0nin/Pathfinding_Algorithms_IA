#include "InputListener.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_ttf.h>

InputListener::InputListener(Scene * scene, ControllerSelector * selector)
{
	this->scene = scene;
	this->selector = selector;
}

InputListener::~InputListener()
{

}

void InputListener::run()
{
	Controller* activeController = selector->getCurrentController();
	SDL_Event event;

	while (1) {

		while (SDL_WaitEvent(&event)) {

			switch (event.type) {

			case SDL_KEYDOWN:

				switch (event.key.keysym.sym) {

				case SDLK_DOWN: // Flèche bas
					activeController = selector->selectNextController();
					scene->render();
					break;

				case SDLK_UP: // Flèche haut
					activeController = selector->selectPreviousController();
					scene->render();
					break;

				case SDLK_RETURN: // Touche entrée
					activeController->execute();
					scene->render();
					break;

				case SDLK_ESCAPE: // Touche echap
					return;
				}

				break;
			}

		}

	}
}