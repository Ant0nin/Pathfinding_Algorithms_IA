#pragma once

#include "ControllerState.h"
#include "Noeud.h"

struct ControllerInfo {
	const char *controllerName;
	ControllerState state;
	Noeud *arrive;
	std::list<Noeud*> *cheminement;
	time_t duration;
};
typedef ControllerInfo ControllerInfo;