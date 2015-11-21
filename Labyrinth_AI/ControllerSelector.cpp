#include "ControllerSelector.h"
#include "Controller.h"
#include <SDL2\SDL.h>
#include "const.h"

ControllerSelector::ControllerSelector(std::list<Controller*> controllers)
{
	this->controllers = controllers;
	it = this->controllers.begin();
}

ControllerSelector::~ControllerSelector()
{

}

Controller * ControllerSelector::selectNextController()
{
	it = std::next(it);
	return getCurrentController();
}

Controller * ControllerSelector::selectPreviousController()
{
	it = std::prev(it);
	return getCurrentController();
}

Controller *ControllerSelector::getCurrentController()
{
	return (Controller*)&*it;
}