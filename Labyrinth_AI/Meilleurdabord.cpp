#include "Meilleurdabord.h"
#include "Controller.h"
#include <string>

using namespace std;

//TODO : finir l'algo et afficher le chemin

Meilleurdabord::Meilleurdabord(Noeud* etatInitial, Terrain *ter, std::list<Direction> *op)
	: Controller("Best First", etatInitial, ter, op)
{
}

void Meilleurdabord::heuristique(Noeud* n) {
	n->heur=sqrt(pow(n->getPosition().x - etatInitial->getPosition().x,2) + pow(n->getPosition().y - etatInitial->getPosition().y, 2));
}
