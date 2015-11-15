#pragma once

#include <SDL2\SDL.h>
#include "Controller.h"

class Character {

private:
	SDL_Point *position;
	Controller *controller;

public:
	Character(SDL_Point *startPosition); // TODO : ajouter 'controller' au constructeur
};