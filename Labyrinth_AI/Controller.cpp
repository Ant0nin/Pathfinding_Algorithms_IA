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
