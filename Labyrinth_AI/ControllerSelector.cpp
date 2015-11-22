#include "ControllerSelector.h"
#include "Controller.h"
#include <SDL2\SDL.h>
#include "const.h"

ControllerSelector::ControllerSelector(std::list<Controller*> controllers)
{
	this->controllers = controllers;
	it = this->controllers.begin();
	currentIndex = 0;
}

ControllerSelector::~ControllerSelector()
{
}

Controller * ControllerSelector::selectNextController()
{
	currentIndex++;
	if (currentIndex < (controllers.size() - 1))
	{
		it = std::next(it);
	}
	else {
		currentIndex = 0;
		it = this->controllers.begin();
	}
	return getCurrentController();
}

Controller * ControllerSelector::selectPreviousController()
{
	currentIndex--;
	it = this->controllers.begin();

	if (currentIndex < 0)
	{
		currentIndex = (controllers.size() - 1);
	}
	it = std::next(it, currentIndex);

	return getCurrentController();
}

Controller *ControllerSelector::getCurrentController()
{
	return *it;
}