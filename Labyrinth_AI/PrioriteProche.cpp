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

	n->heur = -sqrt(pow(etatInitial->getPosition().x - n->getPosition().x, 2) + pow(etatInitial->getPosition().y - n->getPosition().y, 2));
}