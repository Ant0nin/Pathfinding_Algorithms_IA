#include <SDL2\SDL.h>
#include "TerrainFactory.h"
#include "Character.h"
#include "Scene.h"
#include "const.h"

#undef main

int main(int argc, int *argv) {

	SDL_Init(SDL_INIT_VIDEO);

	TerrainFactory *factory = new TerrainFactory(LEVEL_NUMBER);
	Terrain terrain = factory->createTerrain();

	Character *character = new Character(&terrain.startPosition);

	Scene *scene = new Scene(&terrain, character);
	scene->render();

	SDL_Delay(10000);

	SDL_Quit();
	return 0;
}