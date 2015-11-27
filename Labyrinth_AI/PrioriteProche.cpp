#include "PrioriteProche.h"
#include "Controller.h"
#include <string>
#include <list>

using namespace std;


PrioriteProche::PrioriteProche(Noeud* etatInitial, Terrain *ter, std::list<Direction> *op)
	: Controller("Priorite au plus proche", etatInitial, ter, op)
{

}

void PrioriteProche::heuristique(Noeud* n) {
	
	n->heur = -1*sqrt(pow(n->getPosition().x - etatInitial->getPosition().x, 2) + pow(n->getPosition().y - etatInitial->getPosition().y, 2));
}
