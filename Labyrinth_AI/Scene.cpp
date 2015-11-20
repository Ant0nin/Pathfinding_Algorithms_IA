#include "Scene.h"
#include "const.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>

Scene::Scene(Terrain *terrain, Character *character)
{
	this->window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	this->terrain = terrain;
	this->character = character;

	initTextures();
}

void Scene::initTextures()
{
	SDL_Surface *buffer;
	
	buffer = IMG_Load(TEXTURE_BACKGROUND);
	this->texture_bg = SDL_CreateTextureFromSurface(this->renderer, buffer);

	buffer = IMG_Load(TEXTURE_FOREGROUND);
	this->texture_fg = SDL_CreateTextureFromSurface(this->renderer, buffer);

	buffer = IMG_Load(TEXTURE_FLOOR_UNIT);
	this->texture_floor_unit = SDL_CreateTextureFromSurface(this->renderer, buffer);

	buffer = IMG_Load(TEXTURE_EXIT_UNIT);
	this->texture_exit_unit = SDL_CreateTextureFromSurface(this->renderer, buffer);

	buffer = IMG_Load(SPRITESHEET_CHARACTER);
	this->spritesheet_character = SDL_CreateTextureFromSurface(this->renderer, buffer);

	SDL_free(buffer);
}

void Scene::render()
{
	int winWidth, winHeight;
	SDL_GetWindowSize(window, &winWidth, &winHeight);
	SDL_Rect drawZone;

	drawZone.x = 0;
	drawZone.y = 0;
	drawZone.w = winWidth;
	drawZone.h = winHeight;
	SDL_RenderCopy(renderer, texture_bg, NULL, &drawZone);

	if (winWidth <= winHeight)
		drawZone.w = (winWidth - winWidth % terrain->width) / terrain->width;
	else
		drawZone.w = (winHeight - winHeight % terrain->height) / terrain->height;
	drawZone.h = drawZone.w;

	for (int i = 0; i < terrain->height; i++) {

		drawZone.y = i * drawZone.h;

		for (int j = 0; j < terrain->width; j++) {
			
			drawZone.x = j * drawZone.w;

			Tile tile = terrain->tiles[i * terrain->width + j];
			
			switch (tile) {
				case FLOOR:
					SDL_RenderCopy(renderer, texture_floor_unit, NULL, &drawZone);
					break;

				case EXIT:
					SDL_RenderCopy(renderer, texture_exit_unit, NULL, &drawZone);
					break;
			}

		}
	}

	/*drawZone.x = 0;
	drawZone.y = 0;
	drawZone.w = winWidth;
	drawZone.h = winHeight;
	SDL_RenderCopy(renderer, texture_fg, NULL, &drawZone);*/

	SDL_RenderPresent(renderer);
}
