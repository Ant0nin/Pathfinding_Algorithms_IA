#pragma once

#include "Controller.h"
#include "Direction.h"
#include "Terrain.h"
#include "Noeud.h"
#include "PileNoeud.h"
#include <math.h>

#include <SDL2\SDL.h>
#include <string>
#include <stdio.h>

class PrioriteProche : public Controller {

protected:
	list<SDL_Point*> listExit;

public:
	PrioriteProche(Noeud *etatInitial, Terrain *terrain, std::list<Direction> *op);
	virtual void heuristique(Noeud *) override;
};