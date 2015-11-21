#pragma once

#include "Controller.h"
#include "Direction.h"
#include "Terrain.h"
#include "Noeud.h"
#include "Pile.h"

#include <SDL2\SDL.h>
#include <string>
#include <stdio.h>

class Meilleurdabord : public Controller {

public :
	Meilleurdabord(SDL_Point *characterPosition, Terrain *terrain, std::list<Direction> *op);
	virtual void execute() override;

private :
	bool isValid(SDL_Point *pos);
	bool isBut(SDL_Point *pos);
};