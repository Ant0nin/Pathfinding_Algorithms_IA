#pragma once

#include <SDL2\SDL.h>
#include "Controller.h"

class Character {

private:
	SDL_Point *position;
	Controller *controller;
};