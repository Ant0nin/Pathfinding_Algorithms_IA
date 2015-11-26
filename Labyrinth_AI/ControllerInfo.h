#pragma once

#include "ControllerState.h"
#include "Noeud.h"
#include "PileNoeud.h"
#include <list>

using namespace std;

struct ControllerInfo {
	const char *controllerName;
	ControllerState state;
	Noeud* arrive;
	PileNoeud* cheminement;
	Uint32 duration = 0;
	int cout = 0;
};