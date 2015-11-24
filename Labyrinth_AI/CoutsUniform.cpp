#include "CoutsUniform.h"



CoutsUniform::CoutsUniform(Noeud * etatInitial, Terrain * terrain, std::list<Direction> * op)
	: Controller("Uniform-cost search", etatInitial, terrain, op)
{
}

void CoutsUniform::execute()
{
}

