#include "Controller.h"
#include "ControllerInfo.h"

Controller::Controller(const char name[], SDL_Point * characterPos, Terrain * terrain, std::list<Direction>* op)
{
	info.controllerName = name;
	this->characterPos = characterPos;
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
