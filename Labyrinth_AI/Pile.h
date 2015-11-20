#pragma once

#include <list>

#include "Noeud.h"

class Pile {

public:
	Pile();
	void empil(Noeud* n);
	Noeud* depil();
	void sort();
	void join(Pile enf);
	std::list<Noeud*> pileNoeud;
	bool comparHeur(const Noeud& first, const Noeud& second);
	bool isIn(Noeud* noeud);
};