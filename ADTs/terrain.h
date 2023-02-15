#pragma once

#include "address.h"

typedef struct terrain * Terrain;

//Memory functions:
Terrain terrain_create();
void terrain_destroy(Terrain);

//Set functions:
void terrain_set(Terrain);

//Get functions:
Address terrain_getAddres(Terrain);
char * terrain_getBroker(Terrain);

//Print functions:
void terrain_print(Terrain);

//Compare functions:
int terrain_compareArea(const void *, const void *);