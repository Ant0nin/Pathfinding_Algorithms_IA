#pragma once

#include "Controller.h"
#include "Noeud.h"
#include "Pile.h"
#include "Direction.h"
#include <SDL2\SDL.h>

class AEtoile : public Controller {

public:
	AEtoile(Noeud * etatInitial, Terrain * ter, std::list<Direction>* op);
	virtual void execute() override;
};