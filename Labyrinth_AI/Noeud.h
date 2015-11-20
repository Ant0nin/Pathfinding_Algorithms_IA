#pragma once


#include "Controller.h"
#include "Operateur.h"
#include <cmath>


class Noeud {

public:
	Noeud(int x,int y,Noeud* pere);
	Noeud* sucesseur(Operateur op);
	bool valid();
	bool isBut();
	Noeud* getPopa();
	int calcHeur();

	int heur, x, y;




};