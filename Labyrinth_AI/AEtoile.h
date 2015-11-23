#pragma once

#include "Controller.h"
#include "Noeud.h"
#include "Pile.h"
#include "Direction.h"
#include <SDL2\SDL.h>

class AEtoile : public Controller {

public:
	AEtoile(SDL_Point *characterPosition, Terrain *terrain, std::list<Direction> *op);
	virtual void execute() override;
};