#pragma once

#include <SDL2\SDL.h>
#include "Terrain.h"
#include "Character.h"

class Scene {

private:

	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Texture *spritesheet;

	Terrain *terrain;
	Character *character;

public:
	Scene(Terrain *terrain, Character *character);
	void render();

};