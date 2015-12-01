#pragma once

#include <queue>
#include <vector>


#include "Noeud.h"

using namespace std;
//TODO : Comparaison inversée
struct ptr_less {
	template<typename Noeud>
	bool operator()(const Noeud& left, const Noeud& right) const {
		return ((left->heur) < (right->heur));
	}
};

class PileNoeud : public priority_queue<Noeud*, vector<Noeud*>, ptr_less> {

public:
	
	PileNoeud();
	void empil(Noeud* n);
	Noeud* depil();
	void sort();
	void join(PileNoeud enf);
	bool comparHeur(const Noeud& first, const Noeud& second);
	bool isIn(Noeud* noeud);
	vector<Noeud*> getC();

};


