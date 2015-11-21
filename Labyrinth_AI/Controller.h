#pragma once

#include <string>
#include <SDL2\SDL.h>
#include <list>
#include "Terrain.h"
#include "Noeud.h"
#include "ExecutionResult.h"

class Controller {

private:
	std::string name;
	SDL_Point *characterPos;
	Terrain *terrain;
	std::list<Direction> *op;
public:
	Controller(std::string name, SDL_Point *characterPos, Terrain *terrain, std::list<Direction> *op);
	std::string getName();
	virtual ExecutionResult execute() = 0; // à définir obligatoirement dans chaque classe fille
};