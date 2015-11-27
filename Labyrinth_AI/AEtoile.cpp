#include "AEtoile.h"

using namespace std;

AEtoile::AEtoile(Noeud * etatInitial, Terrain * terrain, std::list<Direction>* op)
	: Controller("A Star", etatInitial, terrain, op)
{
}

void AEtoile::heuristique(Noeud* n) {
	//n->heur = sqrt(pow(n->getPosition().x - etatInitial->getPosition().x, 2) + pow(n->getPosition().y - etatInitial->getPosition().y, 2));
}
