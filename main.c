#include "ADTs/land.h"
#include <stdio.h>

void menu_print();
void menu_actions(Land);

void main() {

    Land land = land_create();

    initialize_menu_functions();

    menu_actions(land);

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

void menu_actions(Land l) {

    int op = -1;

    while (op) {

        menu_print();
        printf("Type the action: ");
        scanf("%d%*c", &op);

        executeFunction(op, l);
    }
}