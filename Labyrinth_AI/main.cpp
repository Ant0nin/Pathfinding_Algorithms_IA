#include <SDL2\SDL.h>
#include "TerrainFactory.h"
#include "Character.h"
#include "Meilleurdabord.h"
#include "Scene.h"
#include "const.h"

#undef main

int main(int argc, int *argv) {

	SDL_Init(SDL_INIT_VIDEO);

	TerrainFactory *factory = new TerrainFactory(LEVEL_NUMBER);
	Terrain terrain = factory->createTerrain();

	Character character;
	character.position = &terrain.startPosition;

	Scene *scene = new Scene(&terrain, &character);
	scene->render();

	SDL_Delay(10000); // TODO : retirer

	SDL_Quit();
	return 0;
}