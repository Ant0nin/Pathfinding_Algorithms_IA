#include "AEtoile.h"

using namespace std;

AEtoile::AEtoile(Noeud * etatInitial, Terrain * terrain, std::list<Direction>* op)
	: Controller("A Star", etatInitial, terrain, op)
{
}
