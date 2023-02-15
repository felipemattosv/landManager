#include "land.h"
#include "terrain.h"
#include "address.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

functionality menu_functions[9];


Land Exit(Land l) {

    printf("Closing program...\n");

    return l;
}

Land Register(Land l) {

    if (l->land_used == l->land_alloc)
        l = land_realloc(l);
    
    terrain_set(l->land[l->land_used]);

    l->land_used++;

    return l;
}

Land Remove(Land l) {

    Address target = address_create();

    printf("Type the address of the terrain that will be removed:\n");
    address_set(target);

    int indexOnArray = -1;

    for(int i=0; i < l->land_used; i++)
        if (address_compare(terrain_getAddres(l->land[i]), target))
            indexOnArray = i;

    if (indexOnArray != -1) {

        terrain_destroy(l->land[indexOnArray]);

        for (int i = indexOnArray; i < l->land_alloc - 1; i++)
            l->land[i] = l->land[i + 1];

        l->land_alloc--;
        l->land_used--;
    }
    else printf("Terrain not found at the address entered!\n\n");

    address_destroy(target);

    return l;
}

Land ListAll(Land l) {

    for (int i=0; i < l->land_used; i++) {
        
        terrain_print(l->land[i]);
        printf("\n");
    }

    return l;
}

Land OrderArea(Land l) {

    qsort(l->land, l->land_used, sizeof(Terrain), terrain_compareArea);

    return l;
}

Land ListByBroker(Land l) {

    char target[64];
    printf("Search terrains associated to: ");
    scanf("%[^\n]", target);

    for(int i=0; i < l->land_used; i++)
        if (strcmp(target, terrain_getBroker(l->land[i])) == 0) {
            
            terrain_print(l->land[i]);
            printf("\n");
        }
    
    return l;
}

Land OrderCleaning(Land l) {

    qsort(l->land, l->land_used, sizeof(Terrain), terrain_compareDate);

    return l;
}

Land SearchAddress(Land l) {


    return l;
}

Land Report(Land l) {


    return l;
}

void initialize_menu_functions() {

    menu_functions[0] = Exit;
    menu_functions[1] = Register;
    menu_functions[2] = Remove;
    menu_functions[3] = ListAll;
    menu_functions[4] = OrderArea;
    menu_functions[5] = ListByBroker;
    menu_functions[6] = OrderCleaning;
    menu_functions[7] = SearchAddress;
    menu_functions[8] = Report;
}

Land executeFunction(int action, Land l) {

    if (menu_functions[action] != NULL)
        return menu_functions[action](l);
    else
        printf("Action invalid!\n");
}