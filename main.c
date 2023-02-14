#include "ADTs/land.h"
#include <stdio.h>

void menu_print();
Land menu_actions(Land);

void main() {

    Land land = land_create();

    initialize_menu_functions();

    land = menu_actions(land);

    land_destroy(land);
}

void menu_print() {

    printf("Functionalities menu:\n\n");

    printf("0 - Exit\n");
    printf("1 - Register terrain\n");
    printf("2 - Remove terrain\n");
    printf("3 - List land\n");
    printf("4 - Order land by area\n");
    printf("5 - List land by broker\n");
    printf("6 - Order land by date of last cleaning\n");
    printf("7 - Search for terrain by address\n");
    printf("8 - Generate land report\n");
    printf("\n");
}

Land menu_actions(Land l) {

    int action = -1;

    while (action) {

        menu_print();
        printf("Type the action: ");
        scanf("%d%*c", &action);

        l = executeFunction(action, l);
    }

    return l;
}