#pragma once

#include <SDL2\SDL.h>
#include <SDL2\SDL_ttf.h>
#include "Terrain.h"
#include "Character.h"
#include "Controller.h"
#include "ControllerSelector.h"

class Scene {

private:

	SDL_Renderer *renderer;
	SDL_Window *window;

	SDL_Texture *texture_bg;
	SDL_Texture *spritesheet_character;
	SDL_Texture *texture_floor_unit;
	SDL_Texture *texture_exit_unit;
	SDL_Texture *texture_console;

	Terrain *terrain;
	Character *character;

	ControllerSelector *selector;
	TTF_Font *font;

	void initTextures();

	void prepareConsole(int winWidth, int winHeight);
	void prepareMap(int winWidth, int winHeight);
	void preparePathTrace(int winWidth, int winHeight);

public:
	Scene(Terrain *terrain, Character *character, ControllerSelector *selector);
	~Scene();
	void render();
};