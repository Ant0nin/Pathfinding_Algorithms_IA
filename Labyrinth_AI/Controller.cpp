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
	info.state = ControllerState::IDLE;
	info.bestWay = list<Noeud*>();
	info.charted = list<Noeud*>();
	info.duration = 0;
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
	reset();

	Uint32 startTime = SDL_GetTicks();

	PileNoeud aExplo = PileNoeud();
	PileNoeud dejaExplo = PileNoeud();
	Noeud* curNoeud = NULL;
	aExplo.empil(etatInitial);

	while (aExplo.size() != 0) {
		curNoeud = aExplo.depil();
		dejaExplo.empil(curNoeud);
		info.charted.push_front(curNoeud);

		if (isBut(curNoeud)) break;
		else {
			std::list<Direction>::iterator it = op->begin();
			for (; it != op->end(); it++) {
				Noeud* curNoeudEnfant = curNoeud->successeur(*it);
				heuristique(curNoeudEnfant);
				if (isValid(curNoeudEnfant) && (!dejaExplo.isIn(curNoeudEnfant) && !aExplo.isIn(curNoeudEnfant))) {
					aExplo.empil(curNoeudEnfant);
				}
			}
		}
	}

	info.state = ControllerState::SUCCESS;

	info.bestWay = list<Noeud*>();
	while (!isStart(curNoeud)) {
		info.bestWay.push_front(curNoeud);
		curNoeud = curNoeud->getParent();
	}

	info.duration = SDL_GetTicks() - startTime;
}
