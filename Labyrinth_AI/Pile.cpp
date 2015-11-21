#include "Pile.h"



Pile::Pile() {
	pileNoeud = std::list<Noeud*>();
}

void Pile::empil(Noeud* n) {	
	pileNoeud.push_back(n);
}

Noeud* Pile::depil()
{
	return &pileNoeud.pop_front;
}

void Pile::sort() {
	pileNoeud.sort(comparHeur);
}

bool comparHeur(const Noeud* first, const Noeud* second)
{
	return (first->heur < second->heur);
}

void Pile::join(Pile listEnf) {
	while (listEnf.pileNoeud.size != 0) {
		pileNoeud.push_front(listEnf.pileNoeud.pop_back);
	}
}

bool Pile::comparHeur(const Noeud & first, const Noeud & second)
{
	return false;
}

bool Pile::isIn(Noeud* noeud) {
	return std::find(pileNoeud.begin(), pileNoeud.end(), &noeud) != pileNoeud.end();
}

