#include "PileNoeud.h"




PileNoeud::PileNoeud()
{
}

void PileNoeud::empil(Noeud* n) {	
	this->push(n);
}

Noeud* PileNoeud::depil()
{
	Noeud* ret = top();
	pop();
	return ret;

}

void PileNoeud::sort() {
	//sort(comparHeur);
}

bool comparHeur(const Noeud* first, const Noeud* second)
{
	return (first->heur < second->heur);
}

void PileNoeud::join(PileNoeud listEnf) {
	/*while (listEnf.pileNoeud.size() != 0) {
		pileNoeud.push_front(listEnf.pileNoeud.pop_back());
	}*/
}

bool PileNoeud::comparHeur(const Noeud & first, const Noeud & second)
{
	return false;
}

bool PileNoeud::isIn(Noeud* noeud) {
	bool ret = find(c.cbegin(), c.cend(), noeud) != c.end();
	return ret;

}

