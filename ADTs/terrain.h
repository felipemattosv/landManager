#pragma once

typedef struct terrain * Terrain;

//Memory functions:
Terrain terrain_create();
void terrain_destroy(Terrain);

//Set functions:
void terrain_set(Terrain);