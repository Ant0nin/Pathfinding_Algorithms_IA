#include "CoutsUniform.h"
#include "PileNoeud.h"


CoutsUniform::CoutsUniform(Noeud * etatInitial, Terrain * terrain, std::list<Direction> * op)
	: Controller("Uniform-cost search", etatInitial, terrain, op)
{
}

void CoutsUniform::heuristique(Noeud *n)
{
	if (isStart(n))
		n->heur = 0;
	else {
		n->heur = n->getParent()->heur + 1;
	}
}