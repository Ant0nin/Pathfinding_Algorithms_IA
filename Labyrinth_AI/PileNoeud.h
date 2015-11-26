#pragma once

#include <queue>
#include <vector>


#include "Noeud.h"

using namespace std;
/*

struct ptr_less {
	template<class PileNoeud>
	bool operator()(const Noeud& left, const Noeud& right) const {
		return ((*left) <(*right));
	}
};*/

class PileNoeud : public priority_queue<Noeud*> {

public:
	
	PileNoeud();
	void empil(Noeud* n);
	Noeud* depil();
	void sort();
	void join(PileNoeud enf);
	//std::priority_queue<Noeud*, vector<Noeud*>, ptr_less> pileNoeud;
	bool comparHeur(const Noeud& first, const Noeud& second);
	bool isIn(Noeud* noeud);
	vector<Noeud*> getC();

};


