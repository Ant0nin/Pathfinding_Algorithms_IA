#pragma once

#include "ControllerState.h"
#include "Noeud.h"
#include <list>

struct ControllerInfo {
	const char *controllerName;
	ControllerState state;
	Noeud *arrive;
	std::list<Noeud*> cheminement;
	Uint32 duration = 0;
};
typedef ControllerInfo ControllerInfo;