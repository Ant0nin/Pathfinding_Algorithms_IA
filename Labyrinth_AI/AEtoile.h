#pragma once


#include "Controller.h"
#include "Noeud.h"
#include "Pile.h"
#include "Direction.h"
#include <SDL2\SDL.h>
#include <string>
#include <stdio.h>


class AEtoile {

public:
	AEtoile(Noeud* etatinitial, Direction op);

};