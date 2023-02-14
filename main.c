#include "ADTs/land.h"
#include <stdlib.h>

int main() {

    Land land = land_create();


    land_destroy(land);

    return EXIT_SUCCESS;
}