#pragma once

#include <SDL2\SDL.h>

class Tile {

public:
	static enum Type {
		WALL,
		FLOOR,
		EXIT
	};

	Tile(Type type, SDL_Texture *texture);

private:
	Type type;
};