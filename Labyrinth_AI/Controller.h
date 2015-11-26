#pragma once

#include <SDL2\SDL.h>
#include <list>
#include "Terrain.h"
#include "Noeud.h"
#include "ControllerInfo.h"
#include "Direction.h"

// abstract
class Controller {

protected:
	Noeud *etatInitial;
	Terrain *terrain;
	std::list<Direction> *op;
	
	ControllerInfo info;
	Controller(const char name[], Noeud *etatInitial, Terrain *terrain, std::list<Direction> *op);

public:
	ControllerInfo* getInfo();
	void reset();

	bool isBut(Noeud *n);
	bool isValid(Noeud *n);
	bool isStart(Noeud *n);

	virtual void execute() = 0; // à définir obligatoirement dans chaque classe fille
};