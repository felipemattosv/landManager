#include "land.h"
#include "terrain.h"
#include <stdlib.h>
#include <stdio.h>

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


void Exit(Land l) {

    printf("Closing program...\n");
}

void Register(Land l) {

}

void Remove(Land l) {

}

void ListAll(Land l) {

}

void OrderArea(Land l) {

}

void ListByBroker(Land l) {

}

void OrderCleaning(Land l) {

}

void SearchAddress(Land l) {

}

void Report(Land l) {

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

void executeFunction(int action, Land l) {

    if (menu_functions[action] != NULL)
        menu_functions[action](l);
    else
        printf("Action invalid!\n");
}