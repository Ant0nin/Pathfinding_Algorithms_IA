#pragma once

#include "Controller.h"
#include <list>

class ControllerSelector
{
private:
	std::list<Controller*> controllers;
	std::list<Controller*>::iterator it;
	
public:
	ControllerSelector(std::list<Controller*> controllers);
	~ControllerSelector();
	Controller* selectNextController();
	Controller* selectPreviousController();
	Controller* getCurrentController();
};

