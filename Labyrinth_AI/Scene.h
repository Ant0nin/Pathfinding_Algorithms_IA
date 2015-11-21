#pragma once

#include <SDL2\SDL.h>
#include "Terrain.h"
#include "Character.h"
#include "ControlPanel.h"
#include "ExecutionResult.h"

class Scene {

private:

	SDL_Renderer *renderer;
	SDL_Window *window;

	SDL_Texture *texture_bg;
	SDL_Texture *spritesheet_character;
	SDL_Texture *texture_floor_unit;
	SDL_Texture *texture_exit_unit;

	Terrain *terrain;
	Character *character;

	void initTextures();

public:
	Scene(Terrain *terrain, Character *character, ControlPanel *panel);
	void render();
	void render(ExecutionResult *algoResult);

};