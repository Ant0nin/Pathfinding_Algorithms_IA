#pragma once

#include "Controller.h"
#include <list>

class ControlPanel
{
private:
	std::list<Controller*> controllers;
	std::list<Controller*>::iterator it;
	
public:
	ControlPanel(std::list<Controller*> controllers);
	~ControlPanel();
	Controller* selectNextController();
	Controller* selectPreviousController();
	Controller* getCurrentController();
};

