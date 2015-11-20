#pragma once

#include <SDL2\SDL.h>
#include "Terrain.h"
#include "Character.h"

class Scene {

private:

	SDL_Renderer *renderer;
	SDL_Window *window;

	SDL_Texture *texture_bg;
	SDL_Texture *texture_fg;
	SDL_Texture *spritesheet_character;
	SDL_Texture *texture_floor_unit;

	Terrain *terrain;
	Character *character;

	void initTextures();

public:
	Scene(Terrain *terrain, Character *character);
	void render();

};