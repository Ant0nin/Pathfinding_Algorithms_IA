#pragma once

#include <queue>
#include <vector>


#include "Noeud.h"

using namespace std;

class PileNoeud : public priority_queue<Noeud*, vector<Noeud*>,Compar> {

public:
	

	PileNoeud();
	void empil(Noeud* n);
	Noeud* depil();
	void sort();
	void join(PileNoeud enf);
	std::priority_queue<Noeud*> pileNoeud;
	bool comparHeur(const Noeud& first, const Noeud& second);
	bool isIn(Noeud* noeud);
};


class Compar
{
public:
	bool operator()(const Noeud* &a1, const Noeud* &a2)
	{
		return a1->heur < a2->heur;
	}
};