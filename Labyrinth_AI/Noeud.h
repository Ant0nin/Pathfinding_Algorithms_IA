#pragma once


#include "Controller.h"

class Noeud {

public:
	Noeud();
	Noeud sucesseur(Operateur op);
	bool valid();
	bool isBut();
	int heur, x, y;
	Noeud node;

};