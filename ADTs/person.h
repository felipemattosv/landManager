#pragma once

#include <stdio.h>

typedef struct person * Person;

//Memory functions:
Person person_create();
void person_destroy(Person);

//Set functions:
void person_set(Person);

//Print functions:
void person_print(Person);
void person_fprint(Person, FILE *);