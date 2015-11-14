#pragma once

#include "Terrain.h"

class TerrainFactory {

private:
	char terrainFilename[16];
public:
	TerrainFactory(Uint16 levelNumber);
	Terrain createTerrain();
};