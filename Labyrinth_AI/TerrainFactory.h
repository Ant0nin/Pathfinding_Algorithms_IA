#pragma once

#include "Terrain.h"
#include <string>

using namespace std;

class TerrainFactory {

private:
	string terrainFilename;
public:
	TerrainFactory(Uint8 levelNumber);
	Terrain createTerrain();
};