#include "land.h"
#include "terrain.h"
#include <stdlib.h>

struct land {

    Terrain * land;
    int land_used;
    int land_alloc;
};

Land land_create() {

    Land l = (Land)calloc(1, sizeof(struct land));
    l->land = (Terrain *)calloc(100, sizeof(Terrain));

    for (int i=0; i < 100; i++) 
        l->land[i] = terrain_create();
    
    l->land_alloc = 100;
    l->land_used = 0;

    return l;
}

Land land_realloc(Land l) {

    l->land_alloc *= 2;
    l->land = (Terrain *)realloc(l->land, l->land_alloc * sizeof(Terrain));

    for (int i=l->land_used; i < l->land_alloc; i++)
        l->land[i] = terrain_create();

    return l;
}

void land_destroy(Land l) {

    for (int i=0; i < l->land_alloc; i++)
        terrain_destroy(l->land[i]);

    free(l->land);
    free(l);
}