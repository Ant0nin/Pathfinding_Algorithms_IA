#include "TerrainFactory.h"
#include "Tile.h"
#include <SDL2\SDL.h>
#include <string>
#include <fstream>

using namespace std;

#define READ_NEXT_LINE	getline(file, line); \
						numericalValue = stoi(line, NULL, 10);

TerrainFactory::TerrainFactory(Uint8 levelNumber)
{
	this->terrainFilename = "res/lvl/00" + std::to_string(levelNumber) + ".txt";
}

Terrain TerrainFactory::createTerrain() {
	
	string line;
	Uint16 numericalValue;
	Terrain terrain;
	SDL_Point startPosition;
	ifstream file(this->terrainFilename);
	
	// Lecture de la position de départ du personnage
	READ_NEXT_LINE
	startPosition.x = numericalValue;
	READ_NEXT_LINE
	startPosition.y = numericalValue;
	terrain.startPosition = startPosition;
	
	// Lecture des dimensions du labyrinthe
	READ_NEXT_LINE
	terrain.width = numericalValue;
	READ_NEXT_LINE
	terrain.height = numericalValue;

	// Construction des cases du terrain
	Tile* terrainTiles;
	terrainTiles = (Tile*)malloc(sizeof(Tile) * terrain.width * terrain.height);
	for (Uint8 i = 0; i < terrain.height; i++)
	{
		getline(file, line);
		for (Uint8 j = 0; j < terrain.width; j++) 
		{
			*terrainTiles = Tile(line[j] - 48); // 48 est la valeur décimale de 0 dans la table ASCII
			terrainTiles++; // décalage d'une case vers la droite
		}
	}
	terrain.tiles = terrainTiles;

	file.close();

	return terrain;
}
