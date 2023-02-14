#include "ADTs/land.h"
#include <stdlib.h>
#include <stdio.h>

void menu_print();
void menu_actions();

#define EXIT 0
#define REGISTER 1
#define REMOVE 2
#define LIST_ALL 3
#define ORDER_AREA 4
#define LIST_BROKER 5
#define ORDER_CLEANING 6
#define SEARCH_ADDRESS 7
#define REPORT 8

void main() {

    Land land = land_create();

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

void menu_actions() {

    int op = -1;

    while (op != EXIT) {

        menu_print();
        printf("Type the action: ");
        scanf("%d%*c", &op);

        switch (op) {
        
            case EXIT:
                break;

            case REGISTER:
            
                break;

            case REMOVE:
            
                break;

            case LIST_ALL:
                
                break;

            case ORDER_AREA:
                
                break;

            case LIST_BROKER:
                
                break;

            case ORDER_CLEANING:
                
                break;

            case SEARCH_ADDRESS:
                
                break;

            case REPORT:
                
                break;                            
            
            default:
                printf("Invalid action!\n");
                break;
        }
    }
}