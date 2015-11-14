#include "TerrainFactory.h"
#include <SDL2\SDL.h>
#include <string>

using namespace std;

TerrainFactory::TerrainFactory(Uint16 levelNumber)
{
	strcat(this->terrainFilename, "res/lvl/");
	strcat(this->terrainFilename, SDL_itoa(levelNumber, NULL, 10));
	strcat(this->terrainFilename, ".txt");
}

Terrain TerrainFactory::createTerrain() {
	
	FILE* file = fopen(this->terrainFilename, "r");
	
	char input;
	Uint16 line = 0;

	while (true) {

		input = fgetc(file);
		if (input == '\n') {
			switch (line) {
				// TODO
			}
			line++;
		}
		else {

		}

	}

	fclose(file);
}
