#include "ControlPanel.h"
#include <SDL2\SDL.h>
#include "const.h"

ControlPanel::ControlPanel(std::list<Controller*> controllers)
{
	this->controllers = controllers;
	it = this->controllers.begin();
}

ControlPanel::~ControlPanel()
{

}

Controller * ControlPanel::selectNextController()
{
	it = std::next(it);
	return getCurrentController();
}

Controller * ControlPanel::selectPreviousController()
{
	it = std::prev(it);
	return getCurrentController();
}

Controller *ControlPanel::getCurrentController()
{
	return (Controller*)&*it;
}