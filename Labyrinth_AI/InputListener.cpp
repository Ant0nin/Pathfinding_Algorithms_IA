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

			case SDL_WINDOWEVENT:

				switch (event.window.event) {
				
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					scene->render();
					break;

				case SDL_WINDOWEVENT_CLOSE:
					return;
				}

			case SDL_KEYDOWN:

				switch (event.key.keysym.sym) {

				case SDLK_RIGHT: // Fl�che droite
				case SDLK_DOWN: // Fl�che bas
					activeController = selector->selectNextController();
					scene->render();
					break;

				case SDLK_LEFT: // Fl�che gauche
				case SDLK_UP: // Fl�che haut
					activeController = selector->selectPreviousController();
					scene->render();
					break;

				case SDLK_RETURN: // Touche entr�e
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