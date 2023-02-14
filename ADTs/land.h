#pragma once

typedef struct land * Land;

//Memory functions:
Land land_create();
Land land_realloc(Land);
void land_destroy(Land);