#include "PileNoeud.h"




/*PileNoeud::PileNoeud() : std::priority_queue<Noeud*,std::vector<Noeud*>, Compar>()
{
}*/

void PileNoeud::empil(Noeud* n) {	
	push(n);
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
	return std::find(c.begin, c.end, &noeud) != c.end();
}

