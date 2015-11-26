#pragma once

#include "ControllerState.h"
#include "Noeud.h"
#include <list>

using namespace std;

struct ControllerInfo {
	const char *controllerName;
	ControllerState state;
	list<Noeud*> arrive;
	list<Noeud*> cheminement;
	Uint32 duration = 0;
	int cout = 0;
};