#include "AEtoile1_5.h"
#include "Controller.h"


AEtoile1_5::AEtoile1_5(Noeud * etatInitial, Terrain * ter, std::list<Direction>* op)
	: AEtoile(etatInitial, ter, op)
{
	info.controllerName = "A Etoile (1, 5)";
	poidsDepart = 1;
	poidsArrivee = 5;
}


