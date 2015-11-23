#pragma once

#include "ControllerState.h"
#include "Noeud.h"
#include <list>

using namespace std;

struct ControllerInfo {
	const char *controllerName;
	ControllerState state;
	Noeud* arrive;
	list<Noeud*> cheminement;
	Uint32 duration = 0;
};