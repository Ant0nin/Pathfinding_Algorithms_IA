#pragma once
#include "AEtoile.h"
class AEtoile5_1 :
	public AEtoile
{
public:
	AEtoile5_1(Noeud * etatInitial, Terrain * ter, std::list<Direction>* op);
};

