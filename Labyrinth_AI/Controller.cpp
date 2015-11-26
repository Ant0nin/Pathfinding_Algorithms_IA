#include "Controller.h"
#include "ControllerInfo.h"

Controller::Controller(const char name[], Noeud *etatInitial, Terrain * terrain, std::list<Direction>* op)
{
	info.controllerName = name;
	this->etatInitial = etatInitial;
	this->terrain = terrain;
	this->op = op;
}

ControllerInfo * Controller::getInfo()
{
	return &info;
}

void Controller::reset()
{
	// TODO
}


bool Controller::isBut(Noeud* n) {
	return (terrain->tiles[n->getPosition().x + terrain->width * n->getPosition().y] == Tile::EXIT);
}

bool Controller::isStart(Noeud *n) {
	return (!n->getParent());
}

bool Controller::isValid(Noeud *n) {
	return (terrain->tiles[n->getPosition().x + terrain->width * n->getPosition().y] != Tile::WALL);
}

void Controller::execute()
{
	PileNoeud aExplo = PileNoeud(), dejaExplo = PileNoeud();
	Noeud* curNoeud = NULL;
	aExplo.empil(etatInitial);

	while (aExplo.size() != 0) {
		curNoeud = aExplo.depil();
		dejaExplo.empil(curNoeud);
		if (isBut(curNoeud)) break;
		else {
			std::list<Direction>::iterator it = op->begin();
			for (; it != op->end(); it++) {
				Noeud* curNoeudEnfant = curNoeud->successeur(*it);
				if (isValid(curNoeudEnfant) && (!dejaExplo.isIn(curNoeudEnfant) && !aExplo.isIn(curNoeudEnfant))) {
					heuristique(curNoeudEnfant);
					aExplo.empil(curNoeudEnfant);
				}
			}
		}
	}

	info.bestWay = new PileNoeud();
	info.charted = &dejaExplo;
	while (!isStart(curNoeud)) {
		info.cout++;
		info.bestWay->empil(curNoeud);
		curNoeud = curNoeud->getParent();
	}

	printf("Depart : %i / %i : %i/%i parcouru\n", curNoeud->getPosition(), info.cout, dejaExplo.size());
}
