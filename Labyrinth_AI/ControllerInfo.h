#pragma once

#include "ControllerState.h"
#include "Noeud.h"
#include "PileNoeud.h"
#include <list>

using namespace std;

struct ControllerInfo {
	const char *controllerName;
	ControllerState state;
	list<Noeud*> bestWay;
	list<Noeud*> charted;
	Uint32 duration = 0;
	int cout = 0;
};

// TODO : Poser un ratio d'effacit