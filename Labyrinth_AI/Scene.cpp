#include "Scene.h"
#include "const.h"
#include <SDL2\SDL.h>

Scene::Scene(Terrain *terrain, Character *character)
{
	this->window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// TODO : load spritesheet

	this->terrain = terrain;
	this->character = character;
}

void Scene::render()
{
	int winWidth, winHeight;
	SDL_GetWindowSize(window, &winWidth, &winHeight);
	SDL_Rect drawZone;

	if (winWidth <= winHeight)
		drawZone.w = (winWidth - winWidth % terrain->width) / terrain->width;
	else
		drawZone.w = (winHeight - winHeight % terrain->height) / terrain->height;
	drawZone.h = drawZone.w;
	drawZone.x = 0;
	drawZone.y = 0;

	// TODO : utiliser une spritesheet au lieu de fillRect
	for (int i = 0; i < terrain->height; i++) {
		for (int j = 0; j < terrain->width; j++) {
			
			Tile tile = terrain->tiles[j + i * terrain->width];
			
			switch (tile) {
				case FLOOR:
					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // RED = sol
					break;

				case WALL:
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // GREEN = mur
					break;

				case EXIT:
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // BLUE = sortie
					break;
			}
			SDL_RenderFillRect(renderer, &drawZone);

			drawZone.x = j * drawZone.w;
		}
		drawZone.y = i * drawZone.h;
	}

	SDL_RenderPresent(renderer);
}
