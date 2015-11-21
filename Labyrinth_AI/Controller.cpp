#include "Controller.h"
#include <string>

Controller::Controller(std::string name, SDL_Point * characterPos, Terrain * terrain, std::list<Direction>* op)
{
	this->name = name;
	this->characterPos = characterPos;
	this->terrain = terrain;
	this->op = op;
}

std::string Controller::getName()
{
	return this->name;
}
