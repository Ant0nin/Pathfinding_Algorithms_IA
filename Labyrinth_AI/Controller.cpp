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
