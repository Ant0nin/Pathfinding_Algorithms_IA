#pragma once

#include "Tile.h"
#include <SDL2\SDL.h>

struct Terrain {
	Tile *tiles;
	SDL_Point startPosition;
	Uint16 terrain_width;
	Uint16 terrain_height;
};