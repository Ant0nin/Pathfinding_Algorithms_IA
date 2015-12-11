#include "AEtoile5_1.h"


AEtoile5_1::AEtoile5_1(Noeud * etatInitial, Terrain * ter, std::list<Direction>* op)
	: AEtoile(etatInitial, ter, op)
{
	info.controllerName = "A Etoile (5, 1)";
	poidsDepart = 5;
	poidsArrivee = 1;
}
