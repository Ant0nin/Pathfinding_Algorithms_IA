#pragma once

#include "Tile.h"
#include <SDL2\SDL.h>

struct Terrain {
	Tile *tiles;
	SDL_Point startPosition;
	Uint16 width;
	Uint16 height;
};
typedef Terrain Terrain;