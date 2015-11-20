#pragma once


#include "Controller.h"
#include "Direction.h"
#include <cmath>
#include <SDL2\SDL.h>


class Noeud {

public:
	Noeud(int x,int y,Noeud* pere);
	Noeud sucesseur(Direction op);
	bool valid();
	bool isBut();
	Noeud* getPopa();
	int calcHeur();

	int heur;
	SDL_Point pos;




};