#pragma once

#include "Controller.h"
#include "Direction.h"
#include <SDL2\SDL.h>

class Noeud {

private:
	Noeud *parent;
	int heur;
	SDL_Point pos;

public:
	Noeud(SDL_Point pos, Noeud* parent = nullptr);
	Noeud* successeur(Direction op);
	int calcHeur();

	bool isValid(Terrain *terrain);
	bool isBut(Terrain *terrain);

	Noeud* getParent();
	SDL_Point getPosition();
	
};