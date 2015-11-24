#pragma once

#include <SDL2\SDL.h>
#include <list>
#include "Terrain.h"
#include "Noeud.h"
#include "ControllerInfo.h"
#include "Direction.h"

// abstract
class Controller {

private:
	SDL_Point *characterPos;
	Terrain *terrain;
	std::list<Direction> *op;
	
protected:
	ControllerInfo info;
	Controller(const char name[], Noeud *etatInitial, Terrain *terrain, std::list<Direction> *op);

public:
	ControllerInfo* getInfo();
	void reset();
	virtual void execute() = 0; // à définir obligatoirement dans chaque classe fille
};