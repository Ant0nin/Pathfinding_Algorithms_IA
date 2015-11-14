#include <SDL2\SDL.h>
#include "TerrainFactory.h"
#include "const.h"

#undef main

int main(int argc, int *argv) {

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Terrain terrain = new TerrainFactory(LEVEL_FILENAME)->createTerrain();

	SDL_Delay(2000);

	SDL_Quit();
	return 0;
}