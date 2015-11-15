#pragma once

#include <list>

#include "Noeud.h"

class Pile {

public:
	Pile();
	int length;
	void insert(Noeud n, int heur);

private:
	std::list<Noeud> pileNoeud;
};