#pragma once

#include "Direction.h"
#include "Terrain.h"
#include <SDL2\SDL.h>

class Noeud {

private:
	Noeud *parent;
	SDL_Point pos;

public:
	Noeud(SDL_Point pos, Noeud* parent = nullptr);
	Noeud* successeur(Direction op);
	int calcHeur();

	Noeud* getParent();
	SDL_Point getPosition();

	int h, g, f,heur;
	
};