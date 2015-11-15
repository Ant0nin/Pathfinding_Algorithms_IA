#include "Pile.h"





Pile::Pile() {

	pileNoeud = std::list<Noeud>();
	length = 0;
}

void Pile::insert(Noeud n, int heur) {

	
	std::list<int>::iterator it;
	it = pileNoeud.begin;
	pileNoeud.push_back(n);

	length++;


}

void Pile::sort(Noeud n, int heur) {

	
	pileNoeud.sort(comparHeur);


}


bool comparHeur(const Noeud& first, const Noeud& second)
{
	

}
