#include "TerrainFactory.h"
#include "Tile.h"
#include <SDL2\SDL.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

TerrainFactory::TerrainFactory(Uint8 levelNumber)
{
	this->terrainFilename = "res/lvl/00" + std::to_string(levelNumber) + ".txt";
}

Terrain TerrainFactory::createTerrain() {
	
	string line;
	Terrain terrain;
	ifstream file(this->terrainFilename);

	// TODO : vérifier l'existence du fichier
		
	// Lecture de la position de départ du personnage
	file >> terrain.startPosition.x;
	file >> terrain.startPosition.y;

	// Lecture des dimensions du labyrinthe
	file >> terrain.width;
	file >> terrain.height;

	// Construction des cases du terrain
	Tile* terrainTiles;
	terrainTiles = (Tile*)malloc(sizeof(Tile) * terrain.width * terrain.height);
	for (Uint8 i = 0; i < terrain.height; i++)
	{
		for (Uint8 j = 0; j < terrain.width; j++)
		{
			char char_Value;
			file >> char_Value;
		    terrainTiles[i * terrain.width + j] = Tile(char_Value - 48); // 48 est la valeur ASCII du caractère '0'
		}
	}
	terrain.tiles = terrainTiles;

	file.close();

	return terrain;	
}
