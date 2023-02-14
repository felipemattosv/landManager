#pragma once

typedef struct land * Land;

//Memory functions:
Land land_create();
Land land_realloc(Land);
void land_destroy(Land);


typedef void (*functionality)(Land l); //functionality is a type of function that receive one Land and return void
//Menu functions:
void initialize_menu_functions();
void executeFunction(int, Land);